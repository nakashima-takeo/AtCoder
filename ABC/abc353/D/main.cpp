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

int count_digits(ll x) {
    int digits = 0;
    while (x > 0) {
        x /= 10;
        digits++;
    }
    digits--;
    return digits;
}

bool will_multiply_overflow(long long a, long long b) {
    if (a > 0 && b > 0 && a > (LLONG_MAX / b)) {
        return true;
    }
    return false;
}

long long safe_multiply(long long a, long long b) {
    if (will_multiply_overflow(a, b)) {
        throw std::overflow_error("Overflow in multiplication");
    }
    return a * b;
}

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll mod = 998244353LL;
  ull result = 0;

  // 処理
  vector<ll> ten_ex(n);
  vector<ll> ten_ex_count(10, 0);

  rep(i, n){
    ll ex = count_digits(a[i]);
    ten_ex[i] = ex;
    ten_ex_count[ex]++;
  }

  for(ll i = 0LL; i < n; i++){
    ten_ex_count[ten_ex[i]]--;
    rep(j, 10){
      ll pow_number = 1LL;
      rep(k, j+1){
        pow_number *= 10;
        pow_number %= mod;
      }
      // こちらだとうまくいく
      // ll term1 = (a[i] % mod);
      // ll term2 = (pow_number % mod) * (ten_ex_count[j] % mod) % mod;
      // result += (term1 * term2) % mod;
      // result %= mod;
      // こちらだとうまくいく
      result += ((a[i] % mod) * ((pow_number * ten_ex_count[j]) % mod)) % mod;
      result %= mod;
      // こちらだとうまくいかない
      result += ((a[i] % mod) * (pow_number * ten_ex_count[j]) % mod) % mod;
      result %= mod;
    }
    result = (result + (a[i] % mod) * (i % mod) % mod) % mod;
  }

  result %= mod;
  cout << result << endl;

  // ここまで
  return 0;
}
