Brute Force Approach

class Solution {
public:
    bool linearSearch(vector<int> nums , int x){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == x){
                return true;
            }
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int count = 1;
            while(linearSearch(nums, x+1)){
                
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
        int ans = 0;
        int count = 0;
        int sequenceStart = INT_MIN;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            if((nums[i] - 1) == sequenceStart){
                sequenceStart = nums[i];
                count++;
            }
            else if(nums[i] == sequenceStart){
                continue;
            }
            else if((nums[i] - 1) != sequenceStart){
                count = 1;
                sequenceStart = nums[i];
            }
            ans = max(ans, count);
        }
        return ans;
    }
};



Optimal Approach


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i : nums){
            s.insert(i);
        }
        int ans = 0;

        for(int i : s){
            if(s.find(i - 1) == s.end()){
                int count = 1;
                int x = i;
                while(s.find(x+1) != s.end()){
                    x++;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
