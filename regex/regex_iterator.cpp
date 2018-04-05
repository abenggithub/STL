#include <iostream>
#include <regex>

int main() {
    std::string str = "ssid=JC-GROUP&password=jcgroup!@#";
    std::regex reg("[^&=]+");
    
    std::cout << "正则表达式：[^&=]+" << std::endl;
    for (std::sregex_iterator it(str.begin(), str.end(), reg), end; it != end; ++it) {
        std::cout << "字符串：" << &*it->prefix().first << " 匹配成功！" << std::endl;
        std::cout << "匹配字符子串个数：" << it->size() << std::endl;
        std::cout << "分别为：";
        for(auto aa:*it)
            std::cout << aa.str() << "";
        std::cout << std::endl;

        std::cout << "字符串 " << it->str() << " 前的字符为：" << it->prefix().str() << std::endl;
        std::cout << "字符串 " << it->str() << " 后的字符为：" << it->suffix().str() << std::endl;
        std::cout << std::endl;
    }
}