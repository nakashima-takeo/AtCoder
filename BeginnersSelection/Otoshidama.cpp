#include<iostream>
using namespace std;

int MaxCount(int faceValue, int yen);

int main()
{
    int n, yen;
    cin >> n >> yen;
    for (int i = 0; i <= MaxCount(10000, yen); i++)
    {
        for (int j = 0; j <= MaxCount(5000, yen - i * 10000); j++)
        {
            int k = (yen - i * 10000 - j * 5000) / 1000;
            if (i + j + k == n)
            {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}

int MaxCount(int faceValue, int yen)
{
    return (int)yen / faceValue;
}