Brute Force Approach

#include <bits/stdc++.h>

bool canWePlace(vector<int> &stalls, int dist, int k){
    int n = stalls.size();
    int cowCount = 1;
    int last = stalls[0];
    for(int i = 1; i < n; i++){
        if(stalls[i] - last >= dist){
            cowCount++;
            last = stalls[i];
        }
        if(cowCount >= k)return true;
    }
    return false;

}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int limit = stalls[n - 1] - stalls[0];
    for(int i = 1; i <= limit; i++){
        if(canWePlace(stalls, i, k) == false){
            return i - 1;
        }
    }
    return limit;
}


Optimal Approach

#include <bits/stdc++.h>

bool canWePlace(vector<int> &stalls, int dist, int k){
    int n = stalls.size();
    int cowCount = 1;
    int last = stalls[0];
    for(int i = 1; i < n; i++){
        if(stalls[i] - last >= dist){
            cowCount++;
            last = stalls[i];
        }
        if(cowCount >= k)return true;
    }
    return false;

}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int high = stalls[n - 1] - stalls[0];
    int low = 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(canWePlace(stalls, mid, k)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}
