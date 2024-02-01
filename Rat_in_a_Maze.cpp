Brute Force Approach

class Solution{
    public:
    void solve(vector<string>& ans, string path, vector<vector<int>>& visited, vector<vector<int>>& m, int n, int i, int j){
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return ;
        }
        
        if((i+1) < n && visited[i+1][j] == 0 && m[i+1][j] == 1){
            path.push_back('D');
            visited[i][j] = 1;
            solve(ans, path, visited, m, n, i+1, j);
            path.pop_back();
            visited[i][j] = 0;
        }
        
        
        if((j-1) >= 0 && visited[i][j - 1] == 0 && m[i][j - 1] == 1){
            path.push_back('L');
            visited[i][j] = 1;
            solve(ans, path, visited, m, n, i, j - 1);
            path.pop_back();
            visited[i][j] = 0;
        }
        
        
        if((j+1) < n && visited[i][j+1] == 0 && m[i][j+1] == 1){
            path.push_back('R');
            visited[i][j] = 1;
            solve(ans, path, visited, m, n, i, j+1);
            path.pop_back();
            visited[i][j] = 0;
        }
        
        
        if((i-1) >= 0 && visited[i-1][j] == 0 && m[i-1][j] == 1){
            path.push_back('U');
            visited[i][j] = 1;
            solve(ans, path, visited, m, n, i-1, j);
            path.pop_back();
            visited[i][j] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string path = "";
        vector<vector<int>> visited(n, vector<int>(n, 0));
        if(m[0][0]!=0)
        solve(ans, path, visited, m, n, 0, 0);
        return ans;
    }
};


Optimal Approach

#include <bits/stdc++.h>

using namespace std;

class Solution {
  void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis, int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
      int nexti = i + di[ind];
      int nextj = j + dj[ind];
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
        vis[i][j] = 1;
        solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
        vis[i][j] = 0;
      }
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));
      int di[] = {
        +1,
        0,
        0,
        -1
      };
      int dj[] = {
        0,
        -1,
        1,
        0
      };
      if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
      return ans;
    }
};


    
