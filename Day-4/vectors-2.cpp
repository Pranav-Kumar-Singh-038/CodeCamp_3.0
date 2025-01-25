#include <iostream>
#include <vector>
using namespace std;

int main() {
    // head : 0, 2
    // Declare a vector of pairs to represent segments of a snake's tail
    vector<pair<int, int>> tail = {{0,2},{0,1},{0,0},{1, 2}};

    cout << "Snake's tail segments:" << endl;

    // Range-based for loop to iterate through each segment
    for (auto segment : tail) {
        cout << "Segment at: (" << segment.first << ", " << segment.second << ")" << endl;
    }

    return 0;
}
