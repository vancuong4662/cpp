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
        for (int j = x; j < y + k; j++)
        {

            kq[x - j][y - i] = a[i][j];
        }
    }
    return kq;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> b(3, vector<int>(3));
    b = tachhinhvuong(a, 2, 1, 3);
    coutmt(b);
    return 0;
}