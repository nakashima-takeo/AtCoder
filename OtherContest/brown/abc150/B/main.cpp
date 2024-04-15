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
  string s;
  cin >> n >> s;

  int result = 0;
  REP(i, s.length() - 2){
    if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') result++;
  }

  cout << result << endl;

  // ここまで
  return 0;
}
