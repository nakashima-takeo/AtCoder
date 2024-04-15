#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n;
  cin >> n;
  vector<ll> a(3 * n);
  REP(i, 3 * n) cin >> a[i];

  sort(ALL(a), greater<ll>());

  ll sum = 0LL;
  for (int i = 1; i < 2*n; i += 2)
  {
    sum += a[i];
  }

  cout << sum << endl;

  // ここまで
  return 0;
}
