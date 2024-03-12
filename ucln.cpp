#include <iostream>
#include <vector>

// Hàm tìm ước chung lớn nhất của 2 số
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm tìm ước chung lớn nhất của dãy số
int findGCDOfArray(const std::vector<int>& arr) {
    int gcd = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        gcd = findGCD(gcd, arr[i]);
    }
    return gcd;
}

int main() {
    int n;
    std::cout << "Nhập số lượng phần tử trong dãy số: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Nhập dãy số:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Phần tử thứ " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    int gcd = findGCDOfArray(arr);
    std::cout << "Ước chung lớn nhất của dãy số là: " << gcd << std::endl;

    return 0;
}
