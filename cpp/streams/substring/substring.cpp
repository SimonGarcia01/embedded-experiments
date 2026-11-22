#include <optional>
#include <iostream>
#include <string>

std::optional<std::string> valueAfterEquals(const std::string& text){

    size_t pos = text.find('=');

    if(pos == std::string::npos){
        return std::nullopt;
    }

    return text.substr(pos + 1);
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
};