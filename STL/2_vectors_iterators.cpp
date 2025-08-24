#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
    vector<int> v1 = {1,2,3,4,4};
    // cout << v1[0] << ", Another method is " << v1.at(0) << endl;
    // cout << v1[6] << endl; //won't throw an error
    // cout << v1.at(6) << endl; // would throw an error

    // ******************** Changing an element **************************
    v1[0] = 2; // changing an element
    v1.at(1) = 3; // changing an element (considered safer)
    // cout << v1[0] << " " << v1.at(1) << endl;

    // ******************** Adding an element ****************************
    v1.push_back(5); // changing the size and pushing 5 at the end
    v1.emplace_back(5); // another syntax for pushing elements at the end
    // cout << v1[5] << " " << v1[6] << endl;

    vector<pair<int, int>> v2;
    v2.push_back({1,2}); // explicitly making it a pair
    v2.emplace_back(1,2); // automatically assumes it a pair
    // cout << v2[0].first << endl;
    // cout << v2[1].first << endl;
    
    // ******************** Removing an Element **************************
    v2.pop_back();// removes an element from end
    // cout << v2.at(1).first << endl;

    // ************** Fill a vector with the same element ****************
    vector<int> v3(5, 100); // Fill the vector with 5 instances of 100
    vector<int> v4(5); // Fill the vector with 5 instances of 0

    vector<int> vec1 = {1,2,3,4};
    vector<int> vec2(vec1); // creates a copy of vec1. Any change in v1 won't be reflected at vec2

// ************************* Iterators *****************************
//  ::iterator is a type alias used to refer to the iterator type defined 
// inside a container class or a class template. It’s part of the nested 
// type system and is accessed using the scope resolution operator ::

// C++ containers (like std::vector, std::list, std::map, etc.) define 
// their own iterator types internally. These iterators are tailored to the
// container’s structure and behavior.

    vector<int> my_vector = {0,1,2,3,4,5,6,7,8,9};
    for(vector<int>::iterator i = my_vector.begin(); i != my_vector.end(); i++){
        // cout << *i << " ";
    }

    vector<int>::iterator iter; // first defining an iter and then using it 
    iter = my_vector.begin(); // Points at my_vector[0]
        // cout << *iter << endl; // Output: 0
        iter = my_vector.end(); // Points at a location just past my_vector[9]
        // cout << *iter << endl; // Outputs A value stored at a location past the location of my_vector[9]
        --iter; // Output: 9
        
    for (iter = my_vector.begin(); iter != my_vector.end(); iter++) {
            // cout << *iter << " ";
    }
        
    // we could also create an iterator of type auto so it would work with every kind of vector
    for(auto i = my_vector.begin(); i != my_vector.end(); i++){
        // cout << *i << " ";
    }
    
    // The for-each loop automatically implements iterator-based approach 
    // (the loop below is absolutely the same as the one above) 
    for(auto it : my_vector){
        // cout << it << " "; // Note that we didn't use *(dereference operator). This is range based not iterator based
    }
    
    // **************************** Deleting elements ************************
    my_vector.erase(my_vector.begin() + 1, my_vector.begin() + 3); // 1 and 2 will be deleted. (econd parameter is exclusive)
    
    // **************************** Inserting elements ***********************
    my_vector.insert(my_vector.begin() + 1, 23); // inserting 23 at my_vector[1]
    my_vector.insert(my_vector.begin() + 2, 2, 24); // inserting two 24 at my_vector[2]

    // ****************** Other functions:
    // v1.clear() // clears a vector
    // v2.size() // returns the size of the vector
    // v1.swap(v2) // swaps the two vectors
    // v2.empty() // return true or false if empty or not

// **********************************************************
    // ***Additional information:
    //  Contiguous memory (like a C-style array)
    //  Supports random access via indexing (vec[i])
    //  Automatically resizes (usually doubles capacity when full)
    
    // ✅ Use When
    //  You need fast access by index
    //  You mostly push/pop at the end
    //  Memory locality matters (cache-friendly)(cause obviously it's contiguous)

    return 0;
}