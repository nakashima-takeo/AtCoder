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

  int n, a;
  cin >> n >> a;

  int amari = n % 500;
  if(amari <= a) cout << "Yes" << endl;
  else cout << "No" << endl;

  // ここまで
  return 0;
}
