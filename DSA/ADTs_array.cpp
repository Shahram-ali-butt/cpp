#include <iostream>
using namespace std;

template <typename T>
class my_array{
    private:
        int total_size;
        int used_size;
        T* ptr = nullptr;

    public:
        my_array(int ts, int us) : total_size(ts), used_size(us){
            ptr = new T[total_size];
        }

        ~my_array(){
            delete[] ptr;
        }

        int get_used_size() const{
            return used_size;
        }
        
        void set() const {
            T n;
            for(int i = 0; i < used_size; i++){
                cout << "Enter element you want to add to the array #" << i <<" : ";
                cin >> n;
                ptr[i] = n; 
            }
        }

        T get(int index) const {
            if(index < 0 || index >= used_size){
                cout << "There is no element at index: " << index << endl;
                return -1;
            }
            return ptr[index];
        }
        
        void print() const {
            cout << "[";
            for(int i = 0; i < used_size; i++){
                cout << ptr[i];
                if(i != used_size - 1){
                    cout << ",";
                }
            }
            cout << "]" << endl;
        }

        void del(int index){
            if(index < 0 || index >= used_size){
                cout << "There is no element at index: " << index << endl;
                return;
            }else{
                for(int i = index; i < used_size - 1; i++){
                    ptr[i] = ptr[i + 1];
                }
                --used_size;
            }
        }

        void del(int index) const {
            throw logic_error("del() won't work for 'const' object. Cannot change the attribute 'used_size'");
        }

        T& operator[](int index) {
            if (index < 0 || index >= used_size) throw out_of_range("Index out of range");
            return ptr[index];
        }

        const T& operator[](int index) const {
            if (index < 0 || index >= used_size) throw out_of_range("Index out of range");
            return ptr[index];
        }
        
        void insert(int index, T elem){
            if (index < 0 || index > used_size){
                cout << "Operation Out of range!";
                return;
            }
        
            if (used_size >= total_size) {
                cout << "Array is full. Cannot insert." << endl;
                return;
            }
                
            for (int i = used_size; i > index; i--)
            {
                ptr[i] = ptr[i - 1];
            }

            ptr[index] = elem;
            used_size++;
        }
        
        void insert(int index, T elem) const{
            throw logic_error("insert() won't work with 'const' object.");
        }
        
        int linear_search(T elem) const{
            for(int i = 0; i < used_size; i++){
                if(elem == ptr[i]){
                    return i;
                }
            }
            return -1;
        }
        
        int binary_search(T elem) const{
            T start = 0;
            T mid = used_size / 2;
            T end = used_size - 1;
            cout << "First mid: " << mid << endl;
            while(start <= end){
                if(elem == ptr[mid]){
                    return mid;
                }else if(elem < ptr[mid]){
                    end = mid - 1;
                    mid = (start + end) / 2;
                }else if(elem > ptr[mid]){
                    start = mid + 1;
                    mid = (start + end) / 2;
                    
                }
            }
            return -1;
        }
        
        int search(T elem, bool is_sorted = false) const{
            if(is_sorted){
                return binary_search(elem);
            }
            return linear_search(elem);
        }
};
    

int main(){
    my_array<int> a1(20, 10);
    a1.set(); // setting all positions to be used not all positions allocated
    a1.print(); // prints as an array

    // a1[2] = 16; // Elements are made accessible as well as modifiableusing bracket syntax
    // int x = a1[2];
    int y = a1.get(16); // Can also access elements using get method
    cout << y << endl;
    // a1.del(1); // won't run for const object! takes index to delete element. 
  
    // a1.insert(3, 3); // won't work with const object! takes index & element 
    

    // int position1 = a1.linear_search(2); // For both sorted and unsorted arrays.
    // (position1 != -1) ? cout << a1[position1] << " is at index: " << position1 : cout <<"The element was not found!";
    
    // int position2 = a1.binary_search(2); // Only for sorted arrays
    // (position2 != -1) ? cout << a1[position2] << " is at index: " << position2 : cout <<"The element was not found!";
    
    // int search_index1 = a1.search(9); //runs linear search. Optional parameter 'is_sorted' set to false as default.
    // int search_index2 = a1.search(2, true); //optional parameter 'is_sorted' set to true. Will run binary search 
    // (search_index2 != -1) ? cout << a1[search_index2] << " is at index: " << search_index2 : cout <<"The element was not found!";

    
    // my_array<string> a2(5, 4); // creating an array of strings
    // a2.set();
    // a2.print();
    return 0;
}