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

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> ans;
  REP(i,n){
    if(a[i] % k == 0){
      ans.push_back(a[i]/k);
    }
  }

  REP(i, ans.size()){
    cout << ans[i] << " ";
  }

  // ここまで
  return 0;
}
