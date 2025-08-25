#include <iostream>
#include <deque>
using namespace std;

int main(){
    // Again similar to Vectors and lists but with difference in internal working
    deque<int> dq1;
    dq1 = {1,2,3,4,5,6,7,8};
    
    // ******************* Adding Elemets ******************
    // Lists are bidirectional. Elemnts can be added or removed 
    // from both the front or back.
    dq1.push_back(9);
    dq1.emplace_back(10);

    dq1.push_front(0);
    dq1.emplace_front(-1);

    dq1.pop_front();
    dq1.pop_back();
    
    // ****************** Other Functions ******************
    // Rest of the functions are same as vectors
    // e.g. begin(), end(), clear(), insert(), size(), swap() 

// *********************************************************
    // **Additional information:
    // - Sequence of memory blocks (not fully contiguous)
    // - Supports fast insertions/removals at both ends
    // - Indexing is allowed (dq[i]), but slightly slower than vector

    // ✅ Use When
    // - You need fast access at both ends
    // - You want indexing and flexibility

    return 0;
}