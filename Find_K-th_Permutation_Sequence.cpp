Brute Force Approach

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        for(int i = 0; i < n; i++){
            char a = i + 1 + '0';
            ans.push_back(a);
        }
        while((k-1)){
            next_permutation(ans.begin(), ans.end());
            k--;
        }
        return ans;
    }
};


or

class Solution {
public:
    void solve(vector<string>& temp , string s, int index){
        if(index == s.size()){
            temp.push_back(s);
            return ;
        }

        for(int i = index; i < s.size(); i++){
            swap(s[i], s[index]);
            solve(temp, s, index + 1);
            swap(s[i], s[index]);
        }
    }

    string getPermutation(int n, int k) {
        string s;
        for(int i = 1; i <= n; i++){
            char a = '0' + i;
            s.push_back(a);
        }
        vector<string> temp;
        solve(temp , s, 0);
        sort(temp.begin(), temp.end());
        return temp[k-1];

    }
};


Optimal Approach

class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        vector<int> v;
        for(int i = 1; i < n; i++){
            factorial = factorial * i;
            v.push_back(i);
        }
        v.push_back(n);
        string ans = "";
        k--;
        while(true){
            ans = ans + to_string(v[k/factorial]);
            v.erase(v.begin() + (k/factorial));
            if(v.size() == 0){
                break;
            }
            k = k % factorial;
            factorial = factorial / v.size();
        }
        return ans;
    }
};
