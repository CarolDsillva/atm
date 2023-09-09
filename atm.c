#include <stdio.h>
#include <stdbool.h>

// Global variables to store the account balance and PIN
float balance = 1000.0;
int pin = 1234; // Change this to your desired PIN

// Function to display the main menu
void displayMenu() {
    printf("\n************ ATM Menu ************\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Change PIN\n");
    printf("5. Exit\n");
    printf("***********************************\n");
}

// Function to check account balance
void checkBalance() {
    printf("Your account balance is $%.2f\n", balance);
}

// Function to deposit money
void deposit() {
    float amount;
    printf("Enter the amount to deposit: $");
    scanf("%f", &amount);
    
    if (amount > 0) {
        balance += amount;
        printf("Deposit successful. Your new balance is $%.2f\n", balance);
    } else {
        printf("Invalid amount. Please enter a positive amount.\n");
    }
}

// Function to withdraw money
void withdraw() {
    float amount;
    printf("Enter the amount to withdraw: $");
    scanf("%f", &amount);
    
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        printf("Withdrawal successful. Your new balance is $%.2f\n", balance);
    } else {
        printf("Invalid amount or insufficient balance.\n");
    }
}

// Function to change PIN
void changePin() {
    int newPin;
    printf("Enter your current PIN: ");
    scanf("%d", &pin);
    
    if (pin == 1234) { // Change this to your current PIN
        printf("Enter your new PIN: ");
        scanf("%d", &newPin);
        pin = newPin;
        printf("PIN successfully changed.\n");
    } else {
        printf("Incorrect PIN. PIN change failed.\n");
    }
}

int main() {
    int choice;
    int enteredPin;
    bool authenticated = false;
    char continueChoice;
    
    printf("Welcome to the ATM\n");
    
    while (1) {
        if (!authenticated) {
            printf("Please enter your PIN: ");
            scanf("%d", &enteredPin);
            
            if (enteredPin == pin) {
                printf("PIN accepted. Access granted.\n");
                authenticated = true;
            } else {
                printf("Incorrect PIN. Access denied.\n");
            }
        } else {
            displayMenu();
            printf("Enter your choice: ");
            scanf("%d", &choice);
            
            switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    changePin();
                    break;
                case 5:
                    printf("Thank you for using the ATM. Goodbye!\n");
                    return 0;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
            
            // Ask if the user wants to continue
            printf("Do you want to perform another operation? (y/n): ");
            scanf(" %c", &continueChoice);
            if (continueChoice != 'y' && continueChoice != 'Y') {
                printf("Thank you for using the ATM. Goodbye!\n");
                return 0;
            }
        }
    }
    
    return 0;
}
