class Solution {
public:
    void solve(string s, vector<vector<string>>& ans, vector<string> output, int index){
        if(index == s.size()){
            ans.push_back(output);
            return ;
        }

        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s , index, i)){
                output.push_back(s.substr(index, i - index + 1));
                solve(s, ans, output, i + 1);
                output.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int st, int e){
        // int s = 0;
        // int e = s.size() - 1;
        while(st<=e){
            if(s[st++] != s[e--]){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        solve(s, ans, output, 0);
        return ans;
    }
};
