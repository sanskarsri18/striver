Brute Force Approach

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] > 2 * nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};
