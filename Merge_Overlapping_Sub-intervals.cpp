Brute Force Approach

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(!ans.empty() && intervals[i][1] <= ans.back()[1]){
                continue;
            }
            for(int j = i + 1; j < n; j++){
                if(intervals[i][1] >= intervals[j][0]){
                    intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                }
                else{
                    break;
                }
            }

            ans.push_back({intervals[i][0], intervals[i][1]});

        }
        return ans;
    }
};



Optimal Approach

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n; i++){
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }
        }
        return ans;
    }
};
