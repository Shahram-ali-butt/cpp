#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

void mutiset(); // Multiset is explained in a separate function
void unorderedset(); // Unordered set is explained in a separate function

int main(){
    // sets are sorted automatically in ascending order.
    // Are unique, Can be added or removed, but the value of an existing element cannot be changed.
    // Cannot be accessed by indexing, because the order is based on sorting and not indexing.

    set<int> s1;
    s1.insert(2);
    s1.insert(10);
    s1.insert(1);
    s1.emplace(1); // Won't insert
    s1.insert(3);

    // **************************** Remove elements ********************************
    s1.erase(3);
    s1.clear(); //Removes al elements

    // Other Functions like size(), empty(), begin(), end() are the same as vectors

    // ************************ sort in descending order *************************** 
    set<int, greater<int>> s2;
    s2 = {1,4,10,2,8,4,4,9,3,5,6,7,8}; // This will be sorted in descending order and deplicates will be removed

    // *********************** Finding Elemnts in sets ****************************
    auto iterator = s2.find(4); // returns the iterator pointing at 4
    // If the elem is not in the set it would point to s1.end() which is the memory location
    // just after the last element 
    auto iter = s2.find(16); 
    
    // *************************** Deleting elements ******************************
    s2.erase(4); // deletes 4 and maintains the sorted order -> Logarithmic Time
    s2.erase(iterator); // You can also give the iterator -> constant time
    auto it1 = s2.find(2); 
    auto it2 = s2.find(5); 
    s2.erase(it1, it2); // You can also give 2 iterators but the second is exclusive

    // ************************* Lower and upper bound *****************************
    set<int> s = {10, 20, 30, 40, 50};

    auto lb = s.lower_bound(25); // returns an iterator and points to 30
    auto ub = s.upper_bound(30); // points to 40

    cout << "Lower bound of 25: " << *lb << "\n";
    cout << "Upper bound of 30: " << *ub << "\n";

    return 0;
}

void mutiset(){
    // Everything is same as sets but they can store duplicates
    multiset<int> ms;
    ms.insert(10);
    ms.emplace(10);
    ms.insert(20);
    ms.insert(20);
    ms.insert(30);
    // ms = {10, 10, 20, 20, 30}

    ms.erase(10); // All instances of 10 will be erased
    ms.erase(ms.find(10)); // Only one instance of 10 will be erased
    ms.erase(ms.find(10), std::next(ms.find(10), 2)); // You could also give a range 
    // ms.erase(ms.find(10), ms.find(10) + 2); // Not allowed

    int no_of_20 = ms.count(20); // return 2
}

void unorderedset(){
    // Unordered sets are unique but they are not sorted.
    // All the elements are placed randomly in a unordered set.
    // upper_bound() and lower_bound() don't work other than that 
    // all the functions are the same as sets.

    unordered_set <int> uset;
    uset.insert(10);
    uset.insert(5);
    uset.insert(20);
    uset.insert(5); // This will not be inserted as 5 already exists

}