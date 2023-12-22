Brute Force Approach

class Solution {
public:
    void generateRow(vector<vector<int>>& matrix , int i){
        int r = matrix.size();
        int c = matrix[0].size();
        for(int j = 0; j < c; j++){
            if(matrix[i][j] != 0)
            matrix[i][j] = -1100;
        }
    }

    void generateCol(vector<vector<int>>& matrix , int j){
        int r = matrix.size();
        int c = matrix[0].size();
        for(int k = 0; k < r; k++){
            if(matrix[k][j])
            matrix[k][j] = -1100;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0){
                    generateRow(matrix, i);
                    generateCol(matrix, j);
                }
            }
        }


        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == -1100){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};





Better Approach

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> row(r);
        vector<int> col(c);

        for(int i = 0 ; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


Optimal approach

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int col0 = 1;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j!=0){
                        matrix[0][j] = 0;
                    }
                    else{
                        col0 = 0;
                    }
                }
            }
        }

        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int j = 0; j < c; j++){
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0){
            for(int i = 0; i < r; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
