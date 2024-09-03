#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class ATM {
private:
    unordered_map<string, string> accounts; // stores user id and password
    double balance; // user's balance

public:
    ATM() : balance(0.0) {} // constructor to initialize balance

    // Function to create a new account
    void createAccount() {
        string userid, password;
        cout << "Please enter your user ID: ";
        cin >> userid;
        cout << "Please enter your password: ";
        cin >> password;

        // Check if the account already exists
        if (accounts.find(userid) != accounts.end()) {
            cout << "Account already exists! Please try again." << endl;
        } else {
            accounts[userid] = password; // store user ID and password
            cout << "Thank you! Your account has been created!" << endl;
        }
    }

    // Function to log in
    bool login() {
        string userid, password;
        cout << "Please enter your user ID: ";
        cin >> userid;
        cout << "Please enter your password: ";
        cin >> password;

        // Check if the login is successful
        if (accounts.find(userid) != accounts.end() && accounts[userid] == password) {
            cout << "Login successful!" << endl;
            return true; // successful login
        } else {
            cout << "***Login failed!***" << endl;
            return false; // failed login
        }
    }

    // Main menu after successful login
    void mainMenu() {
        int choice;
        do {
            cout << "\nMAIN MENU" << endl;
            cout << "1. Withdraw money" << endl;
            cout << "2. Deposit money" << endl;
            cout << "3. Request balance" << endl;
            cout << "4. Quit" << endl;
            cout << "Select an option: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    withdrawMoney();
                    break;
                case 2:
                    depositMoney();
                    break;
                case 3:
                    requestBalance();
                    break;
                case 4:
                    cout << "Thank you for using the ATM!" << endl;
                    break;
                default:
                    cout << "Invalid option! Please try again." << endl;
            }
        } while (choice != 4); // loop until user chooses to quit
    }

    // Function to withdraw money
    void withdrawMoney() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount; // deduct amount from balance
            cout << "Please take your cash: " << amount << endl;
        }
    }

    // Function to deposit money
    void depositMoney() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "You have successfully deposited: " << amount << endl;
    }

    // Function to request balance
    void requestBalance() {
        cout << "Your current balance is: " << balance << endl;
    }
};

int main() {
    ATM atm; // create ATM object
    char option;
    cout << "Hi! Welcome to the ATM machine" << endl;

    do {
        cout << "\nPlease select an option from the menu below: " << endl;
        cout << "l -> Login" << endl;
        cout << "c -> Create" << endl;
        cout << "q -> Quit" << endl;
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 'l':
                if (atm.login()) { // if login is successful
                    atm.mainMenu(); // show main menu
                }
                break;
            case 'c':
                atm.createAccount(); // create a new account
                break;
            case 'q':
                cout << "Thank you for using the ATM! Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    } while (option != 'q'); // loop until user chooses to quit

    return 0;
}

