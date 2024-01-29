Brute Force Approach

class Solution {
public:

    void solve(vector<vector<int>>& ans, vector<int> output, vector<int> freq, vector<int> nums){
        if(output.size() == nums.size()){
            ans.push_back(output);
            return ;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!freq[i]){
                output.push_back(nums[i]);
                freq[i] = 1;
                solve(ans, output, freq, nums);
                freq[i] = 0;
                output.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        vector<int> freq(nums.size(), 0);
        solve(ans, output, freq, nums);
        return ans;
    }
};


Optimal Approach

class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int> nums, int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return ;
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[i], nums[index]);
            solve(ans, nums, index + 1);
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans, nums, 0);
        return ans;
    }
};
