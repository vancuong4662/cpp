#include <iostream>
#include <vector>
#include <algorithm> // for std::copy

using namespace std;

// Hàm thực hiện xóa toàn bộ phần tử của vector a và sao chép từ vector b sang a
void vectorCopy(vector<int>& a, const vector<int>& b) {
    // Xóa toàn bộ phần tử của vector a
    a.clear();

    // Sao chép từ vector b sang vector a
    copy(b.begin(), b.end(), back_inserter(a));
}

int main() {
    // Khai báo và khởi tạo vector a và b
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {5, 6, 7, 8, 9};

    // Hiển thị vector a và b trước khi thực hiện thao tác
    cout << "Vector a ban đầu:";
    for (const auto& element : a) {
        cout << " " << element;
    }
    cout << endl;

    cout << "Vector b ban đầu:";
    for (const auto& element : b) {
        cout << " " << element;
    }
    cout << endl;

    // Gọi hàm để xử lý sao chép và xóa
    vectorCopy(a, b);

    // Hiển thị vector a sau khi thực hiện thao tác
    cout << "Vector a sau khi sao chép từ b:";
    for (const auto& element : a) {
        cout << " " << element;
    }
    cout << endl;

    return 0;
}
