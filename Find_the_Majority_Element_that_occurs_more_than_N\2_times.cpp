Brute Force Approach

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
            if(count > (n / 2)){
                return nums[i];
            }
        }
        return -1;
    }
};


Better Approach


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > (n / 2)){
                return nums[i];
            }
        }
        return -1;
    }
};



Optimal Approach (Moore's Voting Algorithm)


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int element;

        for(int i = 0; i < n; i++){
            if(count == 0){
                element = nums[i];
            }

            if(nums[i] == element){
                count++;
            }
            else{
                count--;
            }
        }
        return element;
    }
};
