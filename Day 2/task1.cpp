#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>

int calculatePoints(char enemy, char move)
{
    unsigned ans = 0;
    ans = int(move) - 87;
    if (int(enemy) == (int(move) - 23))
        ans += 3;
    if ((enemy == 'C' && move == 'X') || (enemy == 'A' && move == 'Y') || (enemy == 'B' && move == 'Z'))
        ans += 6;
    return ans;
}

int main()
{
    std::ifstream file("dataset.txt");
    std::string str;
    int ans = 0;
    while (std::getline(file, str))
    {
        ans += calculatePoints(str[0], str[2]);
    }
    std::cout << ans;
    return 0;
}
