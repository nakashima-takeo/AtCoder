#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int n,m;
    cin >> n;
    vector<string> nStr(n);
    for (int i = 0; i < n; i++) cin >> nStr[i];
    cin >> m;
    vector<string> mStr(m);
    for (int i = 0; i < m; i++) cin >> mStr[i];
    map<string,int> nMap;
    map<string,int> mMap;
    for (int i = 0; i < n; i++) nMap[nStr[i]]++;
    for (int i = 0; i < m; i++) mMap[mStr[i]]++;
    int ans = 0;
    for (auto itr = nMap.begin(); itr != nMap.end(); ++itr)
    {
        if (mMap.find(itr->first) != mMap.end())
        {
            if (itr->second - mMap.find(itr->first)->second > ans)
            {
                ans = itr->second - mMap.find(itr->first)->second;
            }
        }
        else if (itr->second > ans)
        {
            ans = itr->second;
        }
    }
    cout << ans << endl;
}