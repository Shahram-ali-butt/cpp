#include <iostream>
using namespace std;

int main(){

    for(int i = 0; i <= 5; i++){ 
        for(int j = 0; j < i; j++){
            cout << '*' ;
        }
        cout << endl;
    }                       

    cout << endl;
    
    for(int i = 5; i >= 1; i--){
        for(int k = 5; k > i ; k--){
            cout << " ";
        }
        for(int j = 0; j < i; j++){
            cout << '*' ;
        }
        cout << endl;
    }
    
    cout << endl;
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << '*';
        }
        cout << endl;
    }

    for(int i = 0; i <= 5; i++){
        for(int j = 0; j < i; j++){
            cout << j;
        }
        cout << endl;
    }

    for(int i = 0; i<=5; i++){
        for(int j = 0; j<i; j++){
           switch (j)
           {
           case 0:
            cout << '*';
            break;
           case 1:
            cout << '@';
            break;
           case 2:
            cout << '#';
            break;
           case 3:
            cout << '$';
            break;
           case 4:
            cout << '&';
            break;
           }
        }
        cout << endl;
    }
    
    return 0;
}