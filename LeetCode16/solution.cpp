#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = numeric_limits<int>::max();
        sort(nums.begin(), nums.end());
        for(auto i = nums.begin();i<nums.end()-2; i++){
             auto a = i+1;
             auto b = nums.end()-1;
             while(a<b){
                  int sum = *a + *b + *i;
                  ans = abs(sum - target) < abs(ans - target)? sum:ans;
                  if(*a + *b + *i < target){a++;}else{b--;}
             }
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {-1,2,1,-4,5};
    Solution sol;
    cout << sol.threeSumClosest(arr, 5)<<endl;
    return 0;
};
