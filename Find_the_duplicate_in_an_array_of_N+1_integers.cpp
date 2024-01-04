Solution 1

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
};


Solution 2

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int *freq = new int[n];
        for(int i = 0; i < n; i++){
            freq[i] = 0;
        }
        for(int i = 0; i < n; i++){
            if(freq[nums[i]] == 1){
                return nums[i];
            }
            freq[nums[i]]++;
        }
        return -1;
    }
};


Solution 3

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
        
    }
};
