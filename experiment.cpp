#include <iostream>
using std::cout, std::cin, std::string, std::endl;

enum Day {sunday , monday, tuesday, wednessday, thursday, friday, saturday};

struct Car {
    string brand;
    int year;
    bool working;
    private:
        int price = 5000;
    public:
        void changePrice(int pr){price = pr; cout << price;};
};

long long factorial(int num);

template <typename T> 
T max(T a, T b){
    return (a > b)? a : b;
}

template <typename T, typename U>
auto max(T a, U b){
    return (a > b)? a : b;
}

int main(){
    int num;

    class Human{
        protected:
            string name = "shahram";
            int age = 10;
        public:
            void getName(){cout << name << endl;}
    };

    class Doctor : public Human{
        public:
        string scale;
        string designation;
        void getAge(){cout << age << endl;}

    };

    Day today = monday;
    Human shahram;
    Doctor harmain;

    shahram.getName();

    cout << "The name Doctor harmain is " << endl;
    // harmain.getName();
    cout << "The age of Doctor harmain is " << endl;
    harmain.getAge();


    Car car1;
    car1.brand = "shelby";
    // car1.changePrice(2000);
    return 0;
}

long long factorial(int num){
    if(num > 1){
        return num * factorial(num - 1);;
    }else{
        return 1;
    }
}
