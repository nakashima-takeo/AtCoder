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

const int INF = 107374182;

struct Search {
  int cost = 0;
  int searched_index = -1;
};

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  string t;
  cin >> t;
  int n;
  cin >> n;

  multimap<int,string> moji_box;

  rep(i, n){
    int k;
    cin >> k;
    rep(j, k){
      string s;
      cin >> s;
      moji_box.emplace(i, s);
    }
  }

  vector<vector<int>> dp(n+1, vector<int>(t.size()+1, INF));
  dp[0][0] = 0;

  rep(i, n){
    auto range = moji_box.equal_range(i);
    int min_cost = 0;
    rep(j, t.size()+1) dp[i+1][j] = dp[i][j];
    rep(j, t.size()+1){
      if(dp[i][j] == INF) continue;
      for(auto it = range.first; it != range.second; ++it){
        string s = it->second;
        // 配るDP
        if(s == t.substr(j, s.size())){
          dp[i+1][j+s.size()] = min(dp[i+1][j+s.size()], dp[i][j]+1);
        }
      }
    }
  }

  if(dp[n][t.size()] == INF) cout << -1 << endl;
  else cout << dp[n][t.size()] << endl;
  // ここまで
  return 0;
}
