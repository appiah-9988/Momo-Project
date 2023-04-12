#include <iostream>
#include <string>

using namespace std;

// Declare global variables
string pin = "0000";
int balance = 1000;
int attempts = 0;

// Function to authenticate user
bool authenticate(string inputPin) {
    if (inputPin == pin) {
        attempts = 0;
        return true;
    } else {
        attempts++;
        if (attempts == 3) {
            cout << "Too many incorrect attempts. Exiting program." << endl;
            exit(0);
        } else {
            cout << "Incorrect pin. Please try again." << endl;
            return false;
        }
    }
}

// Function to change/reset pin
void changePin() {
    string oldPin, newPin;
    cout << "Enter old pin: ";
    cin >> oldPin;
    if (authenticate(oldPin)) {
        cout << "Enter new pin: ";
        cin >> newPin;
        pin = newPin;
        cout << "Pin changed successfully." << endl;
    }
}

// Function to check balance
void checkBalance() {
    if (authenticate(pin)) {
        cout << "Your balance is " << balance << ".cedisbbbbbbgyh~	" << endl;
    }
}

// Function to send money
void sendMoney() {
    if (authenticate(pin)) {
        int amount;
        cout << "Enter amount to send: ";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            balance -= amount;
            cout << "Money sent successfully." << endl;
        }
    }
}

int main() {
    int choice;
    string inputPin;

    do {
        cout << "Select an option: " << endl;
        cout << "1. Authentication" << endl;
        cout << "2. Resetting/changing Pin" << endl;
        cout << "3. Checking balance" << endl;
        cout << "4. Sending money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system ("cls");
        switch (choice) {
            case 1:
                cout << "Enter pin: ";
                cin >> inputPin;
                authenticate(inputPin);
            system ("pause>0");
			    system ("cls");
                break;
            case 2:
                changePin();
                system ("pause>0");
				system ("cls");
                break;
            case 3:
                checkBalance();
                system ("pause>0");
			    system ("cls");
                break;
            case 4:
                sendMoney();
                    system ("pause>0");
				system ("cls");
                break;
            case 5:
                cout << "Exiting program." << endl;
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

