#include <iostream>
using namespace std;

template <typename T, typename V>
int binary_search(const T ar[], int size, V elem){
    int start = 0;
    int end = size - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(ar[mid] == elem) return mid;        
        if(elem < ar[mid]){
            end = mid - 1;
        }else if(elem > ar[mid]){
            start = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    std::string arr2[] = {"Hello", "World", "shahram", "harmain", "ali"};
    
    int size = sizeof(arr) / sizeof(arr[0]);
    
    for(auto elem : arr){
        cout << elem << " ";
    }
    cout << endl;

    int index = binary_search(arr, size, 4);
    cout << index << endl;
    
    return 0;
}