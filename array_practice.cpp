#include <iostream>

int main(){
    const int size = 6;
    std::string fruits[size];
    
    fill(fruits, fruits + 1, "Apple");         // index 0
    fill(fruits + 1, fruits + 2, "Banana");    // index 1
    fill(fruits + 2, fruits + 3, "Apricot");   // index 2
    fill(fruits + 3, fruits + 4, "Mango");     // index 3
    fill(fruits + 4, fruits + 5, "Pineapple"); // index 4
    fill(fruits + 5, fruits + 6, "Guava");     // index 5

    for(std::string fruit : fruits){
        std::cout << fruit << " "; 
    }

    return 0;
}