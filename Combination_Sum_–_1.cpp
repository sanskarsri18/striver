class Solution {
public:
    void solve(vector<int> candidates, int target, vector<vector<int>>& ans, vector<int> output, int index){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(output);
            }
            return ;
        }

        if(candidates[index] <= target){
            output.push_back(candidates[index]);
            solve(candidates, target - candidates[index], ans, output, index);
            output.pop_back();
        }
            solve(candidates, target, ans, output, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates, target, ans, output, 0);
        return ans;
    }
};
