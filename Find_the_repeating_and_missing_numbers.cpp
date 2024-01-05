Brute Force Approach

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int missing = -1;
	int repeating = -1;
	

	for(int i = 1 ; i <= n; i++){
		int count = 0;
		for(int j = 0; j < n; j++){
			if(arr[j] == i){
				count++;
			}
		}

		if(count == 2){
			repeating = i;
		}

		if(count == 0){
			missing = i;
		}

		if(repeating != -1 && missing != -1){
			break;
		}
	} 
	return {missing , repeating};
	
}


Better Approach

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	vector<int> hash(n+1 , 0);
	for(int i = 0; i < n; i++){
		hash[arr[i]]++;
	} 

	int missing = 0;
	int repeating = 0;

	for(int i = 1; i <= n; i++ ){
		if(hash[i] == 0){
			missing = i;
		}

		if(hash[i] == 2){
			repeating = i;
		}

		if(missing && repeating){
			break;
		}
	}

	return {missing , repeating};
	
}


Optimal Approach

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &a, int N)
{	long long n = (long long)N;
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)y, (int)x};

}
