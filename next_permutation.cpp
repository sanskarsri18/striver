Brute Force Approach

Step 1: Find all possible permutations of elements present and store them.

Step 2: Search input from all possible permutations.

Step 3: Print the next permutation present right after it.







Better Approach

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};


Optimal Approach

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        for( index = n - 2 ; index >= 0 ; index--){
            if(nums[index] < nums[index + 1]){
                break;
            }
        }

        if(index < 0){
            reverse(nums.begin(), nums.end());
        }
        else{
            for(int i = n - 1 ; i > index ; i--){
                if(nums[index] < nums[i]){
                    swap(nums[index], nums[i]);
                    break;
                }
            }
            reverse(nums.begin() + index + 1 , nums.end());
        }
    }
};

Step 1: Get the size of the input vector
Step 2: Initialize the index to find the first element from the right that is smaller than the element to its right
Step 3: If no such element is found, reverse the entire vector (as it is the last permutation)
Step 4: If such an element is found
Step 5: Find the smallest element to the right of 'index' that is greater than nums[index]
Step 6: Swap nums[index] with the found element
Step 7: Reverse the subarray to the right of 'index'
