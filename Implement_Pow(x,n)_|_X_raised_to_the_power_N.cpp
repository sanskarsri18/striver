Brute Force Approach

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        int m = n;
        if(m < 0){
            m = -m;
        }
        for(int i = 0; i < m; i++){
            ans = ans * x;
        }

        if(n < 0){
            return 1.0/ans;
        }
        return ans;


    }
};


Optimal Approach

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long m = n;
        if(m < 0){
            m = -m;
        }

        while(m){
            if(m%2){
                ans = ans * x;
                m = m - 1;
            }
            else{
                x = x * x;
                m = m / 2;
            }
        }

        if(n < 0){
            return 1.0/ans;
        }
        return ans;
    }
};
