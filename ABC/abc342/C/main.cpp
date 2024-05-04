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

  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  vector<char> code(26);
  const string alfabet = "abcdefghijklmnopqrstuvwxyz";
  rep(i, 26){
    code[i] = alfabet[i];
  }
  rep(i, q){
    char c, d;
    cin >> c >> d;
    rep(i, 26){
      if(code[i] == c) code[i] = d;
    }
  }

  string new_s = "";
  rep(i, n){
    rep(j, 26){
      if(s[i] == alfabet[j]){
        new_s += code[j];
        break;
      }
    }
  }
  cout << new_s << endl;


  // ここまで
  return 0;
}