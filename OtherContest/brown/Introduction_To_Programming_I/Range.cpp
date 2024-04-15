#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  int a, b, c;
  cin >> a >> b >> c;

  if(a < b && b < c) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
