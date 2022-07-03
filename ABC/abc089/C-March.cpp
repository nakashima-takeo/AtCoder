#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> march(5, 0);
    string s;
    char moji;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        moji = s[0];
        if (moji == 'M') march[0]++;
        else if (moji == 'A') march[1]++;
        else if (moji == 'R') march[2]++;
        else if (moji == 'C') march[3]++;
        else if (moji == 'H') march[4]++;
    }
    long long ans = 0;
    // 組み合わせ計算
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                ans += march[i] * march[j] * march[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}