#include <fstream>
#include <iostream>
#include <string>

struct
{
    unsigned cal = 0;
    unsigned elf = 0;
} best;

int main()
{
    unsigned elf = 1;
    unsigned CurrCal = 0;
    std::ifstream file("dataset.txt");
    std::string str;
    while (std::getline(file, str))
    {
        if (str == "")
        {
            if (best.cal <= CurrCal)
            {
                best.cal = CurrCal;
                best.elf = elf;
            }
            CurrCal = 0;
            elf++;
        }
        else
            CurrCal += stoi(str);
    }
    std::cout << "A legtöbb vitt kalóra " << best.cal << " cal amit a(z) " << best.elf <<".-ik manó vitt.";
    return 0;
}