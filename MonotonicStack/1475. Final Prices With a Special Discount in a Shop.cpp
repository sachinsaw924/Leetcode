

// Tc O(2*n)  // do bar hi visit kr rhe hai ek bar iterate krte waqt or dusra pop krte waqt
// sc o(n )


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int>result(begin(prices),end(prices));
        stack<int>st;
        for(int i = 0 ; i < n  ; i++)
        {
            while(!st.empty() && prices[i] <= prices[st.top()])
            {
                result[st.top()] = result[st.top()]-prices[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
