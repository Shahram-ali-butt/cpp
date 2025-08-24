#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    // stack is a container adapter in C++ that provides Last-In, First-Out 
    // (LIFO) access to elements.
    // It’s not a standalone container — it wraps around other containers like 
    // deque or vector to provide stack-like behavior.

    stack<int> st;
    st.push(1);
    st.emplace(2);
    st.pop();

    cout << st.top() << endl;

    st.size();
    st.empty();

    stack<int> st2;
    st.swap(st2);

    // ************************* Under The Hood ********************************
    // By default, std::stack uses std::deque as its underlying container:
    stack<int, deque<int>> s;

    // You can also use vector:
    stack<int, vector<int>> s1;
    // But you can’t access elements other than the top — no iterators, no indexing.
    // It’s intentionally restrictive to enforce LIFO behavior.

    return 0;
}
