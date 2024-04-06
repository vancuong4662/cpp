#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void coutmt(vector<vector<int>> a)
{
    for (vector<int> i : a)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

vector<vector<int>> tachhinhvuong(vector<vector<int>> a, int x, int y, int k)
{
    vector<vector<int>> kq(k, vector<int>(k));
    for (int i = y; i < y + k; i++)
    {
        for (int j = x; j < x + k; j++)
        {
            kq[i - y][j - x] = a[i][j]; // Sửa chỉ số ở đây
        }
    }
    return kq;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> b(3, vector<int>(3));
    b = tachhinhvuong(a, 1, 2, 3); // Sửa chỉ số ở đây
    coutmt(b);
    return 0;
}
