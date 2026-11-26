#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

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

int main() {
    std::vector<Setting> settings = {
        {"key1", "value1"},
        {"key2", "value2"},
        {"key3", "value3"}
    };

    std::unordered_map<std::string, std::string> settingsMap = indexSettings(settings);

    for (const std::pair<const std::string, std::string>& pair : settingsMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << '\n';
    }

};