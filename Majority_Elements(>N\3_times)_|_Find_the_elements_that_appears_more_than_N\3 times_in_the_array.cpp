Brute Force Approach

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            int count = 0;
            if(ans.empty() || nums[i] != ans[0]){
                for(int j = 0; j < n; j++){
                    if(nums[i] == nums[j]){
                        count++;
                    }
                }

                if(count > (n/3)){
                    ans.push_back(nums[i]);
                }
                if(ans.size() == 2){
                    break;
                }
            }
        }
        return ans;
    }
};


Better Approach

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        map<int, int> freq;
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }

        for(auto it : freq){
            if(it.second > (n/3)){
                ans.push_back(it.first);
            }
            if(ans.size() == 2){
                break;
            }
        }
        return ans;
    }
};


Optimal Approach

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c2 = 0;
        int c1 = 0;
        int e1, e2;
        for(int i = 0; i < n; i++){
            if(c1 == 0 && nums[i] != e2){
                c1 = 1;
                e1 = nums[i];
            }
            else if(c2 == 0 && nums[i] != e1){
                c2 = 1;
                e2 = nums[i];
            }
            else if(nums[i] == e1){
                c1++;
            }
            else if(nums[i] == e2){
                c2++;
            }
            else{
                c1--, c2--;
            }
        }

        vector<int> ans;
        int count1 = 0;
        int count2 = 0;
        for(int i : nums){
            if(i == e1){
                count1++;
            }
            if(i == e2){
                count2++;
            }
        }

        if(count1 > (n/3)){
            ans.push_back(e1);
        }
        if(count2 > (n/3)){
            ans.push_back(e2);
        }
        return ans;
    }
};
