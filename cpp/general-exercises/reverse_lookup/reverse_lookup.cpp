#include <optional>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

struct Setting {
    std::string key;
    std::string value;
};

std::optional<std::string> findSetting(const std::vector<Setting>& settings, std::string_view key){

    std::vector<Setting>::const_reverse_iterator reverseBegin = settings.rbegin();
    
    std::vector<Setting>::const_reverse_iterator reverseEnd = settings.rend();

    auto found = std::find_if(reverseBegin, reverseEnd,
        [key](const Setting& setting){
            return setting.key == key;
        }
    );

    if(found == reverseEnd){
        return std::nullopt;
    }

    return std::make_optional(found->value);
};

int main() {
    std::vector<Setting> settings = {
        {"key1", "value1"},
        {"key2", "value2"},
        {"key1", "value3"}
    };

    std::optional<std::string> value = findSetting(settings, "key1");

    if (value) {
        std::cout << "Value for 'key1': " << *value;
    }
};