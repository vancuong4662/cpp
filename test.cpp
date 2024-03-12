#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void printVector(vector<int> a) {
    cout << "Vector: (";
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

void vectorCopy(vector<int>& a, const vector<int>& b) {
    // Xóa toàn bộ phần tử của vector a
    a.clear();

    // Sao chép từ vector b sang vector a
    copy(b.begin(), b.end(), back_inserter(a));
}

bool VectorCheckIn(const vector<int>& vec, int number) {
    auto it = find(vec.begin(), vec.end(), number);
    return it != vec.end();
}

// Hàm biến đổi dãy số
void transform(vector<int>& numbers, int& transformations) {
    
    vector<int>origins;
    vectorCopy(origins,numbers);
    
    vector<int>checkeds;
    
    cout<<"Ori ";
    printVector(origins);
    
    int n = numbers.size();
    for (int i = 0; i < n; ++i) {
        if (VectorCheckIn(numbers,i)) continue;
        for (int j = i + 1; j < n; ++j) {
            if (i == j) continue;
            if (VectorCheckIn(numbers,j)) continue;
            int a = numbers[i];
            int b = numbers[j];
            for (int k = 2; k < min(a, b); ++k) {
                if (a % k == 0 && a != k) {
                    // Tìm thấy số nguyên tố k thỏa mãn
                    cout << "Pick a="<<a<<", b="<<b<<"\n";
                    numbers[i] = a / k;
                    numbers[j] = b * k;
                    ++transformations;
                    cout<<"Transform to ";
                    printVector(numbers);
                    
                    int checkGCD = greatestCommonDivisor(numbers);
                    if (checkGCD != 1) {
                        cout<<"Final ";
                        printVector(numbers);
                        return; // Thỏa mãn, kết thúc
                    } else {
                        cout<<"GCD is 1. Continue to transform";
                        checkeds.push_back(i);
                        checkeds.push_back(j);
                        cout<<"Checked position ";
                        printVector(checkeds);
                        
                        if (checkeds.size() == numbers.size()) {
                            cout<<"\nNot found any result";
                        }
                        return;
                    }
                }
            }
        }
        cout << "________\n";
        vectorCopy(numbers,origins);
        cout<<"reset ";
        printVector(numbers);
    }
    return false;
}


// Hàm tính ước chung lớn nhất của dãy số
int greatestCommonDivisor(const vector<int>& numbers) {
    int gcd = numbers[0];
    for (int i = 1; i < numbers.size(); ++i) {
        gcd = __gcd(gcd, numbers[i]);
        if (gcd == 1) return 1; // Nếu gcd đã bằng 1, không cần kiểm tra tiếp
    }
    return gcd;
}

int main() {
    cout << "Hello ? "  << endl;
    vector<int> numbers = {4,5,6,7,8};
    int transformations = 0;
    
    

    // Biến đổi dãy số
    transform(numbers, transformations);
    cout << "Finish transforming"  << endl;
    
    

    // Tìm ước chung lớn nhất
    int gcd = greatestCommonDivisor(numbers);

    cout << "Số lần biến đổi ít nhất: " << transformations  << endl;
    cout << "Ước chung lớn nhất của dãy: " << gcd << endl;

    return 0;
}
