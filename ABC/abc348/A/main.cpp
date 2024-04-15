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

  string result = "";
  REP(i, n){
    if((i+1) % 3 == 0) result.append("x");
    else result.append("o");
  }

  cout << result << endl;

  // ここまで
  return 0;
}
