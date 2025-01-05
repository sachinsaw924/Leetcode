

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        // now i am implementing the difference array technqiue
        // 1. first take difference array of each element equal to 0 ;
        // 2. go to each query apply the operation in this array   like below
        // mentiioned arr[left ] += x         if(right+1 <n)    arr[right+1] +=
        // x then find cumulative array

        vector<int>diff(n,0);

        for (auto& query : shifts) {
            int left = query[0];
            int right = query[1];
            int dir = query[2];
            int x ;
            if (dir == 0) {
                x = -1;
            } else {
                x = 1;
            }

            diff[left] += x;
            if (right + 1 < n) {
                diff[right + 1] -= x;
            }
        }

        for(int i = 1 ; i< n ;i++)
        {
            diff[i] +=diff[i-1];  // here i find the cumulative sum 
        }


        // now i will go any array of diff and here i will find to how many times i have to do shift

        for(int i = 0 ; i  < diff.size() ; i++)
        {
            int shift = diff[i] %26;

            if(shift<0)
            {
                shift +=26;
            }
           s[i] = ((s[i]-'a') + shift)%26 + 'a';
            
        }

      return s;
    }
};
