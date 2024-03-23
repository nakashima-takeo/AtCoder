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

  int n, m, d;
  cin >> n >> m >> d;

  vector<int> a(n);
  vector<int> b(m);
  REP(i, n){
    cin >> a[i];
  }
  REP(i, m){
    cin >> b[i];
  }

  

  // ここまで
  return 0;
}
