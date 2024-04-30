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


bool isPalindrome(ll x){
  ll reversed = 0;
  ll tmp = x;
  while(tmp != 0){
    int digit = tmp % 10;
    reversed = reversed * 10 + digit;
    tmp /= 10;
  }
  return (reversed == x);
}

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  ll n;
  cin >> n;

  int max_search = cbrtl(n);
  for (int i = max_search; i > 0; --i)
  {
    ll k = powl(i, 3);
    if(isPalindrome(k)){
      cout << k << endl;
      return 0;
    }
  }


  // ここまで
  return 0;
}
