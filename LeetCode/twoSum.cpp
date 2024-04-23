#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> numMap;
      int n = nums.size();

      // ハッシュテーブルの作成
      for(int i = 0; i < n; i++){
        numMap[nums[i]] = i;
      }

      // 発見
      for (int i = 0; i < n; i++){
        int complement = target - nums[i];
        if(numMap.count(complement) && numMap[complement] != i){
          cout << numMap[complement] << endl;
          return {i, numMap[complement]};
        }
      }
      return {};
    }
};

#include <iostream>

int main(){
  Solution s;
  vector<int> nums = {5, 5, 11, 15};
  int target = 10;
  vector<int> ans = s.twoSum(nums, target);
  cout << ans[0] << ans[1] << endl;
  return 0;
}
