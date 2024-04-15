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

  int n;
  cin >> n;
  vector<int> d(n);
  REP(i, n) cin >> d[i];

  ll sum = 0LL;
  REP(i, n){
    for(int j = i+1; j < n; j++){
      sum += d[i] * d[j];
    }
  }

  cout << sum << endl;

  // ここまで
  return 0;
}
