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

  int x, t;
  cin >> x >> t;

  int result = x - t > 0 ? x - t : 0;

  cout << result << endl;

  // ここまで
  return 0;
}
