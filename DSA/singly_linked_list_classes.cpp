#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class Node{
    private:
        T data;
        unique_ptr<Node> next = nullptr;

    public:
    Node(T data, unique_ptr<Node> next_node_ptr = nullptr) : data(data), next(move(next_node_ptr)) {};

    void print() const {
        cout << "Data: " << data << endl;
        if (next) {
            cout << "Next data: " << next->data << endl;
        } else {
            cout << "Next: nullptr" << endl;
        }
    }

    T get_data(){
        return data;
    }

    void set_next_node(unique_ptr<Node> next_node){
        next = move(next_node);
    }

    Node<T>* get_next_node() {
        return next.get();
    }

    void traversel() {
        Node* n = this;
        while(n != NULL){
                cout << "Data: " << n->data << endl;
                n = n->next.get();
        }
    }
};

template<typename T, typename N = Node<T>>
class list {
    unique_ptr<N> head = nullptr;
    N* tail = nullptr;
    int list_count = 0;

    public:
        void push(T elem) {
            auto node = make_unique<N>(elem);
            list_count++;

            if (!head) {
                head = move(node);
                tail = head.get();
            } else {
                tail->set_next_node(move(node));
                tail = tail->get_next_node();
            }
        }

        void pop() {
            if (!head) {
                cout << "The list is empty!" << endl;
            } else {
                tail = nullptr;
                N* n = head.get();
                while(n != NULL){
                        tail = n;
                        n = n->get_next_node();
                }
                list_count--;
            }
        }

        void print_list() const {
            if (!head) {
                cout << "List is empty." << endl;
                return;
            }
            N* node = head.get();
            cout << "{";
            for (int i = 0; i < list_count; i++) {
                if (i > 0) cout << ","; // Print comma before every element except the first
                cout << node->get_data();
                node = node->get_next_node();
            }
            cout << "}" << endl;
        }
};

int main(){
    // auto head = make_unique<Node<int>>(1);
    // auto n1 = make_unique<Node<int>>(2);
    // auto n2 = make_unique<Node<int>>(3);
    // auto n3 = make_unique<Node<int>>(4);

    // head->set_next_node(std::move(n1));
    // head->get_next_node()->set_next_node(std::move(n2));
    // head->get_next_node()->get_next_node()->set_next_node(std::move(n3));

    // head->traversel();

    list<int> l1;
    l1.push(1);
    l1.push(2);
    l1.push(3);
    l1.push(3);
    l1.push(4);
    l1.print_list();
    l1.pop();
    l1.print_list();

    return 0;
}