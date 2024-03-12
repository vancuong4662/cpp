#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool VectorCheckIn(const vector<int>& vec, int number) {
    auto it = find(vec.begin(), vec.end(), number);
    return it != vec.end();
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    int numToCheck = 3;
    if (VectorCheckIn(numbers, numToCheck)) {
        cout << numToCheck << " nằm trong vector." << endl;
    } else {
        cout << numToCheck << " không nằm trong vector." << endl;
    }

    numToCheck = 6;
    if (VectorCheckIn(numbers, numToCheck)) {
        cout << numToCheck << " nằm trong vector." << endl;
    } else {
        cout << numToCheck << " không nằm trong vector." << endl;
    }

    return 0;
}
