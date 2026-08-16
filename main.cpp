#include <iostream>
#include <string>
using namespace std;

struct Account {
    string name;
    int accountNumber;
    float balance;
};

Account accounts[100];   // Fixed size array
int accountCount = 0;    // Track number of accounts

// Create Account
void createAccount() {
    if (accountCount >= 100) {
        cout << "Account list is full!\n";
        return;
    }
    Account acc;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, acc.name);
    cout << "Enter Account Number: ";
    cin >> acc.accountNumber;
    acc.balance = 0;
    accounts[accountCount++] = acc;
    cout << "Account created successfully!\n";
}

// Deposit Money
void deposit(int accNo, float amount) {
    bool found = false;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNo) {
            accounts[i].balance += amount;
            cout << "Deposited " << amount << " successfully\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Account not found!\n";
}

// Withdraw Money
void withdraw(int accNo, float amount) {
    bool found = false;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNo) {
            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                cout << "Withdrawn " << amount << " successfully\n";
            } else {
                cout << "Insufficient Balance!\n";
            }
            found = true;
            break;
        }
    }
    if (!found) cout << "Account not found!\n";
}

// Check Balance
void checkBalance(int accNo) {
    bool found = false;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNo) {
            cout << "Account Holder: " << accounts[i].name << endl;
            cout << "Account Number: " << accounts[i].accountNumber << endl;
            cout << "Current Balance: " << accounts[i].balance << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Account not found!\n";
}

int main() {
    int choice, accNo;
    float amount;

    while (true) {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(accNo, amount);
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(accNo, amount);
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accNo;
                checkBalance(accNo);
                break;
            case 5:
                cout << "Thank you for using Banking System!\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
