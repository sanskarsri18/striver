Naive Approach

class Solution {
public:
    int nCr(int n , int r){
        long long res = 1;
        for(int i = 0 ; i < r; i++){
            res = res * (n - i);
            res = res / (i + 1);
        }
        return (int)(res);
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1 ; i <= numRows; i++){
            vector<int> row;
            for(int j = 1 ; j <= i; j++){
                row.push_back(nCr(i-1 , j - 1));
            }
            ans.push_back(row);
        }
        return ans;
    }
};
1. Define a function to calculate nCr (combinations).
2. Initialize a variable 'res' to store the result.
3. Loop through each value of i from 0 to r-1.
4. Update 'res' by multiplying it with (n - i).
5. Update 'res' by dividing it by (i + 1).
6. Return the result as an integer.
7. Define a function to generate Pascal's Triangle up to numRows.
8. Initialize a 2D vector 'ans' to store the result.
9. Loop through each row from 1 to numRows.
10. Initialize a vector 'row' to store the elements of the current row.
11. Loop through each element in the current row (from 1 to i).
12. Calculate the value using nCr and push it into the 'row'.
13. Push the current 'row' into the result 'ans'.
14. Return the final result 'ans'.



Optimal Approach

class Solution {
public:

    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        for(int col = 1 ; col < row ; col++){
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 1 ; i <= numRows ; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};

    // Step 1: Define a function to generate a single row of Pascal's Triangle.
        // Step 2: Calculate each element in the row using the nCr formula.
        // Step 3: Return the generated row.
    // Step 4: Define a function to generate Pascal's Triangle up to numRows.
        // Step 5: Generate each row and add it to the result vector.
        // Step 6: Return the final result.

