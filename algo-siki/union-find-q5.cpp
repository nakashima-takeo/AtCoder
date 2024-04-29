#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)


int findRoot(vector<int> &parent, int a){
  if(parent[a] == -1) return a;
  else return parent[a] = findRoot(parent, parent[a]);
}

int main(void)
{
  int n, q;
  cin >> n >> q;

  vector<int> par(n, -1);
  vector<ll> weight(n, 0);
  rep(i, n) cin >> weight[i];

  rep(i, q){
    int t, x, y;
    cin >> t >> x >> y;
    int rootX, rootY;
    if(t == 0){
      rootX = findRoot(par, x);
      rootY = findRoot(par, y);
      if(rootX != rootY){
        par[rootX] = rootY;
        weight[rootY] += weight[rootX];
      }
    } else {
      rootX = findRoot(par, x);
      cout << weight[rootX] << endl;
    }
  }

  return 0;
}
