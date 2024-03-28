#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  int total_legs, total, turu_legs, kame_legs;
  cin >> total_legs >> total >> turu_legs >> kame_legs;

  set<pair<int, int>> turu_kame;

  if(total < 2){
    cout << "miss" << endl;
    return 0;
  }
  if(turu_legs != 0 && kame_legs != 0){
    int repeat_count = total_legs/turu_legs;
    REP(turu, repeat_count+1){
      int kame = total - turu;
      if((kame * kame_legs) + (turu * turu_legs) == total_legs){
        if(turu <= 0 || kame <= 0) continue;
        turu_kame.insert(make_pair(turu, kame));
      }
    }
  } else if(kame_legs != 0){
    if(total_legs % kame_legs == 0){
      int kame = (total_legs / kame_legs);
      int turu = total - kame;
      if(turu > 0 && kame > 0){
        turu_kame.insert(make_pair(turu, kame));
      }
    }
  } else if(turu_legs != 0){
    if(total_legs % turu_legs == 0){
      int turu = (total_legs / turu_legs);
      int kame = total - turu;
      if(turu > 0 && kame > 0){
        turu_kame.insert(make_pair(turu, kame));
      }
    }
  } else {
    if(total_legs == 0){
      if(total == 2){
        turu_kame.insert(make_pair(1, 1));
      }
    }
  }
  if (turu_kame.size() == 1)
  {
    auto it = turu_kame.begin();
    pair<int, int> ans = *it;
    cout << ans.first << " " << ans.second << endl;
  } else {
    cout << "miss" << endl;
  }

  return 0;
}
