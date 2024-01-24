Brute Force Approach

class Solution {
public:
    void solve( vector<int> nums , int index , set<vector<int>>&temp , vector<int> output){
        if(index == nums.size()){
            sort(output.begin(), output.end());
            temp.insert(output);
            return ;
        }

        output.push_back(nums[index]);
        solve(nums , index + 1, temp, output);
        output.pop_back();
        solve(nums , index + 1, temp, output);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> temp;
        vector<int> output;
        solve(nums , 0 , temp , output);
        vector<vector<int>> ans(temp.begin(), temp.end());
        return ans;
    }
};

Optimal Approach

class Solution {
public:
void solve(vector<vector<int>>& ans, vector<int> output, vector<int> nums, int index){
    ans.push_back(output);
    for(int i = index; i < nums.size(); i++){
        if(i != index && nums[i] == nums[i-1])continue;
        output.push_back(nums[i]);
        solve(ans, output, nums, i+1);
        output.pop_back();
    }
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end());
        solve(ans , output, nums, 0);
        return ans;
    }
};
