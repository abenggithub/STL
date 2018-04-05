#include <iostream>
#include <regex>

int main(int argc, char *argv[])
{
    std::string str= "ssid=JC-GROUP&password=jcgroup!@#";

    // std::string str= "ssid=&password=";
    std::smatch sm;

    std::cout << "正则表达式：[^&=]+" << std::endl;
    for (auto it = str.cbegin(); std::regex_search(it, str.cend(), sm, std::regex("password[^&=]+")); it = sm.suffix().first) {
        std::cout << &*it << "匹配成功 " << std::endl;
        std::cout << "匹配字符子串个数：" << sm.size() << std::endl;
        std::cout << "分别为：" << std::endl;
        for (auto aa:sm)
            std::cout << "\t" <<aa.str() << " : " << aa.str().length() << std::endl;
        std::cout << std::endl;

        std::cout << "字符串" << sm.str() << "前的字符串为：" << sm.prefix().str() << std::endl;
        std::cout << "字符串" << sm.str() << "后的字符串为：" << sm.suffix().str() << std::endl;
        std::cout << std::endl;
    }
    return 0;
}