#include<stdio.h>

typedef struct {
    int accountNo;
    float balance;
} Account;

Account accounts[100];
int counter = 0;

void createAccount() {
    Account newAccount;
    newAccount.accountNo = counter;
    newAccount.balance = 0;
    accounts[counter++] = newAccount;
    printf("Account created with Account Number: %d\n", newAccount.accountNo);
}

void deposit(int accountNo, float amount) {
    for(int i=0; i<counter; i++) {
        if(accountNo == accounts[i].accountNo) {
            accounts[i].balance += amount;
            printf("Money deposited successfully!\n");
        }
    }
}

void withdraw(int accountNo, float amount) {
    for(int i=0; i<counter; i++) {
        if(accountNo == accounts[i].accountNo) {
            if(accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Money withdrawn successfully!\n");
            } else {
                printf("Insufficient balance!\n");
            }
        }
    }
}

void checkBalance(int accountNo) {
    for(int i=0; i<counter; i++) {
        if(accountNo == accounts[i].accountNo) {
            printf("Your current balance is: %f\n", accounts[i].balance);
        }
    }
}

int main() {
    int choice;
    int accountNo;
    float amount;

    while(1) {
        printf("\n********** Welcome to the Bank Management System ********\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");

        printf("Please select your option: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            printf("Enter account number: ");
            scanf("%d", &accountNo);
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            deposit(accountNo, amount);
            break;
        case 3:
            printf("Enter account number: ");
            scanf("%d", &accountNo);
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            withdraw(accountNo, amount);
            break;
        case 4:
            printf("Enter account number: ");
            scanf("%d", &accountNo);
            checkBalance(accountNo);
            break;
        case 5:
            printf("Thank for using the Bank Management System. Goodbye.\n");
            return 0;
        default:
            printf("Incorrect option, try again.");
            break;
        }
    }
    return 0;
}