#include <optional>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <sstream>

std::string_view trimSpaces(std::string_view text) {
    const auto first = text.find_first_not_of(' ');

    if (first == std::string_view::npos) {
        return {};
    }

    const auto last = text.find_last_not_of(' ');
    return text.substr(first, last - first + 1);
}

std::optional<std::string> valueAfterEquals(const std::string& text){

    size_t pos = text.find('=');

    if(pos == std::string::npos){
        return std::nullopt;
    }

    //We have to make a copy of the string_view because after trimSpaces returns,
    //the string_view will point to a temporary object that will be destroyed = dangling reference
    //after trimSpaces returns, the string_view caller is still alive, but the local string_view inside trimSpaces is destroyed
    std::string_view textView{text};
    //Trimmed is valid because textView is still alive and the trimmed string_view points to a valid range inside textView
    std::string_view trimmed = trimSpaces(textView.substr(pos + 1));

    //Finally we return a copy of the trimmed string_view as an actual string
    return std::string{trimmed};
};

//Now we are going to parse both the key and the value from a string in the format "key=value"
struct Setting {
    std::string key;
    std::string value;
};

std::optional<Setting> parseSetting(std::string_view line){
    size_t pos = line.find('=');

    if(pos == std::string_view::npos){
        return std::nullopt;
    }

    std::string_view keyView = trimSpaces(line.substr(0, pos));

    if(keyView.empty()){
        return std::nullopt;
    }

    std::string_view valueView = trimSpaces(line.substr(pos + 1));

    return Setting{std::string{keyView}, std::string{valueView}};
};

std::vector<Setting> readSettings(std::istream& input){
    std::vector<Setting> settings;
    std::string line;

    while(std::getline(input, line)){
        if(auto setting = parseSetting(line)){
            settings.push_back(*setting);
        }
    }

    return settings;
};

int main() {
    std::string text = "key=value";
    std::optional<std::string> value = valueAfterEquals(text);
    if (value) {
        std::cout << "Value after '=': " << *value << std::endl;
    } else {
        std::cout << "No '=' found in the string." << std::endl;
    }

    std::string text2 = "keyvalue";
    std::optional<std::string> value2 = valueAfterEquals(text2);
    if (value2) {
        std::cout << "Value after '=': " << *value2 << std::endl;
    } else {
        std::cout << "No '=' found in the string." << std::endl;
    }

    std::string text3 = "key=";
    std::optional<std::string> value3 = valueAfterEquals(text3);
    if (value3) {
        std::cout << "Value after '=': " << *value3 << std::endl;
    } else {
        std::cout << "No '=' found in the string." << std::endl;
    }

    std::string text4 = "key = value";
    std::optional<Setting> setting = parseSetting(text4);
    if (setting) {
        std::cout << "Key: " << setting->key << ", Value: " << setting->value << std::endl;
    } else {
        std::cout << "Invalid setting format." << std::endl;
    }

    std::istringstream input{"key1=value1\nkey2=value2\ninvalid_line\nkey3=value3"};

    std::vector<Setting> settings = readSettings(input);

    for (const auto& s : settings) {
        std::cout << "Key: " << s.key << ", Value: "<< s.value << std::endl;
    };
};