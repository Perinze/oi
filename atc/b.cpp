#include <iostream>
#include <string>

char map['9' + 1];

int main()
{
    map['0'] = '0';
    map['1'] = '1';
    map['6'] = '9';
    map['8'] = '8';
    map['9'] = '6';
    std::string s;
    std::cin >> s;
    for (int i = 0; i < s.size(); i++)
        s[i] = map[s[i]];
    for (int i = s.size() - 1; i >= 0; i--)
        std::cout << s[i];
    std::cout << std::endl;
    return 0;
}