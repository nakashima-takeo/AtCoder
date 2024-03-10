#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ALL(n) begin(n),end(n)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);

  // ここから本番コード
  string s;
  cin >> s;

  REP(i, s.length()){
    char r = s.at(i);
    if (i == 0){
      if (isupper(r)){
        continue;
      } else {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (islower(r)){
        continue;
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;

  // ここまで

  return 0;
}
