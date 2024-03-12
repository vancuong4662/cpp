#include <iostream>
#include <vector>

using namespace std; // Sử dụng namespace std cho toàn bộ chương trình

void print_a_vector(vector<int> a) {
    cout << "\nVector: (";
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i != n-1) {
            cout << ", ";
        } else {
            cout << ")\n";
        }
    }
}

int main() {
    // Khởi tạo một vector
    vector<int> a = {1, 2, 3, 4, 5};

    print_a_vector(a);

    return 0;
}
