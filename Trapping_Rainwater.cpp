Brute Force Approach

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int j = i;
            int leftMax = 0 , rightMax = 0;
            while(j >= 0){
                leftMax = max(leftMax, height[j]);
                j--;
            }
            j = i;
            while(j < n){
                rightMax = max(rightMax , height[j]);
                j++;
            }
            ans += (min(leftMax , rightMax) - height[i]);
        }
        return ans;
    }
};


Better Approach

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int> prefix(n , 0);
        vector<int> suffix(n, 0);
        prefix[0] = height[0];
        suffix[n-1] = height[n-1];
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i-1], height[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = max(suffix[i+1], height[i]);
        }

        for(int i = 0; i < n; i++){
            ans += (min(prefix[i], suffix[i]) - height[i]);
        }
        return ans;
    }
};


Optimal Approach

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] > leftMax){
                    leftMax = height[left];
                }
                else{
                    ans += (leftMax - height[left]);

                }
                left++;
            }
            else{
                if(height[right] > rightMax){
                    rightMax = height[right];
                }
                else{
                    ans += (rightMax - height[right]);
                }
                right--;
            }
        }
        return ans;
    }
};
