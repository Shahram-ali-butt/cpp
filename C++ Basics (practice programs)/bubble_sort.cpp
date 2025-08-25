#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int searchFunc(int array[], int size, int element);
void sort(int array[], int size);
void sort2(int array[], int size);
void sort3(int array[], int size);
void mysort(int array[], int size);

int main()
{
    int grades[] = {10, 4, 1, 6, 2, 9, 5, 7, 3, 8, 20, 11, 44};
    int size = sizeof(grades)/sizeof(grades[0]);
    int index;
    int myNum;
    
    // cout << "Enter the no. you want to search for: " << endl;
    // cin >> myNum;
    
    // index = searchFunc(grades, size, myNum);

    // if(index != -1){
    //     cout << "The number is at index: " << index << endl;
    // }else{
    //     cout << "The number could not be found" << endl;
    // }

    // cout << "This is the full array: " << endl;
    // for(int elem : grades){
    //     cout << elem << endl;
    // }
    

    // *************  ARRAY sorting ****************
    sort3(grades, size);
    for(int elem : grades){
            cout << elem << " ";
    }

    return 0;
}

int searchFunc(int array[], int size, int element){
    int index;
    for(int i=0; i < size; i++){
        if(array[i] == element){
            return i;
        }
    }
    return -1;
}

void sort(int array[], int size){
    int temp;
    for(int i = 0; i < (size - 1); i++){
        for(int j = 0; j < (size - i - 1); j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void sort2(int array[], int size){
    int temp;
    for(int i = 0; i < (size - 1); i++){
        
        cout << "i th iteration " << i << endl;
        
        for(int j = 0; j < (size - i - 1); j++){
            
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }

            for(int k=0; k < size; k++){
                cout << array[k] << " ";
            }   
            cout << " iteration" << j << endl;
        }
        
    }
}


void sort3(int array[], int size){
    bool swapped;
    do{
        swapped = false;
        for(int i = 0; i < (size-1); i++){
            if(array[i] > array[i + 1]){
                std::swap(array[i],array[i + 1]);
                swapped = true;
            }
        }
    }while (swapped);
}

void mysort(int array[], int size){
    bool swaped;
    do{
        for(int i = 0; i < size - 1; i++){
            if(array[i] > array[i + 1]){
                std::swap(array[i], array[i + 1]);
                swaped = true;
            }
        }
    }while(swaped);
}