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

  string s;
  cin >> s;

  set<string> ss;

  for(int i = 1; i <= s.length(); i++){
    for(int j = 0; j+i <= s.length(); j++){
      ss.insert(s.substr(j, i));
    }
  }

  cout << ss.size() << endl;

  // ここまで
  return 0;
}
