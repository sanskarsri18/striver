Brute Force Approach

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    
        set<int> temp;
        for(auto i : nums){
            temp.insert(i);
        }
        int j = 0;
        for(auto i : temp){
            nums[j++] = i;
        }
        return temp.size();
    }
};


Optimal Approach

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j = 1; j < n; j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return (i + 1);
    }
};
