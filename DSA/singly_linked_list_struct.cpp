#include <iostream>
#include <memory>
using namespace std;

struct Node{
    int data;
    unique_ptr<Node> ptr = nullptr;

    Node(int data) : data(data) {}

    void set_data(int d){
        data = d;
    
    }
    int get_data(){
        return data;
    }

    void set_next(unique_ptr<Node> pointer){
        ptr = move(pointer);
    }

    void traversel(){
        Node* n = this;
        if(n){
            while(n != NULL){
                cout << n->get_data() << endl;
                n = n->ptr.get(); 
            }
        }else{
            cout << "List is empty" << endl;
        }
    }
};


int main(){
    auto head = make_unique<Node>(1);
    auto n2 = make_unique<Node>(2);
    auto n3 = make_unique<Node>(3);
    auto n4 = make_unique<Node>(4);

    n3->ptr = move(n4);
    n2->set_next(move(n3));
    head->ptr = move(n2);

    head->traversel();
    return 0;
}