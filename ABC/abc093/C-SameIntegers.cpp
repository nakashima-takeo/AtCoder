#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MinimumRepeatTimes(vector<int>& v)
{
    int count = 0;
    while (v[0] != v[1] || v[1] != v[2])
    {
        sort(v.begin(), v.end(), greater<int>());
        if(v[0] > v[1])
        {
            int tempCount = 0;
            tempCount = v[0] - v[1];
            v[1] += tempCount;
            v[2] += tempCount;
            count += tempCount;
        }
        if (v[1] > v[2])
        {
            int tempCount = 0;
            tempCount += (v[1] - v[2]) % 2 == 0 ? (v[1] - v[2]) / 2 : (v[1] - v[2]) / 2 + 1;
            v[2] += tempCount * 2;
            count += tempCount;
        }
    }
    return count;
}

int main()
{
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    cout << MinimumRepeatTimes(v) << endl;
    return 0;
}