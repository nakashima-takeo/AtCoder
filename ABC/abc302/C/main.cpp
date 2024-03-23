#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

bool almostEqual(string a, string b){
  int difference = 0;
  REP(i, a.length()){
    if(a[i] != b[i]) difference++;
    if(difference == 2) return false;
  }
  return true;
}

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  REP(i, n) cin >> s[i];

  multimap<int, int> graphMap;
  REP(i, n){
    REP(j, n){
      if(almostEqual(s[i], s[j])){
        graphMap.emplace(i, j);
      }
    }
  }

  REP(i, n){
    stack<pair<int,set<int>>> result_stack;
    set<int> a_set;
    a_set.insert(i);
    result_stack.emplace(i, a_set);
    while (!result_stack.empty())
    {
      auto p = result_stack.top();
      result_stack.pop();
      auto range = graphMap.equal_range(p.first);
      for(auto it = range.first; it != range.second; ++it){
        if(p.second.find(it->second) == p.second.end()){
          set<int> nextP = p.second;
          nextP.insert(it->second);
          if(nextP.size() == n){
            cout << "Yes" << endl;
            return 0;
          }
          result_stack.emplace(it->second, nextP);
        }
      }
    }
  }

  cout << "No" << endl;

  // ここまで
  return 0;
}
