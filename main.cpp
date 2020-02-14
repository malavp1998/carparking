#include<iostream>
#include<conio.h>
#include<string.h>
#include<string>
#include<process.h>
#include<stdio.h>
#include<fstream>
#include<iomanip>
int login();
using namespace std;
int d=0;
class car {
public:
    int vno;
    float count;
    char  dname[15], x, l[50];
    void input()
    {
        system("CLS");
        cout << "\n\n\t\tEnter the name of driver : ";
        cin >> dname;
        cout << "\n\n\t\tEnter the car no : ";
        cin >> vno;
        cout << "\n\n\t\tEnter the no of hours of stay : ";
        cin >> count;
        if (d <= 3&& count < 8)
        {
            cout << "\n\n\t\tParking Available! You can park your car. ";       
            cout << "\n\n\t\tCar got parked!!";

        }
        else
        {
            cout << "\n\n\t\t Parking not possible!!";
        }


    }
    void output()
    {

        cout << setw(15) << left << this->dname << setw(10) << left << this->vno << setw(10) << left << this->count << endl;
    }
    void   chargeoutput()
    {


        cout << "\n\t\n\tAre you a V.I.P: y/n ";
        cin >> x;
        if (x == 'y')
        {
            system("CLS");
            cout << "\n\t\n\tThe total expense during parking  ";
            cout << count * 20 << " rupees"<<endl;
        }
        else
        {
            system("CLS");
            cout << "\n\t\n\tThe total expenses during parking  ";
            cout << count * 25 << " rupees"<<endl;

        }
    }
}a;
int main()
{
     if (!login()) { return 0; }
    cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
    int choice = 0, vno1 = 0, d = 0;
    while (1) {
        system("pause");
        system("CLS");

        cout << "\n\n\t\t ====== CAR PARKING RESERVATION SYSTEM ======";
        cout << "\n\n                                          ";
        cout << " \n\t\t\t======================";
        cout << "\n\n\t\t\t  1. Arrival of a Car";
        cout << "\n\n\t\t\t  2. Total no of cars Arrived";
        cout << "\n\n\t\t\t  3. Total parking charges of all cars with details";
        cout << "\n\n\t\t\t  4. Departure of the car";
        cout << "\n\n\t\t\t  5. Exit Program";
        cout << " \n\t\t\t======================";
        cout << "\n\n";
        cout << "\t\t\t Select Your Choice ::";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            d++;
            a.input();
            ofstream out{ "../text.txt",ios::app };
            out << setw(15) << left << a.dname << setw(10) << left << a.vno << setw(10) << left << a.count << endl
            out.close();
        }
        break;
        case 2:
        {
            cout << "in two" << endl;
            ifstream in{ "../text.txt" };
            if (in.is_open())
            {
                cout << "opened" << endl;
            }

            in >> a.dname >> a.vno >> a.count;
            cout << setw(20) << left << "Driver Name " << setw(10) << left << "Car No" << setw(10) << left << "Hours Of Stay" << endl;
            while (!in.eof())
            {

                cout << setw(20) << left << a.dname << setw(10) << left << a.vno << setw(10) << left << a.count << endl;

                in >> a.dname >> a.vno >> a.count;

            }

            in.close();
        }
        system("pause");
        break;
        case 4:
        {
            int n;
            system("CLS");
            cout << "\n\n\t\tEnter the car no you want to get depart : ";
            cin >> n;

            ifstream inFile;
            inFile.open("../text.txt");

            ofstream outFile;
            outFile.open("../text2.txt");

            inFile >> a.dname >> a.vno >> a.count;
            while (!inFile.eof())
            {


                if (a.vno != n)
                {

                    outFile << setw(15) << left << a.dname << setw(10) << left << a.vno << setw(10) << left << a.count << endl;
                }
                else{
                    d--;
                }
                inFile >> a.dname >> a.vno >> a.count;
            }
            cout << "\n\n\t\t Parking Record Deleted";

            inFile.close();
            outFile.close();

            remove("../text.txt");
            rename("../text2.txt", "../text.txt");
        }

        break;
        case 3:
        {
            int n,i=0;
            cout << "\t\t\n\n write your car no" << endl;
            cin >> n;
            ifstream in;
            in.open("../text.txt");
            in >> a.dname >> a.vno >> a.count;
            while (!in.eof())
            {
                if (a.vno == n)
                {
                    
                    a.chargeoutput();
                    
 
                }
                in >> a.dname >> a.vno >> a.count;
            }
            


        }
        break;
        case 5:
        {
            return 0;
        }
        break;
        default:
        {
            cout << "enter correct number" << endl;
            system("pause");
        }



        }
    }
}
int login()
{
    cout << "\n\n\n\t\t\t\t\t\t parking reservation system login" << endl;
    string pass{ "" };
    cout << "write your login pass" << endl;
    char c;
    c = _getch();
    while (c != 13)
    {
        pass += c;
        cout << "*";
        c = _getch();
    }
    cout << endl;
    if (pass == "pass")
    {
        cout << "login successfully" << endl;
        system("pause");
        system("CLS");
        return 1;
    }
    else
    {
        cout << "failed to login" << endl;
        system("pause");
        system("CLS");
        return login();
    }

}