#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  ll a, b;
  cin >> a >> b;
  ll ans = (a+b-1)/b;
  cout << ans << endl;

  return 0;
}
