#include <iostream>
#include <string>
#include <fstream>

char calcShape(char shape, char op)
{
    char ans = ' ';
    switch (op)
    {
    case '+':
        ans = int(shape) + 1;
        break;
    case '-':
        ans = int(shape) - 1;
        break;
    }
    if (ans > int('C'))
        ans = 'A';
    if (ans < int('A'))
        ans = 'C';
    return ans;
}

int calculatePoints(char enemy, char move)
{
    unsigned ans = 0;
    unsigned temp = 0;

    if (move == 'Y')
        temp = int(enemy);

    if (move == 'X')
        temp = calcShape(enemy, '-');

    if (move == 'Z')
        temp = calcShape(enemy, '+');

    ans = ((int(move) - 88) * 3) + (int(temp) - 64);
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