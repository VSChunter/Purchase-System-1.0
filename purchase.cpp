#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;

char ans;
bool mm = true;
int cost = 0;

class stock
{
public:
    string meat[50] = { // item:
        "[1]Chicken (1kg)",
        "[2]Egg     (1 dozen)",
        "[3]Lamb    (1kg)",
        "[4]Beef    (1kg)"};

    int cmeat[50] = {20, 9, 80, 100};

    string fruit[50] = {
        "[1]Apple   (1 pack)",
        "[2]Orange  (1 pack)"};

    int cfruit[50] = {12, 12};

    string veg[50] = {
        "[1]Kale    (0.1kg)",
        "[2]Onion   (0.1kg)"};

    int cveg[50] = {5, 6};

    int menu()
    {
        system("cls");
        cout << "Items Category:" << endl;
        cout << "[1] Meats" << endl;
        cout << "[2] Fruits" << endl;
        cout << "[3] Vegetables" << endl;
        cout << "[4] Payment" << endl;
        cin >> ans;
        mm = true;
        return 0;
    }

    int ques()
    {
        int choose;
        cin >> choose;
        cout << "How many unit do you want: ";
        float unit;
        cin >> unit;
        cost += unit * (cmeat[choose - 1]);
        cout << "The overall cost is now: RM " << cost << endl;
        cout << "Enter ENTER to proceed" << endl;
        cin.ignore();
        cin.get();
        system("cls");
        return 0;
    }

    int purchase()
    {
        switch (ans)
        {
        case '1':
            system("cls");

            cout << "MEATS CATEGORY" << endl // show items
                 << endl;
            cout << "Item:"
                 << "\t\t\t"
                 << "Price(RM):" << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << meat[i] << "\t\t";
                cout << cmeat[i] << endl;
            }

            ques();

            break;

        case '2':
            system("cls");

            cout << "FRUITS CATEGORY" << endl // show items
                 << endl;
            cout << "Item:"
                 << "\t\t\t"
                 << "Price(RM):" << endl;
            for (int i = 0; i < 2; i++)
            {
                cout << fruit[i] << "\t\t";
                cout << cfruit[i] << endl;
            }

            ques();
            
            break;

        case '3':
            system("cls");

            cout << "VEGE CATEGORY" << endl // show items
                 << endl;
            cout << "Item:"
                 << "\t\t\t"
                 << "Price(RM):" << endl;
            for (int i = 0; i < 2; i++)
            {
                cout << veg[i] << "\t\t";
                cout << cveg[i] << endl;
            }

            ques();
            
            break;

        case '4':
            payment();
            break;

        default:
            cout << "We dont have this selection." << endl;
            break;
        }
        mm = true;
        Sleep(1000);
        return 0;
    }

    int payment()
    {
        int balance;
        int pay;

        cout << "You have to pay: RM " << cost << endl;
        cout << "Payment: RM";
        cin >> pay;
        if (pay - cost < 0)
        {
            cout << "You need RM " << abs(pay - cost) << " more." << endl;
            payment();
        }
        else
        {
            cout << "Your balance is RM " << pay - cost << endl;
            cout << "Have a nice day!" << endl;
        }
        mm = false;
        Sleep(1000);
        return 0;
    }
};

int main()
{
    stock obj;
    while (mm == true)
    {
        ans = 0;
        obj.menu();
        obj.purchase();
    }
    return 0;
}