#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m; long long t;
    cin >> n >> m >> t;
    vector<int> an(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> an[i];
    }
    vector<int> x(m + 1);
    vector<int> y(m + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> x[i] >> y[i];
    }
    x[m] = 0;
    y[m] = 0;
    int xLocator = 0;
    for (int place = 1; place < n; place++)
    {
        if (x[xLocator] == place){
            t += y[xLocator];
            xLocator++;
        }
        t -= an[place - 1];
        if (t <= 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}