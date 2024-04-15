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

  string result = "APPROVED";
  REP(i, n){
    if(a[i] % 2 == 0){
      if(a[i] % 3 != 0 && a[i] % 5 != 0) result = "DENIED";
    }
  }

  cout << result << endl;

  // ここまで
  return 0;
}
