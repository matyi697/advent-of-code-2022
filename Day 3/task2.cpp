#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int calcPriority(char letter)
{
    if (int(letter) >= 97)
        return int(letter) - 96;
    else
        return int(letter) - 38;
}

char commonBadge(std::string str1, std::string str2, std::string str3)
{
    string badges = "";
    unsigned sizemax = str1.size() + str2.size() + str3.size();
    for (int i = 0; i <= sizemax; i++)
    {
        if (str1.find(str2[i]) != string::npos)
            badges += str2[i];
    }
    for (int i = 0; i <= sizemax; i++)
    {
        if (str3.find(badges[i]) != string::npos)
            return badges[i];
    }
}

int main()
{
    string dataset[3] = {""};
    unsigned line = 0;
    std::ifstream file("dataset.txt");
    std::string str;
    int ans = 0;
    while (std::getline(file, str))
    {
        dataset[line] = str;
        line++;
        if (line > 2)
        {
            ans += calcPriority(commonBadge(dataset[0], dataset[1], dataset[2]));
            line = 0;
        }
    }
    std::cout << ans;
    return 0;
}