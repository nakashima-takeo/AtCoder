#include <iostream>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        while(true){
            if (a[j] >= b[i]){
                c[j] += b[i];
                j++;
                j = j % n;
                break;
            }else{
                b[i] -= a[j];
                c[j] += a[j];
                j++;
                j = j % n;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << endl;
    }
}