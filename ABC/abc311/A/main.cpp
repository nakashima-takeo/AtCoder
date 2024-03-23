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

  int n;
  string s;
  cin >> n >> s;

  vector<bool> t(3);
  REP(i, 3) t.at(i) = false;
  int result = 3;
  REP(i, s.length()){
    if(s.at(i) == 'A'){
      t.at(0) = true;
    }
    if(s.at(i) == 'B'){
      t.at(1) = true;
    }
    if(s.at(i) == 'C'){
      t.at(2) = true;
    }

    if (t.at(0) && t.at(1) && t.at(2)){
      result = i+1;
      break;
    }
  }

  cout << result << endl;

  // ここまで
  return 0;
}
