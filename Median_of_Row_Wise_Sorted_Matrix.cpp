Brute Force Approach

#include <bits/stdc++.h>

int getMedian(vector<vector<int>> &matrix)
{
    vector<int> v;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            v.push_back(matrix[i][j]);
        }
    }
    sort(v.begin(), v.end());
    return v[v.size()/2];
}

Optimal Approach

#include <bits/stdc++.h>

int upperBound(vector<int>&arr, int x, int n){
    int low = 0;
    int high = n - 1;
    int ans = n;
    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }

    }
    return ans;

}

int countSmallEqual(vector<vector<int>> matrix, int n, int m, int x){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += upperBound(matrix[i], x, m);
    }
    return cnt;
}

int getMedian(vector<vector<int>> &matrix)
{
    int low = INT_MAX;
    int high = INT_MIN;

    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < n; i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m-1]);
    }

    int req = (n*m)/2;

    while(low <= high){
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, n, m, mid);
        if(smallEqual <= req){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}
