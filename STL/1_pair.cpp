#include <iostream>
#include <utility>
using namespace std;

int main(){   
    pair<int, int> p1= {21, 22};
    // cout << p1.first << endl;
    // cout << p1.second << endl;

    pair <char, int> b; // declartion before initializing later
    b = make_pair('B', 'c'); // type conversion of c would happen
    b.second = 23; // changing an entry
    // cout << b.first << " " << b.second << endl;

    // nested pairs
    pair <int, pair <int, int>> three_vals = {1 , {2, 3}};
    // cout << three_vals.first << " " << three_vals.second.first 
    //      << " " << three_vals.second.second << endl;
    
    // array of pairs
    pair<int, int> pair_arr[3] = {{1,2}, {3,4}, {5,6}};
    int two_dimensional_arr[][2] = {{1,2}, {3,4}, {5,6}}; // another way would have been using 2D array
    cout << pair_arr[0].first << endl;
    cout << two_dimensional_arr[0][0] << endl;

    return 0;
}