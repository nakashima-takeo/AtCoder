#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int m,a,r,c,h;
    string s;
    char moji;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        moji = s[0];
        if (moji == 'M') m++;
        else if (moji == 'A') a++;
        else if (moji == 'R') r++;
        else if (moji == 'C') c++;
        else if (moji == 'H') h++;
    }
    long long ans;
    // 組み合わせ計算
    cout << ans << endl;
    return 0;
}