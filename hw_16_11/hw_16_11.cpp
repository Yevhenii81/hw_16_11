#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

struct AddProduct {
    string name;
    int count;
    float price;
    float discount;
};

struct Date {
    unsigned int day;
    unsigned int month;
    int year;
};

struct Place {
    string city;
    string region;
    string street;
    string house;
};

struct Time {
    unsigned short hour;
    unsigned short minute;
};

struct Structs
{
    string shop_name;
    Place place;
    Date date;
    Time time;
    AddProduct prod;
    string card_type;
    unsigned int check_num;
};

void SetCheck(Structs& check)
{
    check.shop_name = "Pivravod";

    cout << "Input city: ";
    cin >> check.place.city;

    cout << "Input region: ";
    cin >> check.place.region;

    cout << "Input street: ";
    cin >> check.place.street;

    cout << "Input number of house: ";
    cin >> check.place.house;

    cout << "Input actual number of day: ";
    cin >> check.date.day;
    if (check.date.day < 0 || check.date.day > 31)
    {
        cout << "Incorrect date value\n";
        throw "ERROR";
    }

    cout << "Input actual number of month: ";
    cin >> check.date.month;
    if (check.date.month < 0 || check.date.month > 12)
    {
        cout << "Incorrect date value\n";
        throw "ERROR";
    }

    cout << "Input actual year: ";
    cin >> check.date.year;

    cout << "Input actual hours: ";
    cin >> check.time.hour;

    cout << "Input actual minutes: ";
    cin >> check.time.minute;

    cout << "Input name of product: ";
    cin >> check.prod.name;

    cout << "Input amount of product: ";
    cin >> check.prod.count;
    if (check.prod.count < 0)
    {
        cout << "Incorrect date value\n";
        throw "ERROR";
    }

    cout << "Input price for one product: ";
    cin >> check.prod.price;
    if (check.prod.price < 0)
    {
        cout << "Incorrect date value\n";
        throw "ERROR";
    }

    cout << "Input discount for the product: ";
    cin >> check.prod.discount;
    if (check.prod.discount < 0)
    {
        cout << "Incorrect date value\n";
        throw "ERROR";
    }

    cout << "Input type of your card: ";
    cin >> check.card_type;

    check.check_num = rand() % 10000;
}

void PrintCheck(Structs& check)
{
    cout << "\n\tATB\n    " << check.shop_name << "\n\n";
    cout << check.place.city << ", " << check.place.region << " region\n" << check.place.street << ", " << check.place.house << "\n";
    printf("%02d.%02d.%04d      ", check.date.day, check.date.month, check.date.year);
    printf("%02d:%02d", check.time.hour, check.time.minute);
    cout << "   Check:  " << check.check_num;
    cout << "\n\t\t" << check.card_type << "\n";
    cout << check.prod.name << "\n" << check.prod.count << " * " << check.prod.price << " (discount: " << check.prod.discount << "%)....." << ((check.prod.price - check.prod.discount) / check.prod.price) * 100 << "\n";
    cout << "Total sum: " << (check.prod.count * (check.prod.price - check.prod.discount)) << "\n";

}

int main()
{
    srand(time(NULL));
    Structs check;
    SetCheck(check);
    PrintCheck(check);


    Sleep(INFINITE);
}

