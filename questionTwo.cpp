#include <iostream>

bool isLeapYear(int year)
{
    if (year % 4 != 0)
        return false;
    else if (year % 100 == 0 && year % 400 != 0)
        return false;

    return true;
}

void firstSunday()
{
    int daysInAMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int currentDay = 1;
    for (int years = 1900; years < 2001; years++)
    {
        for (int months = 0; months < 12; months++)
        {
            if (currentDay % 7 == 0)
                std::cout << 1 << "." << months + 1 << "." << years << " is Sunday" << std::endl;
            if (isLeapYear(years))
            {
                if (months == 1)
                    currentDay += 29;
                else
                    currentDay += daysInAMonth[months];           
            }
            else
                currentDay += daysInAMonth[months];
        }
    }
}

int main()
{
    firstSunday();
}
