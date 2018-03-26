#include <iostream>
#include <string>
#include<fstream>
#include <windows.h>
#include <mysql.h>
#include<iomanip>
#include<sstream>

using namespace std;
/*ifstream fin;
ofstream fout;
fstream inoutfile;
//----------------------------------------------------------------class INVENTORY
class INVENTORY{
public:
int itemCode,itemPrice;
char itemName[15];

void putdata();
void getdata();
void update();
void addItem();
void showList();

}item;*/

string LogIn();

void SignUp() {
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int qstate;
	string username = "", password = "", fname = "", lname = "";
	char mni;


	conn = mysql_init(0);
	if (conn)   //if success
		cout << "Connection Successful" << endl;
	else cout << "Connection Problem" << mysql_errno(conn) << endl;
	conn = mysql_real_connect(conn, "localhost", "root", "", "palat_bakery_db", 0, NULL, 0);
	if (conn)   //if success
		cout << "Connection to database successful" << endl;
	else cout << "Database Connection Problem" << mysql_errno(conn) << endl;

	if (conn)
	{
		cout << "First Name: " << endl; cin >> fname;
		cout << "Last Name: " << endl; cin >> lname;
		cout << "Middle Initial: " << endl; cin >> mni;
		cout << "Choose a Username: " << endl; cin >> username;
		cout << "Enter Password: " << endl; cin >> password;

		string query = "insert into Authentication(Fname,Lname,MNI,UserName,Password) values('" + fname + "','" + lname + "','" + mni + "','" + username + "','" + password + "')";

		const char* q = query.c_str();
		cout << "query is: " << q << endl;
		qstate = mysql_query(conn, q);

		if (!qstate)
			cout << "record inserted successfully..." << endl;
		else
			cout << "query problem: " << mysql_error(conn) << endl;

		qstate = mysql_query(conn, "select * from Authentication");
	}
}

string LogIn() {
	int qstate;
	MYSQL* conn;
	const char* q = query.c_str();

	string username;
	string password;
	cout << "Please enter a Username and Password" << endl;
	cin >> username >> password;

	qstate = mysql_query(conn, "select * from Authentication where UserName="username" AND Password="password"");
	cout << "Welcome " << username << "!" << endl;
	//LogIn();
	//MainActivity();


}

/*void MainActivity(){//variable declarations
int chooseMain;
int choiceOwner,choiceCustomer;
int location;
char ch,yn;
int getch();


do{
/*label/mmain:

cout<<"\n\n"<<setw(50)<<"Bakery Billing System\n";
cout<<setw(54)<<"===========================\n\n";
cout<<"\n\t\t1.Admin\n\n";
cout<<"\t\t2.Customer\n\n";
cout<<"\t\t3.Exit\n\n";
cout<<"\t\tPlease Enter Required Option: ";
cin>>chooseMain;
system("cls");


switch(chooseMain)
{
//-----------------------------------------------------------------------------------------owner option
case 1:
system("cls");
opmain:
cout<<"\n\n"<<setw(50)<<"Admin Access Window\n";
cout<<setw(54)<<"===========================\n\n";
int currentpass,oldpass,newpass;
cout<<"\n\t\tIf you are first time user then enter any number!\n";
cout<<"\n\t\tEnter password: ";
cin>>oldpass;
fin.open("Pass.dat");
if(!fin)
{
system("cls");
setpass:
cout<<"\n\n"<<setw(50)<<"Admin Access Window\n";
cout<<setw(54)<<"===========================\n\n";
cout<<"\n\t\tIn order to use the program...\n\n";
cout<<"\n\t\tPlease create new password: ";
cin>>oldpass;
cout<<"\n\t\tRe-enter password: ";
cin>>newpass;
if(oldpass==newpass)
{
system("cls");
cout<<"\n\n\nBy creating new password you're agree to our terms and conditions.(Y/N)?:";
cin>>yn;
if((yn=='Y')||(yn=='y'))
{
system("cls");
fout.open("Pass.dat");
fout<<oldpass;
fout.close();
cout<<endl<<"\n\n\tCongratulation! You've successfully created new password...";
}
else if((yn=='N')||(yn=='n'))
{
system("cls");
goto mmain;
}
}
else
{
cout<<"\n\n\t\tPassword not match. Please try again...";
getch();
system("cls");
goto setpass;
}
getch();
system("cls");
goto opmain;
}
fin>>newpass;
fin.close();
system("cls");
if(oldpass==newpass)
{
omain:
cout<<"\n\n"<<setw(50)<<"Admin Access Window\n";
cout<<setw(54)<<"===========================\n\n";
cout<<"\n\t\t1.Show item menu\n\n";
cout<<"\t\t2.Add item in menu\n\n";
cout<<"\t\t3.Modify item in menu\n\n";
cout<<"\t\t4.Change password\n\n";
cout<<"\t\t5.Back to previous menu\n\n";
cout<<"\t\t6.Exit\n\n";
cout<<"\t\tPlease Enter Required Option: ";
do{

cin>>choiceOwner;
switch(choiceOwner)
{


//Show the menu list
case 1:
system("cls");
item.showList();
getch();
system("cls");
goto omain;
break;


//add a new item in menu list
case 2:
system("cls");
cout<<"\n\n\t\t<<<<<<<<<<<<<<<<<<<<ADD AN ITEM>>>>>>>>>>>>>>>>>>>>\n\n";
item.addItem();
cout<<"\n\n\t\tItem added successfully...";
getch();
system("cls");
goto omain;
break;
//Update file content
case 3:
system("cls");
item.update();
getch();
system("cls");
goto omain;
break;
case 4:
system("cls");
changepass:
cout<<"\n\n"<<setw(50)<<"Change Password\n";
cout<<setw(54)<<"===========================\n\n";
cout<<"\n\t\tEnter current password: ";
cin>>currentpass;
fin.open("Pass.dat");
if(!fin)
{
cout<<endl<<"File not found...";
exit(1);
}
fin>>oldpass;
fin.close();
if(oldpass==currentpass)
{
fout.open("Pass.dat");
cout<<"\n\t\tEnter new password: ";
cin>>newpass;
cout<<"\n\t\tRe-enter new password: ";
cin>>oldpass;
if(newpass==oldpass)
{
fout<<newpass;
fout.close();
cout<<"\n\n\t\tPassword successfully changed...";
getch();
system("cls");
goto opmain;
}
else
{
cout<<"\n\t\tNew password not match. Please try again...";
getch();
system("cls");
goto changepass;
}
}
else
{
cout<<"\n\t\tPassword not match. Please try again...";
getch();
system("cls");
goto changepass;
}
break;

//Back to menu
case 5:
system("cls");
goto mmain;
break;

//Exit
case 6:
system("cls");
cout<<"\n\n\t\tARE YOU SURE, YOU WANT TO EXIT (Y/N)?:";
cin>>yn;
if((yn=='Y')||(yn=='y'))
{
system("cls");
cout<<"\n\n\n"<<setw(60)<<"Thank you for visiting our bakery store.\n\n\n\n";
exit(0);
}
else if((yn=='N')||(yn=='n'))
{
system("cls");
goto omain;
}
break;
default:
system("cls");
goto omain;
break;
}
}while(choiceOwner!=5);}
else
{
cout<<"\n\n\t\tWrong password entered. Please try again...";
getch();
system("cls");
goto opmain;
}
break;

}*/
int main()
{

	int option;
	cout << "Hello Welcome To The Authentication Menu" << endl;
	cout << "select from the option below\n"
		<< "[1] Login" "\n"
		<< "[2] Register" "\n"
		<< "[3] Exit" << endl;

	cin >> option;
	switch (option) {
	case 1:
		LogIn();
		break;
	case 2:
		SignUp();
		break;

	}

	return 0;

}


int main()
{
    return 0;
}

    return username;
}

void login()
{
     int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        std::string username = get_input <std::string>("Please enter a username.");
        std::string password = get_input <std::string>("Please enter a password.");
        /*std::cout << "Username: \"" << username << "\"\n";
        std::cout << "Password: \"" << password << "\"\n"; */

        }
        if (username == &username && password == &password)
        {
            cout << "Welcome" << username << "!\n";
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
            cout << "Too many login attempts! The program will now terminate.";
            return 0;
    }

    std::cout << "You are being logged in!" "\n";
}

void main_menu()
{
    int choice = get_input <int>(
        "Hello, Would you like to log in or register?" "\n"
        "[1] Login" "\n"
        "[2] Register" "\n"
        "[3] Exit");

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        register_user();
        break;
    }
}

void register_user()
{
    std::string username = get_username();
    std::string password = get_password();
    save_user(username, password);
}

void save_user(const std::string &username, const std::string &password)
{
    std::string filename = username + ".txt";
    std::ofstream file(filename);
    file << password << "\n";
}

