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
  vector<int> x(m);
  REP(i, m)
  cin >> x[i];
  REP(i, m)
  x[i] -= 1;

  vector<ll> path_cost(n);
  REP(i, m - 1)
  {
    int island = x[i];
    int next_island = x[i + 1];
    if (island > next_island)
    {
      island = x[i + 1];
      next_island = x[i];
    }

    int one_cost = abs(next_island - island);
    int another_cost = abs(n - one_cost);

    if (island != 0)
    {
      path_cost[0] += one_cost;
      path_cost[island] += another_cost - one_cost;
      path_cost[next_island] += one_cost - another_cost;
    }
    else
    {
      path_cost[island] += another_cost;
      path_cost[next_island] += one_cost - another_cost;
    }
  }

  // 累積和を取る
  FOR(i, 1, n)
  {
    path_cost[i] += path_cost[i - 1];
  }

  cout << *min_element(ALL(path_cost)) << endl;

  // ここまで
  return 0;
}
