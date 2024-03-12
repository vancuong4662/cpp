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

// Hàm tìm bội chung nhỏ nhất của 2 số
int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}

// Hàm tìm bội chung nhỏ nhất của dãy số
int findLCMOfArray(const std::vector<int>& arr) {
    int lcm = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        lcm = findLCM(lcm, arr[i]);
    }
    return lcm;
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

    int lcm = findLCMOfArray(arr);
    std::cout << "Bội chung nhỏ nhất của dãy số là: " << lcm << std::endl;

    return 0;
}
