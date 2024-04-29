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
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];

  set<int> sumSet;

  // setに和を保存する
  rep(bit, 1<<n){
    int sum = 0;
    rep(i, n){
      if(bit & (1 << i)) sum += A[i];
    }
    sumSet.insert(sum);
  }

  int q;
  cin >> q;
  rep(i, q){
    int a;
    cin >> a;
    if(sumSet.contains(a)) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  return 0;
}
