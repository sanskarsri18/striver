Brute Force Approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    if(sum == 0){
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[k]);
                        sort(t.begin(), t.end());
                        s.insert(t);
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};


Better Approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            set<long long> l;
            for(int j = i + 1; j < n; j++){
                long long sum = (long long)nums[i] + nums[j];
                if(l.find(0 - sum) != l.end()){
                    vector<int> temp {nums[i], nums[j]};
                    temp.push_back((int)(0-sum));
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                l.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};


Optimal Approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n ; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                long long sum = (long long)nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if (sum > 0){
                    k--;
                } 
                else{
                    vector<int> temp{nums[i] , nums[j] , nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j - 1])j++;
                    while(j < k && nums[k] == nums[k + 1])k--;
                }
            }
        }
        return ans;
    }
};
