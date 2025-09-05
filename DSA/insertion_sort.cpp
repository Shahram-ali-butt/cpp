#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size){
    int key, j;
    for(int i = 1; i < size; ++i){
        cout << "running pass: " << i << endl;
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] > key){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int arr[] = {8,3,6,5,1,10,2,7,9,4};
    int arr2[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr, size);

    for(int elem: arr){
        cout << elem << " ";
    }

    return 0;
}