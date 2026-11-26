#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <optional>

struct Setting {
    std::string key;
    std::string value;
};

std::unordered_map<std::string, std::string> indexSettings(const std::vector<Setting>& settings){
    std::unordered_map<std::string, std::string> settingsMap;

    for(const Setting& setting : settings){
        settingsMap.insert_or_assign(setting.key, setting.value);
    }

    return settingsMap;
};

std::optional<std::string> findSetting(const std::unordered_map<std::string, std::string>& settings, const std::string& key){

    std::unordered_map<std::string, std::string>::const_iterator found = settings.find(key);

    if(found == settings.end()){
        return std::nullopt;
    }
    //The most explicit way to return an optional with an owning value: return std::optional<std::string>(std::string(found->second));
    //However, the following is a shorter implicit version that does the same thing
    //found->second returns a string reference, but because the return type is std::optional<std::string>, the compiler will create a new string object from the reference and return it as an optional.
    return found->second;
};

int main() {
    std::vector<Setting> settings = {
        {"key1", "value1"},
        {"key2", "value2"},
        {"key3", "value3"}
    };

    std::unordered_map<std::string, std::string> settingsMap = indexSettings(settings);

    //This loop can be written shorter using structured bindings
    //for (const auto& [key, value] : settingsMap) {}
    //this gives us access to the key and value directly without having to use pair.first and pair.second
    for (const std::pair<const std::string, std::string>& pair : settingsMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << '\n';
    }

};