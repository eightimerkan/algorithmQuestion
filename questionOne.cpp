#include <iostream>

void writeInTurkish(double number)
{
    std::string decimal[] = {"sifir", "bir", "iki", "uc", "dort", "bes", "alti", "yedi", "sekiz", "dokuz"};
    std::string tens[] = {"", "on", "yirmi", "otuz", "kirk", "elli", "altmis", "yetmis", "seksen", "doksan"};

    long partInt = static_cast<long>(number);
    int decimalPlace = static_cast<int>((number - partInt) * 100);

    std::string partIntTurkish = "";
    if (partInt < 0)
    {
        partIntTurkish += "eksi ";
        partInt = -partInt;
        decimalPlace = -decimalPlace;
    }

    if(decimalPlace != 0)
        decimalPlace += 1;

    if (partInt == 0)
        partIntTurkish += decimal[0];
    else 
    {
        if (partInt >= 1000)
        {
            int thousands = partInt / 1000;
            partIntTurkish += decimal[thousands] + " bin ";
            partInt %= 1000;
        }
        if (partInt >= 100)
        {
            int hundreds = partInt / 100;
            partIntTurkish += decimal[hundreds] + " yuz ";
            partInt %= 100;
        }

        if (partInt >= 10)
        {
            int tensPlaces = partInt / 10;
            partIntTurkish += tens[tensPlaces];
            int decimalPlace = partInt % 10;
            if (decimalPlace > 0)
                partIntTurkish += decimal[decimalPlace];
        }
        else
            partIntTurkish += decimal[partInt];
    }

    std::string decimalPlaceTurkish = "";
    if (decimalPlace > 0)
    {
        int tensPlaces = decimalPlace / 10;
        int decimalPlaceDigit = decimalPlace % 10;

        decimalPlaceTurkish += tens[tensPlaces];
        if (decimalPlaceDigit > 0)
            decimalPlaceTurkish += decimal[decimalPlaceDigit];
    }

    std::cout << partIntTurkish;
    if (!decimalPlaceTurkish.empty())
        std::cout << "virgul" << decimalPlaceTurkish;
}

int main()
{
    double number;
    std::cout << "Sayiyi giriniz: ";
    std::cin >> number;

    writeInTurkish(number);

    return 0;
}
