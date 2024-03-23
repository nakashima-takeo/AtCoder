#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

bool check(string s){
  int n = s.size();
  if(s[0] != '<') return false;
  if(s.back() != '>') return false;
  for(int i = 1; i <= n-2; i++){
    if(s[i] != '=') return false;
  }
  return true;
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
