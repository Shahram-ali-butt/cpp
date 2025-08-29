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

        void set() const {
            T n;
            for(int i = 0; i < used_size; i++){
                cout << "Enter element you want to add to the array #" << i <<" : ";
                cin >> n;
                ptr[i] = n; 
            }
        }

        void get(int index) const {
            if(index >= used_size){
                cout << "There is no element at index: " << index << endl;
            }else{
                cout << ptr[index] << endl;
            }
        }
        
        int get_used_size() const{
            return used_size;
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
            if(index >= used_size){
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
    };
    

int main(){
    my_array<int> a1(20, 3);
    a1.set();
    // a1[2] = 16;
    // int x = a1[2];
    // cout << a1[2] << endl;
    // cout << x << endl;
    a1.print();
    a1.del(1); // won't run for const object
    // insert() won't work with const object
    // a1.insert(3, 3); 
    a1.print();
    // a1.get(5);
    // int position = a1.linear_search(2);
    // (position != -1) ? cout << a1[position] << " is at index: " << position : cout <<"The element was not found!";

    // my_array<string> a2(5, 4);
    // a2.set();
    // a2.print();
    return 0;
}