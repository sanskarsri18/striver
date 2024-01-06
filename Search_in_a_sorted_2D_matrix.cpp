Brute Force Approach

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};


Better Approach

class Solution {
public:

    bool binarySearch(vector<int> arr , int target){
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        int mid = (s + e) / 2;
        while(s <= e){
            if(arr[mid] == target){
                return true;
            }
            else if(arr[mid] > target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = (s + e) / 2;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        for(int i = 0; i < r; i++){
            if(matrix[i][0] <= target && matrix[i][c-1] >= target){
                return binarySearch(matrix[i], target);
            }
        }
        return false;
    }
};


Optimal Approach

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        int s = 0;
        int e = (r*c) - 1;
        int mid = (s + e) / 2;
        while(s <= e){
            if(matrix[mid/c][mid%c] == target){
                return true;
            }
            else if(matrix[mid/c][mid%c] > target){
                e = mid - 1; 
            }
            else{
                s = mid + 1;
            }
            mid = (s + e) / 2;
        }
        return false;
    }
};
