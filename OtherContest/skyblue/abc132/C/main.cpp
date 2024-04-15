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

  int devider = n / 2;
  vector<int> d(n);
  REP(i, n) cin >> d[i];

  sort(ALL(d));

  int first = d[devider-1];
  int second = d[devider];

  cout << second - first << endl;

  // ここまで
  return 0;
}
