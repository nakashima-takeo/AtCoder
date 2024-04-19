#include <bits/stdc++.h>
using namespace std;
using long long ll;
using unsigned long long ull;
using long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n), end(n)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n;
  cin >> n;
  vector<int> a(n - 1);
  REP(i, n - 1)
      cin >> a[i];

  int result = accumulate(ALL(a), 0) * (-1);

  cout << result << endl;

  // ここまで
  return 0;
}
