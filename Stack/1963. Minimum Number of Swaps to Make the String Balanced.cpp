/// Bhut effor mara pr obsevation nhi kr paya last me solution  dekha hu 
// kyun ham yanha 2 se divide kr rhe hai ye pta hona chayie dusri bat bs hum sirf yanha opening bracket count kr rhe hai
// revision mark : 0
// T.c O(n)
// s.c O(n)

// approach 1

class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int n = s.size();
        for(int i = 0 ;i<n;i++)
        {
            if(!st.empty() && s[i]==']' && st.top()=='[')
            {
                st.pop();
            }
            else if(s[i]=='[')
            {
                st.push(s[i]);
            }
                 
        }
        return (st.size()+1)/2;
    }
};



/// approach 2

// dry run "]][][[[]]["
 class Solution {
public:
    int minSwaps(string s) {
        int size= 0;
        for(char &ch : s)
        {
            if(ch=='[')
            {
                size++;
            }
            else if(size>0)
            {
                size--;
            }
        }
        return (size+1)/2;
    }
};




