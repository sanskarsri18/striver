Brute Force Approach

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(prices[j] > prices[i]){
                ans = max(ans , prices[j] - prices[i]);
            }
            }
            
        }
        return ans;
    }
};






Optimal Approach

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = INT_MAX;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(prices[i] < mini){
                mini = prices[i];
            }
            ans = max(ans, prices[i] - mini);
        }
        return ans;
    }
};
