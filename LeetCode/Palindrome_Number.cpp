#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
      if(x < 0) return false;
      int number_count = 0;
      for (int i = 0;; i++)
      {
        if(x / static_cast<long long>(pow(10, i)) == 0){
          number_count = i;
          break;
        }
      }

      for(int i = 0; i < number_count/2; i++){
        if((x / static_cast<long long>(pow(10, number_count - 1 - i))) % 10 != ((x % static_cast<long long>(pow(10, i+1))) / static_cast<long long>(pow(10, i)))){
          return false;
        }
      }

      return true;
    }
};


#include <iostream>
int main(int argc, char const *argv[])
{
  Solution s;
  std::cout << s.isPalindrome(123321) << std::endl;
  return 0;
}
