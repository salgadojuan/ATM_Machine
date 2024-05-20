#include <iostream>
using namespace std;

// ARRAY TO STORE ACCOUNT BALANCES FOR 10-PEOPLE:
double account_Balances[10] = { 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };

// FUNCTION THAT DISPLAY MAIN MENU:
void display_Menu() {
    cout << "1. Sign in" << "\n";
    cout << "2. Balance" << "\n";
    cout << "3. Deposit" << "\n";
    cout << "4. Withdraw" << "\n";
    cout << "5. Exit" << "\n";
}

// VALIDATES ACCOUNT NUMBER:

bool validate_Account(int account_Number) {
    return (account_Number >= 0 && account_Number <= 9);
}

// FOR BALANCE INQUIRY (Option 2):

void check_Balance(int account_Number) {
    double balance = account_Balances[account_Number];
    cout << "Current Balance: $" << balance << "\n";
    if (balance < 100) {
        cout << "Low Balance" << "\n";
    }
}

// FUNCTION FOR DEPOSIT (Option 3):

void deposit(int accountNumber) {
    cout << "Enter the amount to deposit: $";
    double amount;
    cin >> amount;
    if (amount <= 0) {
        cout << "Invalid amount." << "\n";
        return;
    }
    account_Balances[accountNumber] += amount;
    cout << "Deposit successful." << "\n";
}

// FUNCTION FOR WITHDRAW (Option 4):

void withdraw(int accountNumber) {
    cout << "Enter the amount to withdraw: $";
    double amount;
    cin >> amount;
    if (amount <= 0) {
        cout << "Invalid amount." << "\n";
        return;
    }
    double balance = account_Balances[accountNumber];
    if (amount > balance) {
        cout << "Insufficient balance. Current balance: $" << balance << "\n";
        cout << "Please enter a new amount: $";
        cin >> amount;
        if (amount <= balance) {
            account_Balances[accountNumber] -= amount;
            cout << "Withdrawal successful." << "\n";
        }
    }
    else {
        account_Balances[accountNumber] -= amount;
        cout << "Withdrawal successful." << "\n";
    }
}

// FUNCTION TO EXIT (Option 5):

void exit_ATM() {
    cout << "Thank You. Goodbye!" << "\n";
}

int main() {

    int accountNumber;
    bool loggedIn = false;

    while (true) {
        if (loggedIn) {
            display_Menu();
            int option;

            cout << "Enter your option: ";
            cin >> option;

            switch (option) {
                case 1: // Sign in
                    loggedIn = false;
                    break;
                case 2: // Balance
                    check_Balance(accountNumber);
                    break;
                case 3: // Deposit
                    deposit(accountNumber);
                    break;
                case 4: // Withdraw
                    withdraw(accountNumber);
                    break;
                case 5: // Exit
                    exit_ATM();
                    return 0;
                default:
                    cout << "Invalid option. Try again." << "\n";
                    break;
            }
        }

        else {
            cout << "Enter your account number (0-9): ";
            cin >> accountNumber;
            if (validate_Account(accountNumber)) {
                loggedIn = true;
            }
            else {
                cout << "Invalid account number. Try again." << "\n";
            }
        }
    }

    return 0;
}
