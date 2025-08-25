#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // A priority queue is a special type of queue where the highest-priority element 
    // is always at the front — not necessarily the first one inserted.
    // In C++, std::priority_queue is a container-adapter (like queue and stack) built 
    // on top of a heap (by default, a max-heap using std::vector).

    priority_queue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.emplace(5);

    cout << "Top: " << pq.top() << "\n"; // 30

    pq.pop();
    cout << "New Top: " << pq.top() << "\n"; // 20

    // You can also use min-heap instead. Use a custom comparator:
    priority_queue<int, vector<int>, greater<int>> minHeap;

    return 0;
}