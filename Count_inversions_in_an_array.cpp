Brute Force Approach

#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}


Optimal Approach


#include <bits/stdc++.h> 


long long merge(long long *arr , long long low , long long mid, long long high){
    vector<long long> temp;
    long long count = 0;
    long long left = low;
    long long right = mid + 1;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
            count += (mid - left + 1);

        }
    }

    while(left <= mid){
        temp.push_back(arr[left++]);
    }

    while(right <= high){
        temp.push_back(arr[right++]);
    }


    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }

    return count;
}

long long mergeSort(long long *arr , long long low , long long high){
    long long count = 0;
    if(low == high){
        return 0;
    }

    long long mid = (low + high) / 2;

    count += mergeSort(arr , low , mid);
    count += mergeSort(arr , mid + 1 , high);
    count += merge(arr, low, mid, high);

    return count;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr , 0 , n - 1);
}
