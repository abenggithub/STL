#include <iostream>
#include <regex>

int main(int argc, char *argv[])
{
    std::string str= "ssid=JC-GROUP&password=jcgroup!@#";
    std::regex reg("[^&=]+");

    std::cout << "正则表达式为：[^&=]+" << std::endl;
    std::cout << "字符串为：" << str << std::endl;

    for (std::sregex_token_iterator it(str.begin(), str.end(), reg), end; it != end; ++it) {
        std::cout << "匹配到的字符串为：" << it->str() << std::endl;
    }
    std::cout << std::endl;

    for (std::sregex_token_iterator it(str.begin(), str.end(), reg, 2), end; it != end; ++it) {
        std::cout << "匹配到的字符串为：" << it->str() << std::endl;
    }
    std::cout << std::endl;

    for (std::sregex_token_iterator it(str.begin(), str.end(), reg, -1), end; it != end; ++it) {
        std::cout << "匹配到的字符串为：" << it->str() << std::endl;
    }

    std::cout << std::endl;

    return 0;
}