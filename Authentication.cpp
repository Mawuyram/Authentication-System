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

