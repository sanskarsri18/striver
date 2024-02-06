Brute Force Approach

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        if(nums[0] != nums[1]){
            return nums[0];
        }

        if(nums[n-1] != nums[n - 2]){
            return nums[n - 1];
        }

        for(int i = 1; i < n - 1; i++){
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
};

Brute Force Approach

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

Optimal Approach

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        if(nums[0] != nums[1]){
            return nums[0];
        }

        if(nums[n - 1] != nums[n - 2]){
            return nums[n - 1];
        }

        int s = 1;
        int e = n - 2;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                return nums[mid];
            }

            if((mid%2 == 1 && nums[mid] == nums[mid - 1]) || (mid%2 == 0) && nums[mid] == nums[mid + 1]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }

        }
            return -1;
    }
};
