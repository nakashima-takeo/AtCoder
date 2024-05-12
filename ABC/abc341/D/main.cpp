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

const ll INF = 1LL << 60;

ll gcd(ll x, ll y){
  if(x>y) swap(x,y);
  if (y%x == 0) return x;
  return gcd(y%x, x);
}

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  ll n, m, k;
  cin >> n >> m >> k;
  ll nmgcd = gcd(n, m);

  auto count = [n, m, nmgcd](ll a){
    return a/n + a/m - 2*(a/(n*m/nmgcd));
  };

  ll upperBound = INF;
  ll lowerBound = 0;
  ll result = INF/2;
  while (true){
    ll k_count = count(result);
    if(k_count == k){
      // cout << result << endl;
      // cout << result % n << " " << result % m << endl;
      if (result % n == 0 && result % m == 0){
        result -= min(n, m);
      } else if (result % n == 0){
      } else if (result % m == 0){
      } else if (result % n == result % m){
        result -= min(n, m) + result % n;
      } else {
        result -= min(result % n, result % m);
        if(result % n == 0 && result % m == 0){
          result -= min(n, m);
        }
      }
      cout << result << endl;
      // cout << result % n << " " << result % m << endl;
      return 0;
    }
    else if(k_count > k){
      upperBound = result--;
    } else {
      lowerBound = result++;
    }
    result = (upperBound + lowerBound)/2;
  }
  
  


  // ここまで
  return 0;
}
