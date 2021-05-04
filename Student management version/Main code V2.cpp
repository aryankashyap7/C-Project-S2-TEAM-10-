//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include <iostream>
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
    cout << "!!!                 VITx ADMINISTRATIVE PORTAL               !!! " << endl;
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

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class student
{
    int rollno;
    char name[50];
    int p_marks, c_marks, m_marks, e_marks, cs_marks;
    double per;
    char grade;
    void calculate(); //function to calculate grade
public:
    void getdata();        //function to accept data from user
    void showdata() const; //function to show data on screen
    void show_tabular() const;
    int retrollno() const;
}; //class ends here

void student::calculate()
{
    per = (p_marks + c_marks + m_marks + e_marks + cs_marks) / 5.0;
    if (per >= 60)
        grade = 'A';
    else if (per >= 50)
        grade = 'B';
    else if (per >= 33)
        grade = 'C';
    else
        grade = 'F';
}

void student::getdata()
{
    cout << "\nEnter The roll number of student ";
    cin >> rollno;
    cout << "\n\nEnter The Name of student ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nEnter The marks in physics out of 100 : ";
    cin >> p_marks;
    cout << "\nEnter The marks in chemistry out of 100 : ";
    cin >> c_marks;
    cout << "\nEnter The marks in maths out of 100 : ";
    cin >> m_marks;
    cout << "\nEnter The marks in english out of 100 : ";
    cin >> e_marks;
    cout << "\nEnter The marks in computer science out of 100 : ";
    cin >> cs_marks;
    calculate();
}

void student::showdata() const
{
    cout << "\nRoll number of student : " << rollno;
    cout << "\nName of student : " << name;
    cout << "\nMarks in Physics : " << p_marks;
    cout << "\nMarks in Chemistry : " << c_marks;
    cout << "\nMarks in Maths : " << m_marks;
    cout << "\nMarks in English : " << e_marks;
    cout << "\nMarks in Computer Science :" << cs_marks;
    cout << "\nPercentage of student is  :" << per;
    cout << "\nGrade of student is :" << grade;
}

void student::show_tabular() const
{
    cout << rollno << setw(6) << " " << name << setw(10) << p_marks << setw(4) << c_marks << setw(4) << m_marks << setw(4) << e_marks << setw(4) << cs_marks << setw(8) << per << setw(6) << grade << endl;
}

int student::retrollno() const
{
    return rollno;
}

//***************************************************************
//    	function declaration
//****************************************************************

void write_student();     //write the record in binary file
void display_all();       //read all records from binary file
void display_sp(int);     //accept rollno and read record from binary file
void modify_student(int); //accept rollno and update record of binary file
void delete_student(int); //accept rollno and delete selected records from binary file
void class_result();      //display all records in tabular format from binary file
void result();            //display result menu
void intro();             //display welcome screen
void entry_menu();        //display entry menu on screen

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
    while (validation == "fail")
        loginpanel();

    system("cls");

    char ch;
    cout.setf(ios::fixed | ios::showpoint);
    cout << setprecision(2); // program outputs decimal number to two decimal places
    intro();
    do
    {
        system("cls");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t1. RESULT MENU";
        cout << "\n\n\t2. ENTRY/EDIT RESULT MENU";
        cout << "\n\n\t3. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            result();
            break;
        case '2':
            entry_menu();
            break;
        case '3':
            break;
        default:
            cout << "\a";
        }
    } while (ch != '3');
    return 0;
}

//***************************************************************
//    	function to write in file
//****************************************************************

void write_student()
{
    student st;
    ofstream outFile;
    outFile.open("student.dat", ios::binary | ios::app);
    st.getdata();
    outFile.write(reinterpret_cast<char *>(&st), sizeof(student));
    outFile.close();
    cout << "\n\nStudent's Record Has Been Created ";
    cin.ignore();
    cin.get();
}

//***************************************************************
//    	function to read all records from file
//****************************************************************

void display_all()
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "Data file not found !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        st.showdata();
        cout << "\n\n====================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "Data file not found !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        if (st.retrollno() == n)
        {
            st.showdata();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nRecord does not exist";
    cin.ignore();
    cin.get();
}

//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_student(int n)
{
    bool found = false;
    student st;
    fstream File;
    File.open("student.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "Data file not found !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }

    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&st), sizeof(student));
        if (st.retrollno() == n)
        {
            st.showdata();
            cout << "\n\nPlease Enter New Details of the Student" << endl;
            st.getdata();
            int pos = (-1) * static_cast<int>(sizeof(st));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&st), sizeof(student));
            cout << "\n\n\t Record has been Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_student(int n)
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "Data file not found !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("Temp.dat", ios::out);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        if (st.retrollno() != n)
        {
            outFile.write(reinterpret_cast<char *>(&st), sizeof(student));
        }
    }
    outFile.close();
    inFile.close();
    remove("student.dat");
    rename("Temp.dat", "student.dat");
    cout << "\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}

//***************************************************************
//    	function to display all students grade report
//****************************************************************

void class_result()
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "Data file not found !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
    cout << "==========================================================\n";
    cout << "R.No      Name         P   C   M   E  CS   %age   Grade" << endl;
    cout << "==========================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        st.show_tabular();
    }
    cin.ignore();
    cin.get();
    inFile.close();
}

//***************************************************************
//    	function to display result menu
//****************************************************************

void result()
{
    char ch;
    int rno;
    system("cls");
    cout << "\n\n\n\tRESULT MENU";
    cout << "\n\n\n\t1. Class Result";
    cout << "\n\n\t2. Student Report Card";
    cout << "\n\n\t3. Back to Main Menu";
    cout << "\n\n\n\tEnter Choice (1/2/3)? ";
    cin >> ch;
    system("cls");
    switch (ch)
    {
    case '1':
        class_result();
        break;
    case '2':
        cout << "\n\n\tEnter Roll Number Of Student : ";
        cin >> rno;
        display_sp(rno);
        break;
    case '3':
        break;
    default:
        cout << "\a";
    }
}

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
    cout << "\n\n\n\t\t\t\t\t  STUDENT INFO AND REPORT MANAGMENT";
    cout << "\n\n\n\n\t\t\t\t\t\t  MADE BY : GROUP 10";
    cin.get();
}

//***************************************************************
//    	ENTRY / EDIT MENU FUNCTION
//****************************************************************

void entry_menu()
{
    char ch;
    int num;
    system("cls");
    cout << "\n\n\n\tENTRY MENU";
    cout << "\n\n\t1.CREATE STUDENT REPORT";
    cout << "\n\n\t2.DISPLAY ALL STUDENT'S RESULTS";
    cout << "\n\n\t3.SEARCH STUDENT REPORT ";
    cout << "\n\n\t4.MODIFY STUDENT'S REPORT";
    cout << "\n\n\t5.DELETE STUDENT REPORT";
    cout << "\n\n\t6.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-6) ";
    cin >> ch;
    system("cls");
    switch (ch)
    {
    case '1':
        write_student();
        break;
    case '2':
        display_all();
        break;
    case '3':
        cout << "\n\n\tPlease Enter The roll number ";
        cin >> num;
        display_sp(num);
        break;
    case '4':
        cout << "\n\n\tPlease Enter The roll number ";
        cin >> num;
        modify_student(num);
        break;
    case '5':
        cout << "\n\n\tPlease Enter The roll number ";
        cin >> num;
        delete_student(num);
        break;
    case '6':
        break;
    default:
        cout << "\a";
        entry_menu();
    }
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
