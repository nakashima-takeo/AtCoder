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

  int n, k, m;
  cin >> n >> k >> m;
  vector<int> a(n);
  REP(i, n-1) cin >> a[i];
  int sum = 0;
  for (auto &&i : a) sum += i;

  int pointRequired = n * m - sum;

  if (pointRequired > k) cout << "-1" << endl;
  else if (pointRequired < 0) cout << "0" << endl;
  else cout << pointRequired << endl;
  // ここまで
  return 0;
}
