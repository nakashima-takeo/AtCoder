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

  vector<int> q(n);
  vector<int> a(n);
  vector<int> b(n);

  REP(i, n)
  {
    cin >> q[i];
  }
  REP(i, n)
  {
    cin >> a[i];
  }
  REP(i, n)
  {
    cin >> b[i];
  }

  int max_iterate_a = 1000000;

  REP(i, n)
  {
    if (a[i] != 0)
    {
      int devide_number_a = static_cast<int>(q[i] / a[i]);
      max_iterate_a = min(max_iterate_a, devide_number_a);
    }
  }

  int max_dishes = 0;

  for (int i = max_iterate_a; i >= 0; i--)
  {
    int max_iterate_b = 1000000000;
    REP(k, n)
    {
      if (b[k] != 0)
      {
        int devide_number_b = static_cast<int>((q[k] - a[k] * i) / b[k]);
        if (devide_number_b < 0)
          break;
        max_iterate_b = min(max_iterate_b, devide_number_b);
      }
    }
    max_dishes = max(max_dishes, i + max_iterate_b);
  }

  cout << max_dishes << endl;

  // ここまで
  return 0;
}
