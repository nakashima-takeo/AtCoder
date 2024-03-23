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

  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h) cin >> s[i];
  struct Accessable{
    bool up_boundary = false;
    bool down_boundary = false;
    bool right_boundary = false;
    bool left_boundary = false;
    void reset(){
      up_boundary = false;
      down_boundary = false;
      right_boundary = false;
      left_boundary = false;
    }
  };

  Accessable boundary;

  REP(i, h){
    REP(j, w){
      if(s[i][j] == 's'){
        boundary.reset();
        if(i >= 4) boundary.up_boundary = true;
        if(j >= 4) boundary.left_boundary = true;
        if(j <= w -5) boundary.right_boundary = true;
        if(i <= h -5) boundary.down_boundary = true;
        if(boundary.right_boundary){
          if(
            s[i][j+1] == 'n' &&
            s[i][j+2] == 'u' &&
            s[i][j+3] == 'k' &&
            s[i][j+4] == 'e'
          ){
            cout << i+1 << " " << j+1 << endl;
            cout << i+1 << " " << j+1+1 << endl;
            cout << i+1 << " " << j+1+2 << endl;
            cout << i+1 << " " << j+1+3 << endl;
            cout << i+1 << " " << j+1+4 << endl;
            return 0;
          }
        }
        if(boundary.left_boundary){
          if(
            s[i][j-1] == 'n' &&
            s[i][j-2] == 'u' &&
            s[i][j-3] == 'k' &&
            s[i][j-4] == 'e'
          ){
            cout << i+1 << " " << j+1 << endl;
            cout << i+1 << " " << j+1-1 << endl;
            cout << i+1 << " " << j+1-2 << endl;
            cout << i+1 << " " << j+1-3 << endl;
            cout << i+1 << " " << j+1-4 << endl;
            return 0;
          }
        }
        if(boundary.up_boundary){
          if(
            s[i-1][j] == 'n' &&
            s[i-2][j] == 'u' &&
            s[i-3][j] == 'k' &&
            s[i-4][j] == 'e'
          ){
            cout << i+1 << " " << j+1 << endl;
            cout << i+1-1 << " " << j+1 << endl;
            cout << i+1-2 << " " << j+1 << endl;
            cout << i+1-3 << " " << j+1 << endl;
            cout << i+1-4 << " " << j+1 << endl;
            return 0;
          }
        }
        if(boundary.down_boundary){
          if(
            s[i+1][j] == 'n' &&
            s[i+2][j] == 'u' &&
            s[i+3][j] == 'k' &&
            s[i+4][j] == 'e'
          ){
            cout << i+1 << " " << j+1 << endl;
            cout << i+1+1 << " " << j+1 << endl;
            cout << i+1+2 << " " << j+1 << endl;
            cout << i+1+3 << " " << j+1 << endl;
            cout << i+1+4 << " " << j+1 << endl;
            return 0;
          }
        }
        if(boundary.down_boundary && boundary.right_boundary){
          if(
            s[i+1][j+1] == 'n' &&
            s[i+2][j+2] == 'u' &&
            s[i+3][j+3] == 'k' &&
            s[i+4][j+4] == 'e'
          ){
            cout << i+1 << " " << j+1 << endl;
            cout << i+1+1 << " " << j+1+1 << endl;
            cout << i+1+2 << " " << j+1+2 << endl;
            cout << i+1+3 << " " << j+1+3 << endl;
            cout << i+1+4 << " " << j+1+4 << endl;
            return 0;
          }
        }
        if(boundary.down_boundary && boundary.left_boundary){
          if(
            s[i+1][j-1] == 'n' &&
            s[i+2][j-2] == 'u' &&
            s[i+3][j-3] == 'k' &&
            s[i+4][j-4] == 'e'
          ){
            cout << i+1 << " " << j+1 << endl;
            cout << i+1+1 << " " << j+1-1 << endl;
            cout << i+1+2 << " " << j+1-2 << endl;
            cout << i+1+3 << " " << j+1-3 << endl;
            cout << i+1+4 << " " << j+1-4 << endl;
            return 0;
          }
        }
        if(boundary.up_boundary && boundary.right_boundary){
          if(
            s[i-1][j+1] == 'n' &&
            s[i-2][j+2] == 'u' &&
            s[i-3][j+3] == 'k' &&
            s[i-4][j+4] == 'e'
          ){
            cout << i+1 << " " << j+1 << endl;
            cout << i+1-1 << " " << j+1+1 << endl;
            cout << i+1-2 << " " << j+1+2 << endl;
            cout << i+1-3 << " " << j+1+3 << endl;
            cout << i+1-4 << " " << j+1+4 << endl;
            return 0;
          }
        }
        if(boundary.up_boundary && boundary.left_boundary){
          if(
            s[i-1][j-1] == 'n' &&
            s[i-2][j-2] == 'u' &&
            s[i-3][j-3] == 'k' &&
            s[i-4][j-4] == 'e'
          ){
            cout << i+1 << " " << j+1 << endl;
            cout << i+1-1 << " " << j+1-1 << endl;
            cout << i+1-2 << " " << j+1-2 << endl;
            cout << i+1-3 << " " << j+1-3 << endl;
            cout << i+1-4 << " " << j+1-4 << endl;
            return 0;
          }
        }
      }
    }
  }

  // ここまで
  return 0;
}
