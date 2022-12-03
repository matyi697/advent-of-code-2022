#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

int calcPriority(char letter)
{
    if (int(letter) >= 97)
        return int(letter) - 96;
    else
        return int(letter) - 38;
}

char overlap(string str)
{
    string p1 = " ";
    string p2 = " ";

    for (int i = 0; i < str.size() / 2; i++)
        p1 += str[i];

    for (int i = str.size() / 2; i < str.size(); i++)
        p2 += str[i];

    for (int i = 1; i <= str.size() / 2; i++)
    {
        if (p2.find(p1[i]) != string::npos)
            return p1[i];
    }
}

int main()
{
    std::ifstream file("dataset.txt");
    std::string str;
    int ans = 0;
    while (std::getline(file, str))
    {
        ans += calcPriority(overlap(str));
    }
    std::cout << ans;
    return 0;
}
