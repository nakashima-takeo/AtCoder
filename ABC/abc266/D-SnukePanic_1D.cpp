#include<iostream>
#include<vector>
#include<tuple>
#include<vector>
using namespace std;
// 貪欲法では解けない。（単調性がない）

int main(){
    int n;
    cin >> n;
    vector<tuple<int, int, int>> sunuke(n);
    for (int i = 0; i < n; i++)
    {
        int t,x,a;
        cin >> t >> x >> a;
        sunuke[i] = make_tuple(t,x,a);
    }

    vector<vector<long long>> maxVolume(n + 1, vector<long long>(5, -1));
    int a = 0;
    maxVolume[0][0] = 0;
    int timeSpace = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1){
            timeSpace = get<0>(sunuke[i - 1]);
        } else {
            timeSpace = get<0>(sunuke[i - 1]) - get<0>(sunuke[i - 2]);
        }
        for (int now = 0; now < 5; now++)
        {
            for (int previous = 0; previous < 5; previous++)
            {
                if (maxVolume[i - 1][previous] == -1){
                    continue;
                }
                if (abs(now - previous) <= timeSpace){
                    if (now == get<1>(sunuke[i - 1])){
                        if (maxVolume[i - 1][previous] + get<2>(sunuke[i - 1]) > maxVolume[i][now]){
                            maxVolume[i][now] = maxVolume[i - 1][previous] + get<2>(sunuke[i - 1]);
                        }
                    } else {
                        if (maxVolume[i - 1][previous] > maxVolume[i][now]){
                            maxVolume[i][now] = maxVolume[i - 1][previous];
                        }
                    }
                }
            }
        }
    }
    long long result = 0;
    for (auto &&hole : maxVolume[n])
    {
        if (hole > result) result = hole;
    }
    cout << result << endl;
    return 0;
}
