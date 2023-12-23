Brute Force Approach

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i ; j < n;j++){
                int sum = 0;
                for(int k = i; k <= j; k++){
                    sum+=nums[k];
                }
                ans = max(ans , sum);
            }
        }
        return ans;
    }
};





Better approach

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i ; j < n; j++){
                sum += nums[j];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

The provided C++ code uses a brute-force approach to find the maximum sum of a contiguous subarray in an array of integers. It iterates through all possible subarrays, calculates their sums, and updates the maximum sum. The time complexity is O(n^2), and space complexity is O(1). While simple, it may not be efficient for large datasets. Consider using more optimized algorithms like Kadane's for practical applications.


Optimal Approach

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSoFar = INT_MIN;
        int maxEndingHere = 0;
        for(int i = 0 ; i < n ; i++){
            maxEndingHere = maxEndingHere + nums[i];
            if(maxEndingHere > maxSoFar){
                maxSoFar = maxEndingHere;
            }
            if(maxEndingHere < 0){
                maxEndingHere = 0;
            }
        }
        return maxSoFar;
    }
};

The algorithm employs Kadane's approach to efficiently find the maximum subarray sum in a given vector (`nums`). It maintains two variables: `maxSoFar` records the overall maximum sum, and `maxEndingHere` tracks the maximum sum ending at the current index. By iteratively updating these variables during traversal, the algorithm ensures the inclusion of positive contributions while efficiently handling negative values by resetting `maxEndingHere` to 0 when encountering a negative sum. This strategy enables a single-pass solution, making it effective for both positive and negative integer scenarios.







Follow up question

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}


