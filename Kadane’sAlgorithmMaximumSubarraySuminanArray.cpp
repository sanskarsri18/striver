Brute Force Approach

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i ; j < n;j++){
                int sum = 0;
                for(int k = i; k <= j; k++){
                    sum+=nums[k];
                }
                ans = max(ans , sum);
            }
        }
        return ans;
    }
};





Better approach

