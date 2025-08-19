#include <iostream>
using std::cout, std::cin, std::string, std::endl;

int sumEven(const string cardNum);
int sumOdd(const string cardNum);
int getDigit(int num);

int main(){
    string cardNum;
    int result = 0;

    cout << "Enter your credit card number: ";
    cin >> cardNum;

    result = sumEven(cardNum) + sumOdd(cardNum);

    if(result % 10 == 0){
        cout << "The provided number is a valid credit card number";
    }else{
        cout << "The provided number is a invalid credit card number";
    }

    return 0;
}

int sumEven(const string cardNum){
    int sum;
    for(int i = cardNum.size() - 2; i >=0; i-=2){
        sum += getDigit((cardNum[i] - '0') * 2);
    }
    
    return sum;
}

int sumOdd(const string cardNum){
    int sum;
    for(int i = cardNum.size() - 1; i >=0; i-=2){
        sum += getDigit(cardNum[i] - '0');
    }
    
    return sum;
}

int getDigit(int num){
    return ((num % 10) + (num / 10 % 10));
}