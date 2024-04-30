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

  int r, c;
  cin >> r >> c;

  vector<vector<string>> binary(c, vector<string>(r, "0"));

  rep(i, r)rep(j, c){
    cin >> binary[j][i];
  }

  vector<int> binary_int(c);

  rep(i, c){
    string s = "";
    rep(j, r){
      s.append(binary[i][j]);
    }
    binary_int[i] = stoi(s, nullptr, 2);
  }

  ll result = 0;

  rep(bit, 1<<r){
    ll sum = 0;
    rep(i, c){
      unsigned int binary_c = bit ^ binary_int[i];
      int count = popcount(binary_c);
      int max_count = max(r - count, count);
      sum += max_count;
    }
    result = max(result, sum);
  }

  cout << result << endl;

  // ここまで
  return 0;
}
