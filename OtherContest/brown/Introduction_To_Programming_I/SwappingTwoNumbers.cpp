#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  vector<pair<int, int>> xy;
  while (true)
  {
    int x, y;
    cin >> x >> y;
    if(x == 0 && y == 0) break;
    xy.emplace_back(x, y);
  }

  for (auto &&i : xy)
  {
    int small, large;
    if(i.first > i.second){
      small = i.second;
      large = i.first;
    } else {
      small = i.first;
      large = i.second;
    }
    cout << small << " " << large << endl;
  }


  return 0;
}
