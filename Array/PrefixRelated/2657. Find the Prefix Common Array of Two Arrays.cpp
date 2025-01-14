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
