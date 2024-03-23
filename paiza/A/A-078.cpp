#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ALL(n) begin(n),end(n)

pair<vector<string>, bool> eraseBlocks(vector<string> s){
  stack<pair<int, int>> sta;
  REP(i, s.size()){
    REP(j, 5){
      char a = s[i][j];
      if(a == '.') continue;
      bool same = true;
      if(i != 0) same = same && (s[i-1][j] == a);
      if(i != s.size()-1) same = same && (s[i+1][j] == a);
      if(j != 0) same = same && (s[i][j-1] == a);
      if(j != 4) same = same && (s[i][j+1] == a);
      if(same) sta.push(make_pair(i, j));
    }
  }

  bool isErased = !sta.empty();

  while(!sta.empty()){
    auto [i,j] = sta.top();
    sta.pop();
    s[i][j] = '.';
    if(i != 0) s[i-1][j] = '.';
    if(i != s.size()-1) s[i+1][j] = '.';
    if(j != 0) s[i][j-1] = '.';
    if(j != 4) s[i][j+1] = '.';
  }
  return make_pair(s, isErased);
}

vector<string> fallBlocks(vector<string> s){
  for(int i = s.size()-1; i > 0; i--){
    REP(j, 5){
      if(s[i][j] == '.'){
        for(int k = i-1; k >= 0; k--){
          if(s[k][j] != '.'){
            s[i][j] = s[k][j];
            s[k][j] = '.';
            break;
          }
        }
      }
    }
  }

  return s;
}

int main(void)
{
  int h;
  cin >> h;
  vector<string> s(h);
  REP(i, h) cin >> s[i];

  bool isErased = true;
  while(isErased){
    auto p = eraseBlocks(s);
    s = p.first;
    isErased = p.second;
    s = fallBlocks(s);
  };

  REP(i, h) cout << s[i] << endl;

  return 0;
}
