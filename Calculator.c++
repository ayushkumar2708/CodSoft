#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    double num1, num2, result;
    char operation;
    char choice;

    do {
        cout << "Simple Calculator\n";
        cout << "-----------------\n";
        cout << "Enter 1st number: ";
        cin >> num1;
        cout << "Enter 2nd number: ";
        cin >> num2;

        cout << "Choose an operation (+, -, *, /): ";
        cin >> operation;

        switch (operation) {
            case '+':
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << fixed << setprecision(2); 
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Cannot divide by zero.\n";
                }
                break;
            default:
                cout << "Invalid operation. Please enter +, -, *, or /.\n";
        }

        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> choice;
        cout << "-----------------\n";

    } while (choice == 'y' || choice == 'Y');

    cout << "Calculator closed.\n";
    return 0;
}
