#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

void showBalance(double balance);
double deposit(double balance);
double withdraw(double balance);

int main()
{
    int choise;
    double balance = 0.0;
    
    cout << "********* Bank Program *********" << endl;
    
    do{
    cout << endl << "Enter the task you want to perform (1-4): " << endl;
    cout << "1: show balance" << endl;
    cout << "2: deposit money" << endl;
    cout << "3: withdraw money" << endl;
    cout << "4: exit" << endl;
    cin >> choise;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    switch(choise){
        case 1: showBalance(balance);
                break;
        case 2: balance += deposit(balance);
                showBalance(balance);
                break;
        case 3: balance -= withdraw(balance);
                showBalance(balance);
                break;
        case 4: cout << "Thank you for visiting!" << endl;
                break;
        default: cout << "Invalid input. Enter a number from 1-4" << endl;
                 break;
    }
    }while(choise!=4);
    
    
    cout << "********************************";

    return 0;
}

void showBalance(double balance){
    cout << "Your balance is $" << setprecision(2) << fixed << balance << endl;
}

double deposit(double balance){
    double amount;
    cout << "Enter amount you want to deposit: " << endl;
    cin >> amount;
    if(amount>0){
    return amount;
    }else{
        cout << "Invalid amount!" << endl;
        return 0;
    }
    
}

double withdraw(double balance){
    double amount;
    cout << "Enter amount you want to withdraw: " << endl;
    cin >> amount;
    if(amount > balance){
        cout << "Insufficient funds!" << endl;
        return 0;
    }else if(amount < 0){
        cout << "Invalid amount!" << endl;
        return 0;
    }else{
        return amount;
    }
    
}


