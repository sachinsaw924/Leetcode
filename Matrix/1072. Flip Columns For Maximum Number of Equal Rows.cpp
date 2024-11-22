


class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();
       int maxValues = 0 ; 

        
        for( vector<int> currRow : matrix) // O(m)
        {
            vector<int>inverted(n); // here we are checking the row not column that why we had taken size of n 


            for(int col = 0  ; col < n; col++) //  O(n)
            {
                inverted[col ] = currRow[col] == 0 ? 1 : 0; // we are checking the inverted row if  it is same then it means by flipping it will same 
            }

            int count = 0 ;

            for(vector<int>row : matrix)
            {
                if(row == currRow || row == inverted) // O(n)
                {
                    count++;
                }
            }
            maxValues = max(count, maxValues);
        }
        return maxValues;

    }
};
