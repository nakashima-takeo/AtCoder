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

  int n, m;
  cin >> n >> m;

  vector<set<int>> keyOfLight(m);
  rep(i, m){
    int k;
    cin >> k;
    rep(j, k) {
      int s;
      cin >> s;
      s--;
      keyOfLight[i].insert(s);
    }
  }

  vector<int> p(m);
  rep(i, m) cin >> p[i];
  int answer = 0;

  rep(bit, 1<<n){
    vector<int> result(m);
    rep(i, n){
      if(bit & (1 << i)){
        rep(j, m){
          if(keyOfLight[j].contains(i)) result[j]++;
        }
      }
    }
    rep(i, m){
      if(p[i] != result[i] % 2) break;
      if(i == m-1) {
        answer++;
      }
    }
  }
  cout << answer << endl;
  // ここまで
  return 0;
}
