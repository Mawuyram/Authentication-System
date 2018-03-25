#include <fstream>
#include <iostream>
#include <limits>
#include <string>

template <typename T>
T get_input(const std::string &strQuery);

std::string get_username();
std::string get_password();
void save_user(const std::string &username, const std::string &password);

void login();
void register_user();
void main_menu();

int main()
{
    main_menu();
}

template <typename T>
T get_input(const std::string &strQuery)
{
    std::cout << strQuery << "\n> ";
    T out = T();

    while (!(std::cin >> out)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        std::cout << "Error!" "\n";
        std::cout << strQuery << "\n> ";
    }

    return out;
}

std::string get_password()
{
    std::string password1 = get_input <std::string> ("Please enter your password.");
    std::string password2 = get_input <std::string> ("Please re-enter your password.");

    while (password1 != password2) {
        std::cout << "Error! Passwords do not match." "\n";
        password1 = get_input <std::string>("Please enter your password.");
        password2 = get_input <std::string>("Please re-enter your password.");
    }

    return password1;
}

std::string get_username()
{
    std::string username = get_input <std::string>("Please enter a username.");
    std::cout << "Username: \"" << username << "\"\n";

    while (get_input <int>("Confirm? [0|1]") != 1) {
        username = get_input <std::string>("Please enter a username.");
        std::cout << "Username: \"" << username << "\"\n";
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

