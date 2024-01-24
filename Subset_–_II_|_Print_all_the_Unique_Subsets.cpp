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
