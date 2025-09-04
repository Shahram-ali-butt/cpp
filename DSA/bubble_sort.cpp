#include <iostream>
using namespace std;

template<typename T>
void bubble_sort(T arr[], int size){
    T temp;
    for(int i = 0; i <= size - 1; i++){
        // cout << "running pass " << i + 1 << endl; 
        for(int j = 0; j < (size - 1 - i); j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            }
        }
    }
}

template<typename T>
void bubble_sort_adaptive(T arr[], int size){
    T temp;
    bool is_sorted = false;
    for(int i = 0; i <= size - 1; i++){
        is_sorted = true;
        // cout << "running pass " << i + 1 << endl; 
        for(int j = 0; j < (size - 1 - i); j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
                is_sorted = false;
            }
        }
        if(is_sorted){
            return;
        }
    }
}

template<typename T>
void bubble_sort_efficient(T arr[], int size){
    bool swaped;
    // int pass = 0;
    do{
        swaped = false;
        // ++pass;
        // cout << "running pass " << pass << endl;
        for(int i = 0; i < size - 1; ++i){
            if(arr[i] > arr[i + 1]){
                swap(arr[i], arr[i + 1]);
                swaped = true;
            }
        }
    }while(swaped);
}

template<typename T>
void printArray(T arr[], int size){
    for(int i= 0; i<size; ++i){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {6,2,5,8,10,3,7,1,9,4};
    char arr2[] = {'h', 'a', 's', 'b', 'a'};
    int arr3[] = {1,2,3,4,5,6,7,8,9,10};
    
    int size = sizeof(arr3)/sizeof(arr3[0]);
    bubble_sort(arr3, size);
    printArray(arr3, size);
    return 0;
}