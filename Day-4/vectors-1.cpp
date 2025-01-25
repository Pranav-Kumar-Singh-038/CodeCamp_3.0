#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declare a vector of pairs
    int arr[3][3];
    vector<pair<int, int>> vec;
// {{1,2},{34,4},{5,6}}
    // Add some pairs to the vector
    vec.push_back({1, 2});
    vec.push_back({3, 4});
    vec.push_back({5, 6});

    // Print all pairs in the vector
    cout << "Contents of the vector:" << endl;
    for (const auto& p : vec) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    // Access individual elements
    cout << "\nAccessing individual elements:" << endl;
    cout << "First pair: (" << vec[0].first << ", " << vec[0].second << ")" << endl;
    cout << "Second pair: (" << vec[1].first << ", " << vec[1].second << ")" << endl;

    // Modify a pair in the vector
    vec[1] = {7, 8};
    cout << "\nAfter modifying the second pair:" << endl;
    for (const auto& p : vec) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    // Size of the vector
    cout << "\nSize of the vector: " << vec.size() << endl;

    return 0;
}
