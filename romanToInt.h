#include <string>
#include <iostream>

using namespace std;

int romanToInt(string s)
{
    int retInt = 0;

    char rom[7] = { 'I','V','X','L','C','D','M' };
    int types[7] = { 1, 5, 10, 50, 100, 500, 1000 };

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'I' && s[i + 1] == 'V')
        {
            retInt += 4;
            i += 1;
        }
        else if (s[i] == 'I' && s[i + 1] == 'X')
        {
            retInt += 9;
            i += 1;
        }
        else if (s[i] == 'X' && s[i + 1] == 'L')
        {
            retInt += 40;
            i += 1;
        }
        else if (s[i] == 'X' && s[i + 1] == 'C')
        {
            retInt += 90;
            i += 1;
        }
        else if (s[i] == 'C' && s[i + 1] == 'D')
        {
            retInt += 400;
            i += 1;
        }
        else if (s[i] == 'C' && s[i + 1] == 'M')
        {
            retInt += 900;
            i += 1;
        }

        else
            for (int j = 0; j < 7; j++)
            {
                if (s[i] == rom[j])
                {
                    retInt += types[j];
                }

            }
    }

    return retInt;
}
