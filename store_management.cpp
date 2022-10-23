/*
Store Management System

[] import header
[] class: stock
[] attributes: name, purchase_item, quantity, password
[] methods: withdraw, refill,stockcheck, show, get quantity, addnew
[] functions: intro, refill, remove,
[] 3 different user role: Customer, employee, dealer
*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
using namespace std;

bool mm = true;
int count = 0;
string username[50];
string password[50];

class user
{

public:
    int menu()  // Login and Register
    {
        user obj;
        string pass;
        string pass2;
        string name;
        char ans;
        int repeat = 0;
        int upper = 0;
        int lower = 0;
        int specc = 0;
        int digit = 0;
        int r = 0;
        int n = 0;
        system("cls");
        cout << "Login Or Register" << endl;
        cout << "[1] Login" << endl;
        cout << "[2] Register" << endl;
        cout << "[3] Quit" << endl;
        cin >> ans;

        switch (ans)
        {
        case '1':

            do
            {
                cout << "Login" << endl;
                cout << "Please enter your username: ";
                cin.ignore();
                cin >> name;
                for (int i = 0; i < count; i++)
                {
                    if (name == username[i])
                    {
                        r++;
                        n = i;
                    }
                }
                if (r == 0)
                {
                    cout << "User doesn't exist" << endl;
                }
            } while (r == 0);
            do
            {
                cout << "Please enter your password:";
                cin >> pass;
                if (pass != password[n])
                {
                    cout << "Incorrect password" << endl;
                }
            } while (pass != password[n]);
            cout << "login.." << endl;
            Sleep(1000);
            cout << "Enter ENTER to proceed" << endl;
            cin.ignore();
            cin.get();
            system("cls");
            mm = true;
            break;

        case '2':
            cout << "Register" << endl;
            do
            {
                cout << "Please enter your username: ";
                cin.ignore();
                cin >> name;
                repeat = 0;
                for (int i = 0; i < count; i++)
                {
                    if (name == username[i])
                    {
                        repeat++;
                        cout << "This account had been created. Please try another username" << endl;
                    }
                }
            } while (repeat != 0);
            do
            {
                cout << "Please enter your password: ";
                cin.ignore();
                cin >> pass;
                if ((pass.size() < 8) || (pass.size() > 16))
                {
                    cout << "Please enter 8 to 16 characters of password" << endl;
                }
                else
                {

                    for (int i = 0; i < pass.size(); i++) // check for characters
                    {
                        if ((pass.at(i) == '_') || (pass.at(i) == '+') || (pass.at(i) == '*') || (pass.at(i) == '-') || (pass.at(i) == '!')) // special char
                        {
                            specc++;
                        }
                        if ((pass.at(i) >= 65) && (pass.at(i) <= 90)) // upper case
                        {
                            upper++;
                        }
                        if (pass.at(i) >= 97 && pass.at(i) <= 122) // lower case
                        {
                            lower++;
                        }
                        if (isdigit(pass.at(i))) // digit
                        {
                            digit++;
                        }
                    }
                    if (!((specc != 0) && (lower != 0) && (upper != 0) && (digit != 0)))
                    {
                        cout << "Make sure your password contains at least 1 Uppercase, Lowercase, Digit and Special Character" << endl;
                    }
                    do
                    {
                        cout << "Please enter your password again: ";
                        cin.ignore();
                        cin >> pass2;
                        if (pass != pass2)
                        {
                            cout << "Please enter your confirm password again" << endl;
                        }
                    } while (pass != pass2);
                    cout << "Account created" << endl;
                    username[count] = name;
                    password[count] = pass;
                    count++;
                    cout << "Enter ENTER to proceed" << endl;
                    cin.ignore();
                    cin.get();
                    system("cls");
                    mm = true;
                }
            } while ((pass.size() < 8) || (pass.size() > 16) && (!((specc != 0) && (lower != 0) && (upper != 0) && (digit != 0))));
            mm = true;
            break;
        case '3':

            cout << "QUIT" << endl;
            mm = false;
            break;

        default:
            break;
        }
        return 0;
    }
};

int main()
{
    user obj;
    while (mm == true)
    {
        obj.menu();
    }

    return 0;
}