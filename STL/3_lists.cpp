#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> ls1;
    ls1 = {1,2,3,4,5,6,7,8};
    
    // ******************* Adding Elemets ******************
    // Lists are bidirectional. Elemnts can be added or removed 
    // from both the front or back.
    ls1.push_back(9);
    ls1.emplace_back(10);

    ls1.push_front(0);
    ls1.emplace_front(-1);

    ls1.pop_front();

    // ****************** Other Functions ******************
    // Rest of the functions are same as vectors
    // e.g. begin(), end(), clear(), insert(), size(), swap() 

    return 0;
}