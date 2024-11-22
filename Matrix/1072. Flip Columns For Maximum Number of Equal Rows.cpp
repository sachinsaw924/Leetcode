


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





// thora effiecient hai pehle wale question se lekin space hai wo jyada le rhe hai 
// observing question ache se observe kre to ho jaega 


class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxValues = 0 ;


        unordered_map<string,int>mp; // O(m*n)

        for(auto &row : matrix) // O(m)
        {
            string rawKaNature = "";
            int value = row[0];

            for(int col = 0 ; col < n ;col++) // O(n)
            {
                rawKaNature +=(row[col] == value) ? "S" : "B";
            }
            mp[rawKaNature]++;

        }
           for(auto &it : mp)
            {
                maxValues = max(maxValues , it.second);
            }
            return maxValues ;

   }
};
