#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

void multi_map(); // Multimaps are explained below in a separate function 
void unorderedmap(); // Unordered are explained below in a separate function 

int main()
{
    // A std::map is an associative container that stores key-value pairs 
    // in sorted order (ascending order) by key. Keys are unique

    map<int, string> m;

    // Insert
    m.insert({1, "A"});
    m.emplace(2, "B"); // Note we didn't use braces to create a pair
    m[3] = "C"; // Also inserts if key doesn't exist

    // Access
    // std::cout << m[1] << endl; // "A"
    // std::cout << m.count(2) << endl; // 1

    // Search
    if (m.find(3) != m.end()) {
        // std::cout << "Found key 3" << endl;
    }

    // Erase
    m.erase(2);

    // Iterate
    for (auto [key, value] : m) {
        cout << key << ": " << value << "\n";
    }

    for(auto elem : m){
        // cout << elem.first << " " << elem.second << endl;
    }

    return 0;
}

void multi_map(){
    // Same as map but can store duplicate keys
    // Cannot use square bracket syntax

    multimap<int, string> m;

    // Insert
    m.insert({1, "A"});
    m.emplace(2, "B"); // Note we didn't use braces to create a pair
    // m[3] = "C"; // Illegal operation
    m.insert({3, "C"});
    m.insert({3, "C"});
    m.insert({3, "C"});

    m.erase(3); // Erases All instances of 3
    m.erase(m.find(3)); // Erases only one instance of 3
}

void unorderedmap(){
    // Most commonly used container
    // Same as map but stores unordered keys
    // Unique Keys and random in order
    unordered_map<int, char> m;
}