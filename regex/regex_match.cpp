#include <iostream>
#include <regex>

int main (int argc, char *argv[])
{
    std::string str = "sigalhu233";
    std::regex r("([a-z0-9])+");
    
    std::cout << "正则表达式：[a-z0-9]+" << std::endl;

    if (std::regex_match(str, r)) {
        std::cout << "字符串：" << str << "   匹配成功！" << std::endl;
    }

    std::cout << "正则表达式：\\d+" << std::endl;
    if (std::regex_match(str, std::regex("\\d+"))) {
        std::cout << str << "   匹配成功！" << std::endl;
    }
    else {
        std::cout << str << "    匹配失败！" << std::endl;
    }

    std::cout << "正则表达式： \\d+" << std::endl;
    if (std::regex_match(str.begin() + 7, str.end(), std::regex("\\d+"))) {
        std::cout << &str[7] << " 匹配成功！" << std::endl;
    }
    else {
        std::cout << &str[7] << "  匹配失败！" << std::endl;
    }
    
    std::smatch sm;
    std::cout << "正则表达式：（[a-z]+)(\\d+)" << std::endl;
    if (std::regex_match(str.cbegin() + 5, str.cend(), sm, std::regex("([a-z]+)(\\d+)"))) {
        std::cout << &str[5] << " 匹配成功！" << std::endl;
        std::cout << "匹配的字符串个数：" << sm.size() << std::endl;
        std::cout << "分别是：";
        for (auto aa:sm)
            std::cout << aa.str() << " ";
        std::cout << std::endl;
    }
    else {
        std::cout << &str[5] << "匹配失败！" << std::endl;
    }

    std::cmatch cm;
    std::cout << "正则表达式：([a-z]+)(\\d+)" << std::endl;
    if (std::regex_match(str.c_str(), cm, std::regex("([a-z]+)(\\d+)"))) {
        std::cout << str << " 匹配成功！" << std::endl;
        std::cout << "匹配字符串个数：" << cm.size() << std::endl;
        std::cout << "分别是：";
        for (auto aa:cm)
            std::cout << aa.str() << " ";
        std::cout << std::endl;
    }
    else {
        std::cout << str << " 匹配失败！" << std::endl;
    }
    return 0;
}