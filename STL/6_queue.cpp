#include <iostream>
#include <queue>
using namespace std;

int main() {
    // queue is a container-adapter (just like stack) that gives you FIFO behavior. 
    // It wraps around other containers (like std::deque or std::list) to enforce 
    // queue semantics — no random access, no iterators, just enqueue and dequeue.

    queue<int> q;

    q.push(100);
    q.push(200);
    q.push(300);
    q.emplace(400);

    cout << "Front: " << q.front() << "\n"; // 100
    cout << "Back: " << q.back() << "\n";   // 400

    q.pop(); // removes 100
    cout << "New Front: " << q.front() << "\n"; // 200

    // size() and swap() same as stack

    // ************************* Under The Hood ********************************
    //  By default, std::queue uses std::deque:
    // std::queue<int, std::deque<int>> q;
    // You can also use std::list if needed, but not std::vector, because vectors don’t support efficient front removal.
    
    return 0;
}