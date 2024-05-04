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

  string s, t;
  cin >> s >> t;

  vector<int> result;
  int s_index = 0;

  rep(i, t.length()){
    if(s[s_index] == t[i]){
      result.push_back(i);
      s_index++;
    }
    if(s_index == s.length()) break;
  }

  rep(i, result.size()){
    if(i != result.size() - 1){
      cout << result[i]+1 << " ";
    } else {
      cout << result[i]+1 << endl;
    }
  }

  // ここまで
  return 0;
}
