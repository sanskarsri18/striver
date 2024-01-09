Brute Force Approach

class Solution {
public:
    bool ls(vector<int> nums, int target){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                return true;
            }
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int ans = 1;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int count = 1;
            while(ls(nums, x + 1)){
                x++;
                count++;
            }
            ans = max(ans , count);
        }
        return ans;
    }
};



Better Approach

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        int longest = 1;
        int cnt = 0;
        int lastSmaller = INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if((long long)nums[i] - lastSmaller == 1){
                cnt+=1;
                lastSmaller++;
            }
            else if(nums[i] != lastSmaller){
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }

};
