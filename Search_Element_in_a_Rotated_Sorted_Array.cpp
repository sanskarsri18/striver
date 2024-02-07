Brute Force Approach

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};


Optimal Approach

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        while(s <= e){
            int mid = s + (e - s) / 2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] >= nums[s]){
                if(target >= nums[s] && target <= nums[mid]){
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] && target <= nums[e]){
                    s = mid + 1;
                }
                else{
                    e = mid - 1;
                }
            }
        }
            return -1;
    }
};
