Brute Force Approach

//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        int ans=1; //final value
    for(int i=0;i<=n-1;i++)
    {
        int count=1; // count of overlapping interval of only this   iteration
        for(int j=0;j<=n-1;j++)
        {
            if(i == j){
                continue;
            }
            if((arr[i]>=arr[j] && arr[i]<=dep[j]))
           {
               count++;
           }
        }
        ans=max(ans,count); //updating the value
    }
    return ans;

    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends


Optimal Approach

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at , at + n);
    sort(dt , dt + n);

    int ans = 1;
    int count = 1;
    int i = 1, j = 0;
    while(i < n && j < n){
        if(at[i] <= dt[j]){
            count++;
            i++;
        }
        else if(at[i] > dt[j]){
            count--;
            j++;
        }
        ans = max(ans , count);
    }
    return ans;
}
