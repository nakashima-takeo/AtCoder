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

  ll a,b;
  cin >> a >> b;

  ll result = 0;
  if(a % b == 0){
    result = a/b;
  } else {
    result = static_cast<ll>(a/b) + 1;
  }

  cout << result << endl;

  // ここまで
  return 0;
}
