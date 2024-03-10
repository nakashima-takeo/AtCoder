#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int d, n, result;
  cin >> d >> n;
  if (n < 100)
  {
    result = pow(100, d) * n;
  }
  else
  {
    result = pow(100, d) * (n + 1);
  }
  cout << result << endl;
}
