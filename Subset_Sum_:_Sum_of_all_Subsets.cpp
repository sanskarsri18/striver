#include<bits/stdc++.h>
void solve(vector<int>&ans , int i , vector<int> num, int sum){
	if(i == num.size()){
		ans.push_back(sum);
		return ;
	}

	solve(ans , i+1, num, sum + num[i]);
	solve(ans , i+1, num, sum);
}

vector<int> subsetSum(vector<int> &num){
	vector<int> ans;
	solve(ans , 0 , num , 0);
	sort(ans.begin(), ans.end());
	return ans;	
}
