Brute Force Approach

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};


Better Approach


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(mp.find(target - nums[i]) != mp.end()){
                return {i , mp[target - nums[i]]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};


Optimal Approach


string read(int n, vector<int> book, int target)
{
    int low = 0;
    int high = n - 1;
    sort(book.begin(), book.end());
    while(low<=high){
        if(book[low] + book[high] < target){
            low++;
        }
        else if(book[low] + book[high] > target){
            high--;
        }
        else{
            return "YES";
        }
    }
    return "NO";
}

