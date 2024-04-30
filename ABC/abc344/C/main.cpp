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

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n, m, l;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  cin >> m;
  vector<int> b(m);
  rep(i, m) cin >> b[i];
  cin >> l;
  vector<int> c(l);
  rep(i, l) cin >> c[i];

  set<ll> all_sums;
  rep(i, n)rep(j, m)rep(k, l) all_sums.insert(a[i] + b[j] + c[k]);

  int q;
  cin >> q;
  rep(i, q){
    int x;
    cin >> x;
    if(all_sums.contains(x)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  // ここまで
  return 0;
}
