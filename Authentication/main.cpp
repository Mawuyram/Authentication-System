#include <iostream>
#include <string>
#include<fstream>
#include <windows.h>
#include <mysql.h>
#include<iomanip>
#include<sstream>

using namespace std;

string LogIn();

void SignUp(){
     cout<<"\n\n"<<setw(50)<<"Admin Access Window\n";
        cout<<setw(54)<<"===========================\n\n";
    MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int qstate;
	string username = "", password = "", fname = "", lname = "";
	char mni;


conn = mysql_init(0);
     if(conn)
    {
        cout<<"First Name: "<<endl; cin>>fname;
        cout<<"Last Name: "<<endl; cin>>lname;
        cout<<"Middle Initial: "<<endl; cin>>mni;
        cout<<"Choose a Username: "<<endl; cin>>username;
        cout<<"Enter Password: "<<endl; cin>>password;

        string query="insert into Authentication(Fname,Lname,MNI,UserName,Password) values('"+fname+"','"+lname+"','"+mni+"','"+username+"','"+password+"')";

        const char* q = query.c_str();
        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(conn,q);

        if(!qstate)
            cout<<"record inserted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;

        qstate = mysql_query(conn,"select * from Authentication");

         if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                cout<<"fname: "<<row[0]<< " "
                    <<"lname: "<<row[1]<< " "
                    <<"mni: "<<row[2]<< " "
                    <<"username: "<<row[3]<< " "
                    <<"password: "<<row[4]<<endl;
            }
        }
        else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
    }
    else
    {
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
    }

    mysql_close(conn);

}


string LogIn(){
     bool qstate=false;
     MYSQL* conn;
     string query;
     const char* q = query.c_str();

    string username;
    string password;
    do {
    cout<<"Please enter a Username and Password"<< endl;
    cin >> username >> password;
    //qstate = mysql_query(conn,"select * from Authentication where UserName='"+this->username->Text+"' AND Password='"+username+"'");
    cout << "Welcome "<<username<<"!"<<endl;
    }
    while(qstate=false);

    LogIn();
   // MainActivity();


}

//void MainActivity(){

int main()
{

    int option;
    cout << "Hello Welcome To The Authentication Menu" << endl;
    cout <<"select from the option below\n"
         <<"[1] Login" "\n"
         <<"[2] Register" "\n"
         <<"[3] Exit"<< endl;

    cin >> option;
    switch(option){
        case 1:
        LogIn();
    break;
        case 2:
        SignUp();
    break;

    }

    return 0;

}
