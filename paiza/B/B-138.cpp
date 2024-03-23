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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h) cin >> s[i];

  int result = 0;

  FOR(i, 1, h - 1){
    REP(j, w){
      if(s[i][j] == '.'){
        if(s[i-1][j-1] == '#' &&
           s[i-1][j] == '#' &&
           s[i-1][j+1] == '#' &&
           s[i][j-1] == '#' &&
           s[i][j+1] == '#' &&
           s[i+1][j-1] == '#' &&
           s[i+1][j] == '#' &&
           s[i+1][j+1] == '#'){
          result++;

        }
      }
    }
  }

  cout << result << endl;

  return 0;
}
