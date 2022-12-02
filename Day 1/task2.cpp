#include <fstream>
#include <iostream>
#include <string>

struct
{
    unsigned cal[3] = {0};
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
            if (best.cal[0] < CurrCal)
            {
                best.cal[2] = best.cal[1];
                best.cal[1] = best.cal[0];
                best.cal[0] = CurrCal;
            }
            else if (best.cal[1] < CurrCal)
            {
                best.cal[2] = best.cal[1];
                best.cal[1] = CurrCal;
            }
            else if (best.cal[2] < CurrCal)
                best.cal[2] = CurrCal;

            CurrCal = 0;
            elf++;
        }
        else
            CurrCal += stoi(str);
    }
    std::cout << best.cal[0] << " " << best.cal[1] << " " << best.cal[2] << "\n";
    std::cout << best.cal[0] + best.cal[1] + best.cal[2];
    return 0;
}