



class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m));

        for (int i = 0; i < n; i++) // transpose the matrix
        {
            for (int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }

        for (vector<char>& row : result) // to rotate it 90 degree matrix
        {
            reverse(begin(row), end(row));
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (result[i][j] == '.') {
                    int stoneKaRow = -1;

                    for (int k = i - 1; k >= 0; k--) {
                        if (result[k][j] == '*') {
                            break;
                        } else {
                            if (result[k][j] == '#') {
                                stoneKaRow = k;
                            }
                        }
                    }
                    if (stoneKaRow != -1) {
                        result[i][j] = '#';
                        result[stoneKaRow][j] = '.';
                    }
                }
            }
        }
               // this is optimized code where we had just simply marked the position of space further we had moved 
        // for(int j = 0 ; j < m ;j++ )
        // {    int spaceBottomRow = n-1 ;
        //     for(int i = n-1 ;i>=0 ;i--)
        //     {
        //        if(result[i][j] == '*')
        //        {
        //         spaceBottomRow = i-1;
        //         continue;
        //        }
        //        if(result[i][j] == '#')
        //        {
        //         result[i][j] = '.';
        //         result[spaceBottomRow][j] = '#';
        //         spaceBottomRow--;

        //        }
        //     }
        // }
        return result;
    }
};
