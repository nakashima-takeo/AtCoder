#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(n) begin(n), end(n)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n;
  cin >> n;

  int amari = n % 10;
  if (amari <= 2 ) cout << n - amari << endl;
  if (amari > 2 && amari < 8) cout << n - amari + 5 << endl;
  if (amari >= 8) cout << n - amari + 10 << endl;

  // ここまで
  return 0;
}
