#include <iostream>
using namespace std;

template <typename T>
class Node{
private:
    T data;
    Node* next = nullptr;
public:
    Node(T data, Node* next_node = nullptr) : data(data), next(next_node) {};
    ~Node(){ delete next; };

    void print() const{
        cout << data << endl;
        cout << next << endl;
    }
};

int main(){
    Node<int> head(1);
    head.print();
    
    return 0;
}