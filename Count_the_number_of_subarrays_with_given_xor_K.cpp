Brute Force Approach


int subarraysWithSumK(vector < int > a, int b) {
    int count = 0;
    int n = a.size();

    for(int i = 0; i < n; i++){
        
        for(int j = i; j < n; j++){
                int x = 0;
            for(int k = i ; k <= j; k++){
                x = x ^ a[k];
            }
                if(x == b){
                    count++;
                }
        }
    }
    return count;
}



Better Approach

int subarraysWithSumK(vector < int > a, int b) {
    int count = 0;
    int n = a.size();

    for(int i = 0; i < n; i++){
        int x = 0;
        for(int j = i; j < n; j++){
            x = x ^ a[j];
            if(x == b){
                count++;
            }
        }
    }
    return count;
}


Optimal Approach


#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    int n = a.size();
    int cnt = 0;
    int x = 0;
    map<int, int> m;
    m[x]++;
    for(int i = 0; i < n; i++){
        x = x ^ a[i];
        int req = x ^ b;
        cnt += m[req];

        m[x]++;
    }
    return cnt;
}
