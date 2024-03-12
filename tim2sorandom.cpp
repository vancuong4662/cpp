/*
Đề bài : Nhập vào 1 dãy số nguyên. Hãy tìm ra 2 số ngẫu nhiên trong dãy và in ra.
*/
#include <iostream>
#include <vector>
#include <cstdlib> // For rand() function
#include <ctime>   // For time()

using namespace std;

// Hàm để chọn ra hai số ngẫu nhiên khác nhau từ dãy số
pair<int, int> selectTwoRandomIndices(int size) {
    int index1 = rand() % size;
    int index2;
    do {
        index2 = rand() % size;
    } while (index2 == index1);
    return make_pair(index1, index2);
}

int main() {
    int n;
    cout << "Nhập số lượng phần tử trong dãy số: ";
    cin >> n;

    // Khởi tạo generator số ngẫu nhiên với seed là thời gian hiện tại
    srand(time(0));

    vector<int> arr(n);
    cout << "Nhập dãy số:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Phần tử thứ " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Chọn ra 2 chỉ số ngẫu nhiên từ dãy số, đảm bảo chúng khác nhau
    pair<int, int> indices = selectTwoRandomIndices(n);
    int index1 = indices.first;
    int index2 = indices.second;

    // In ra 2 số đã chọn
    cout << "Số thứ nhất được chọn: " << arr[index1] << endl;
    cout << "Số thứ hai được chọn: " << arr[index2] << endl;

    return 0;
}
