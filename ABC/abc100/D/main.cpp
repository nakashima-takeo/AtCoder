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

  int n, m;
  cin >> n >> m;
  vector<ll> x(n), y(n), z(n);
  REP(i, n)
  {
    cin >> x[i] >> y[i] >> z[i];
  }

  vector<ll> value_ppp;
  vector<ll> value_ppm;
  vector<ll> value_pmp;
  vector<ll> value_pmm;
  vector<ll> value_mpp;
  vector<ll> value_mpm;
  vector<ll> value_mmp;
  vector<ll> value_mmm;

  REP(i, n)
  {
    value_ppp.push_back(x[i] + y[i] + z[i]);
    value_ppm.push_back(x[i] + y[i] - z[i]);
    value_pmp.push_back(x[i] - y[i] + z[i]);
    value_pmm.push_back(x[i] - y[i] - z[i]);
    value_mpp.push_back(-x[i] + y[i] + z[i]);
    value_mpm.push_back(-x[i] + y[i] - z[i]);
    value_mmp.push_back(-x[i] - y[i] + z[i]);
    value_mmm.push_back(-x[i] - y[i] - z[i]);
  }

  sort(ALL(value_ppp), greater<ll>());
  sort(ALL(value_ppm), greater<ll>());
  sort(ALL(value_pmp), greater<ll>());
  sort(ALL(value_pmm), greater<ll>());
  sort(ALL(value_mpp), greater<ll>());
  sort(ALL(value_mpm), greater<ll>());
  sort(ALL(value_mmp), greater<ll>());
  sort(ALL(value_mmm), greater<ll>());

  vector<ll> result;

  result.push_back(accumulate(value_ppp.begin(), value_ppp.begin() + m, 0LL));
  result.push_back(accumulate(value_ppm.begin(), value_ppm.begin() + m, 0LL));
  result.push_back(accumulate(value_pmp.begin(), value_pmp.begin() + m, 0LL));
  result.push_back(accumulate(value_pmm.begin(), value_pmm.begin() + m, 0LL));
  result.push_back(accumulate(value_mpp.begin(), value_mpp.begin() + m, 0LL));
  result.push_back(accumulate(value_mpm.begin(), value_mpm.begin() + m, 0LL));
  result.push_back(accumulate(value_mmp.begin(), value_mmp.begin() + m, 0LL));
  result.push_back(accumulate(value_mmm.begin(), value_mmm.begin() + m, 0LL));

  sort(ALL(result), greater<ll>());
  cout << result[0] << endl;

  // ここまで
  return 0;
}
