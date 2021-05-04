#include <iostream>
#include <exception>
#include <fstream>
#include <iomanip>
#include <istream>
#include <string>
#include <windows.h>
using namespace std;

//****************************************************************
//                   LOGIN FUNCTION
//****************************************************************
void login();
void registr();
void forgot();
int main();

//Global Variables
string validation = "fail";

void loginpanel()
{
    system("cls");
    int choice;
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
    cout << "!!!                VITx UNIVERSITY STAFF RECORD              !!! " << endl;
    cout << "!!!                        ~LOGIN MENU~                      !!! " << endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
    cout << "\n1.LOGIN" << endl;
    cout << "2.REGISTER" << endl;
    cout << "3.FORGOT PASSWORD/USERNAME" << endl;
    cout << "4.EXIT" << endl;
    cout << "\nEnter your choice :";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        break;
    case 3:
        forgot();
        break;
    case 4:

        cout << "Thanks for using this program\n\n\n";
        break;
    default:
        system("cls");
        cout << "You've made a mistake , give it a try again\n"
             << endl;
        main();
    }
}

void login()
{
    int count;
    string user, pass, u, p;
    system("cls");
    cout << "Please enter the following details" << endl;
    cout << "\nUSERNAME :";
    cin >> user;
    cout << "PASSWORD :";
    cin >> pass;

    ifstream input("database.txt");
    while (input >> u >> p)
    {
        if (u == user && p == pass)

        {
            count = 1;

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cout << "LOGIN SUCCESSFUL";
            cin.get();
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
    }
    input.close();
    if (count == 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "Welcome  " << user;

        cout << " \n\nWe're glad that you're here";
        cout << "\n\nThis is a new database, So in order to continue the program. \nPlease proceed further to create a database of students!";
        cout << "\n\n[PRESS ANY KEY TO CONTINUE]";
        validation = "pass";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        cin.get();
        main();
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 71);
        cout << "\nLOGIN ERROR!\nPlease check your username and password\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cin.get();
        cin.get();
        system("cls");
        loginpanel();
    }
}

void registr()
{

    string reguser, regpass, ru, rp;
    system("cls");
    cout << "Enter the username :";
    cin >> reguser;
    cout << "\nEnter the password :";
    cin >> regpass;

    ofstream reg("database.txt", ios::app);
    reg << reguser << ' ' << regpass << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << "\nRegistration Sucessful\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    system("cls");
    loginpanel();
}

void forgot()
{
    int ch;
    system("cls");
    cout << "Forgotten ? We're here for help\n";
    cout << "1.Search your id by username" << endl;
    cout << "2.Search your id by password" << endl;
    cout << "3.Main menu" << endl;
    cout << "Enter your choice :";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        int count = 0;
        string searchuser, su, sp;
        cout << "\nEnter your remembered username :";
        cin >> searchuser;

        ifstream searchu("database.txt");
        while (searchu >> su >> sp)
        {
            if (su == searchuser)
            {
                count = 1;
            }
        }
        searchu.close();
        if (count == 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cout << "\n\nHurray, account found\n";
            cout << "\nYour password is " << sp;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cin.get();
            cin.get();
            system("cls");
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 71);
            cout << "\nSorry, Your userID is not found in our database\n";
            cout << "\nPlease kindly contact your system administrator for more details \n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cin.get();
            cin.get();
            main();
        }
        break;
    }
    case 2:
    {
        int count = 0;
        string searchpass, su2, sp2;
        cout << "\nEnter the remembered password :";
        cin >> searchpass;

        ifstream searchp("database.txt");
        while (searchp >> su2 >> sp2)
        {
            if (sp2 == searchpass)
            {
                count = 1;
            }
        }
        searchp.close();
        if (count == 1)
        {
            cout << "\nYour password is found in the database \n";
            cout << "\nYour Id is : " << su2;
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 71);
            cout << "Sorry, We cannot found your password in our database \n";
            cout << "\nKindly contact your administrator for more information\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cin.get();
            cin.get();
            main();
        }

        break;
    }

    case 3:
    {
        cin.get();
        main();
    }
    default:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 71);
        cout << "Sorry, You entered wrong choice. Kindly try again" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        forgot();
    }
}

class MyException : public exception
{
public:
    const char *noprojectdone() const throw()
    {
        return "The Employee has not completed any Project.\nHence, The Employee's salary cannot be raised.";
    }
};

class Employee
{
private:
    int ID, experience, proj_completed, total_proj, rating, current_sal;
    string empName;
    double appraisalScore;
    friend void display_tabular(Employee e1);
    friend Employee operator>(Employee e1, Employee e2);

public:
    Employee(){};

    Employee(int ID, string empName, int proj_completed, int total_proj, int current_sal, int experience, int rating)
    {
        this->ID = ID;
        this->empName = empName;
        this->proj_completed = proj_completed;
        this->total_proj = total_proj;
        this->current_sal = current_sal;
        this->experience = experience;
        this->rating = rating;
    }
    ~Employee(){};

    virtual void type() { cout << "This is virtual function in base class\n"; }

    void appraiseEmployee(string empName, int proj_completed, int total_proj)
    {
        try
        {
            if (proj_completed == 0)
            {
                MyException e;
                throw e;
            }
        }
        catch (MyException e)
        {
            cout << e.noprojectdone();
        }
        double appraisalScore = (proj_completed * 100) / total_proj;
        cout << "\nThe new employee name: " << empName << endl;
        cout << "The appraisal score for current month is: " << appraisalScore << endl;
    }
};

class HRDepartment : public Employee
{
public:
    void type() { cout << "The resolving of function call is done at Run-time\n"; }

    void Check()
    {
        cout << "...Now checking the record of HRDepartment...\n";
    }
};

Employee operator>(Employee e1, Employee e2)
{
    if (e1.current_sal > e2.current_sal)
    {
        cout << e1.empName << " has better performance this year" << endl;
    }
    else
    {
        cout << e2.empName << " has better performance this year" << endl;
    }
}

template <class T>
T ComparePerformance(T c1, T c2)
{
    T greator = (c1 > c2) ? c1 : c2;
    return greator;
}

void display_tabular(Employee e1)
{
    cout << endl
         << e1.ID << "\t" << e1.empName << "\t \t" << e1.proj_completed << "  \t\t" << e1.total_proj << "\t\t " << e1.current_sal << "\t " << e1.experience << "\t \t" << e1.rating << endl;
}

int main()
{
    while (validation == "fail")
        loginpanel();

    system("cls");

    int N;
    int ID, experience, proj_completed, total_proj, rating, current_sal;
    string empName;
    double appraisalScore;

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
    cout << "!!!           WELCOME TO EMPLOYEE MANAGEMENT SYSTEM          !!! " << endl;
    cout << "!!!                     ~REGISTRATION MENU~                  !!! " << endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;

    cout << endl
         << endl
         << "Enter the number of Employees : ";
    cin >> N;
    cout << endl
         << endl;

    Employee *emp = new Employee[N];
    for (int i = 0; i < N; i++)
    {
        cout << "Enter the name of " << i + 1 << " Employee: ";
        cin >> empName;
        cout << "Enter the ID of " << i + 1 << " Employee: ";
        cin >> ID;
        cout << "Enter the number of projects completed by " << i + 1 << " Employee: ";
        cin >> proj_completed;
        cout << "Enter the total number of projects given to " << i + 1 << " Employee: ";
        cin >> total_proj;
        cout << "Enter the current salary of " << i + 1 << " Employee: ";
        cin >> current_sal;
        cout << "Enter the experience of " << i + 1 << " Employee: ";
        cin >> experience;
        cout << "Enter the rating of " << i + 1 << " Employee out of 10: ";
        cin >> rating;
        cout << endl;
        emp[i] = Employee(ID, empName, proj_completed, total_proj, current_sal, experience, rating);
    };
    system("cls");
    cout << "============================================================================================\n";
    cout << "                                      OVERALL DATABASE                                      \n";
    cout << "============================================================================================\n";
    cout << "ID"
         << "\t"
         << "NAME"
         << "\t"
         << "PROJECT COMPLETED"
         << "\t"
         << "TOTAL PROJECT"
         << "\t"
         << "SALARY"
         << "\t"
         << "EXPERIENCE"
         << "\t"
         << "RATING";
    cout << "\n============================================================================================\n";
    for (int j = 0; j < N; j++)
    {
        display_tabular(emp[j]);
    }
    cin.get();
    cin.get();

    // cout << "\n==========================================================\n";
    // cout << "                      COMPARING SALARY                     \n";
    // cout << "==========================================================\n";

    // emp[1] > emp[2];

    cout << "\n==========================================================\n";
    cout << "                 VALIDATING FOR EXCEPTIONS                \n";
    cout << "==========================================================\n";

    Employee E = Employee();
    E.appraiseEmployee("Manoj", 12, 15);
    cin.get();
    cin.get();
    system("cls");
    cout << "==========================================================\n";
    cout << "                  COMPARING ACHIEVEMENTS                  \n";
    cout << "==========================================================\n";

    int i1, i2;
    float f1, f2;

    cout << "\nEnter current year credits of company out of 100 points in integers respectively: ";
    cin >> i1;
    cout << "\nEnter previous year credits of company out of 100 points in integers respectively: ";
    cin >> i2;
    cout << ComparePerformance(i1, i2) << " is greater" << endl;
    i1 > i2;
    cout << "\nEnter current year performance stats of company out of 100 in float respectively: ";
    cin >> f1;
    cout << "\nEnter previous year performance stats of company out of 100 in float respectively: ";
    cin >> f2;
    cout << ComparePerformance(f1, f2) << " is greater" << endl;
    f1 > f2;
    cin.get();
    cin.get();
    system("cls");
    cout << "\n==========================================================\n";
    cout << "                 VALIDATING FOR EXCEPTIONS                \n";
    cout << "==========================================================\n";
    HRDepartment H = HRDepartment();
    H.Check();
    H.appraiseEmployee("Rohan", 14, 16);

    cin.get();
    cin.get();
    system("cls");

    cout << "THANKYOU FOR USING OUR PROGRAM [GROUP 10]";
    cout << "\nTEAM MEMBERS: \n";
    cout << "\nARYAN KASHYAP   [20BAI10072]";
    cout << "\nSHISHIR SHARMA  [20BCE11007]";
    cout << "\nZOYA QADRI      [20BCG10111]";
	exit(0);
    cin.get();

    return 0;
}
