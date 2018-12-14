#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> map;
    map["I"] = 1;
    std::cout << map["I"] << std::endl;
    
    return 0;
};