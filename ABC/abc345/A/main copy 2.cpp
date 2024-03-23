#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

bool check(string s){
  regex re("<=+>");
  return regex_match(s, re);
}

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  string s;
  cin >> s;

  if(check(s)) cout << "Yes" << endl;
  else cout << "No" << endl;
  // ここまで
  return 0;
}
