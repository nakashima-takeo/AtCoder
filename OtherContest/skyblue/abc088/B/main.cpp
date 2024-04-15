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
  vector<int> a(n);
  REP(i, n) cin >> a[i];

  sort(ALL(a), greater<int>());

  int Alice = 0;
  int Bob = 0;

  REP(i, n){
    if(i % 2 == 0){
      Alice += a[i];
    } else {
      Bob += a[i];
    }
  }

  cout << Alice - Bob << endl;

  // ここまで
  return 0;
}
