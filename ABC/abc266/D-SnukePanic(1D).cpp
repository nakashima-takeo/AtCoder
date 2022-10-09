#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

int main(){
    int n;
    long long maxVolume;
    cin >> n;
    vector<tuple<int, int, int>> sunuke(n);
    for (int i = 0; i < n; i++)
    {
        int t,x,a;
        cin >> t >> x >> a;
        sunuke[i] = make_tuple(t,x,a);
    }
    
    return 0;
}