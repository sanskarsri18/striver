Brute Force Approach

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
     if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
  {
    unordered_set < int > set;
    for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
    {
      if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        maxans = max(maxans, j - i);
        break;
      }
      set.insert(str[j]);
    }
  }
  return maxans;
     
    }
};


Better Approach


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0){
            return 0;
        }
        int left = 0;
        unordered_set<int> set;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(set.find(s[i]) != set.end()){
                while(left < i && set.find(s[i]) != set.end()){
                    set.erase(s[left]);
                    left++;
                }
            }
            set.insert(s[i]);
            ans = max(ans , i - left + 1);
        }
        return ans;
    }
};


Optimal Approach


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp(256, -1);

        int left = 0;
        int right = 0;
        int n = s.length();
        int ans = 0;
        while(right < n){
            if(mpp[s[right]] != -1){
                left = max(mpp[s[right]]+1, left);
                }
                mpp[s[right]] = right;
                ans = max(ans , right - left + 1);
                right++;
            
        }
        return ans;
    }
};
