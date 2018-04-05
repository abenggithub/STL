#include <map>
#include <typeinfo>
#include <string>
#include <iostream>

typedef std::map<std::string, std::string> form_map_t;
form_map_t cur_map;

int add (const char *key, const char *value)
{
    std::cout << __func__ << std::endl;
    form_map_t::iterator itr;

    std::pair<form_map_t::iterator, bool>test_pair;
    test_pair = cur_map.insert(std::make_pair<std::string, std::string>(key, value));

    if (false == test_pair.second) {
        std::cout << "first: " << test_pair.first->first << ", second: " << "false" << std::endl;
    }
    else {
        std::cout << test_pair.first->first << " : " << test_pair.first->second << std::endl;
    }

}

int add_translator(const char *src_str, char *dst_str) 
{
    
}

int main (int argc, char *argv[]) 
{
    std::string key[] = {"ssid", "password", "mode"};
    std::string value[] = {"JC-GROUP", "jcgroupsz!@#", "client"};

    // std::cout << key << " < " << b << " : "<< (key < b) << std::endl;
    char temp[64] = {0,};
    for (int i = 0; i < sizeof(key) / sizeof(key[0]); ++i) {
        if (0 != add_translator(key[i].c_str(), temp)) {
            key[i].find()
        }
    }

    std::cout << sizeof(key) / sizeof(key[0]) << std::endl;
    for (int i = 0; i < sizeof(key) / sizeof(key[0]); ++i) {
        add(key[i].c_str(), value[i].c_str());
    }

}