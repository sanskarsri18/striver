#include<bits/stdc++.h>
vector<int> MinimumCoins(int n)
{
    vector<int> ans;
    vector<int> curr = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int remaining = n;
    for(int i = 0; i < 9; i++){
        if((remaining / curr[i]) == 0){
            continue;
        }
        int quantity = remaining / curr[i];
        while(quantity--){
            ans.push_back(curr[i]);
        }

        remaining = remaining - remaining/curr[i]*curr[i];
    }
    return ans;
}
