Brute Force Approach

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> temp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    for(int l = k + 1; l < n; l++){
                        long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                        if(sum == target){
                            vector<int> v;
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[k]);
                            v.push_back(nums[l]);
                            sort(v.begin(), v.end());
                            temp.insert(v);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(temp.begin(), temp.end());
        return ans;
    }
};




Better Approach


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> s;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                set<long long> temp;
                for(int k = j + 1; k < n; k++){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k];
                    if(temp.find(target - sum) != temp.end()){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(target - sum);
                        sort(v.begin(), v.end());
                        s.insert(v);
                    }
                    temp.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};


Optimal Approach


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            for(int j = i + 1; j < n; j++){
                if(j>(i+1) && nums[j] == nums[j-1])continue;

                int k = j + 1;
                int l = n - 1;
                while(k < l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++,l--;
                        while(k < l && nums[k] == nums[k-1])k++;
                        while(k < l && nums[l] == nums[l+1])l--;
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
