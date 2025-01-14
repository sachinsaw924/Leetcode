class Solution {
public:
    // solve it by own secondly little mistake i had done that i had not iterate
    // it till 50 and after all everything is correct

    // time complexity is O(n) * O(50) = O(n)*O(1)

    // space complexity is O(n)
    int solve(vector<bool>& vecA, vector<bool>& vecB) {
        int count = 0;

        for (int i = 1; i <= 50; i++) {
            if (vecA[i] == true && vecB[i] == true) {
                count++;
            }
        }

        return count;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> result;
        vector<bool> vecA(50, false);
        vector<bool> vecB(50, false);
        int n = A.size();

        for (int i = 0; i < n; i++) {
            int valueA = A[i];
            int valueB = B[i];
            vecA[valueA] = true;
            vecB[valueB] = true;

            int ans = solve(vecA, vecB);

            result.push_back(ans);
        }

        return result;
    }
};


/// by sir 


// time complexity O(n*n*n) 
// space complexity O(1)


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>result;
        int count = 0 ; 
        int n = A.size();


        for(int i = 0 ; i < n ; i++)
        { 
            count = 0 ;
            for(int A_i = 0 ; A_i <=i ; A_i++)
            {   
                for(int B_i = 0 ; B_i<=i ; B_i++)
                {
                    if(A[A_i] == B[B_i])
                    {
                        count++;
                        break;
                    }
                }
            }
            result.push_back(count);
        }

        return result;
    }
};






//   by sir 
// time complexity O(n)
// space complexity O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp;
        int n = A.size();
        vector<int>result(n);

          
        int count = 0 ;

        for(int i = 0 ; i < n ; i++)
        {

            mp[A[i]]++;

            if(mp[A[i]] == 2)
            {
                count++;
            }

            mp[B[i]]++;
            if(mp[B[i]] == 2)
            {
                count++;
            }

            result[i] =  count;
        }

        return result;
    }
};

// time complexity O(n)
// space complexity O(n)

