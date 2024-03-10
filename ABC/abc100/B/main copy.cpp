#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int d, n;
  cin >> d >> n;
  switch (d)
  {
    case 0:
      if (n < 100){
        cout << n << endl;
      } else {
        cout << n + 1 << endl;
      }
      break;
    case 1:
      if (n < 100){
        cout << 100 * n << endl;
      } else {
        cout << 100 * (n + 1) << endl;
      }
      break;
    case 2:
      if (n < 100){
        cout << 10000 * n << endl;
      } else {
        cout << 10000 * (n + 1) << endl;
      }
      break;
  }
}

