#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isOverlap(int a1, int a2, int b1, int b2)
{
    if ((a1 <= b1 && a2 >= b2) || (b1 <= a1 && b2 >= a2) || (a2 >= b1 && a2 <= b2) || (a1 <= b2 && b2 <= a2))
        return true;
    return false;
}

int main()
{
    std::ifstream file("dataset.txt");
    std::string str;
    int ans, i = 0;
    int dataset[4] = {0};
    ans = 0;
    while (file >> str)
    {
        dataset[i] = stoi(str);
        i++;
        if (i > 3)
        {
            ans += isOverlap(dataset[0], dataset[1], dataset[2], dataset[3]);
            i = 0;
        }
    }
    cout << ans;
}
