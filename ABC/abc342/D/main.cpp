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

ll combination(ll n){
  ll sum = (n * (n-1)) / 2;
  return sum;
}

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  ll sum = 0LL;
  ll n;
  cin >> n;
  vector<ll> A(n);
  rep(i, n) {
    cin >> A[i];
  }
  map<int, int> A_map;
  rep(i,n){
    for(int j = sqrt(A[i]) + 1; j > 0; --j){
      int two = pow(j, 2);
      if(A[i] % two == 0) {
        A_map[A[i] / two]++;
        break;
      }
    }
  }


  for (auto &&i : A_map){
    if(i.first == 0) {
      rep(j, i.second) sum += (n-1-j);
    }
    else sum += combination(i.second);
  }

  cout << sum << endl;


  // ここまで
  return 0;
}
