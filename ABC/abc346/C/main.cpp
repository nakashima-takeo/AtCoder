#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n; ll k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];

  sort(ALL(a));

  ull total = k * (k+1) / 2;
  set<ll> inputSet;
  REP(i, n){
    if(a[i] > k) continue;
    inputSet.insert(a[i]);
  }
  ull inputSum = accumulate(ALL(inputSet), 0LL);
  ull result = total - inputSum;

  cout << result << endl;

  // ここまで
  return 0;
}
