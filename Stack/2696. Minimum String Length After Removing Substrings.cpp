//Approach 1 done silly mistake took lot of time kindly see one more time just to recap 
// similart to valid parenthesis
// T.C O(n)
// S.C O(n)

//Revision mark : 0
class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        stack<int>st;
        for(int i = 0 ;i<n;i++)
        {
            if(!st.empty() && s[i]=='B' && st.top()=='A')
            {
                st.pop();
            }else if (!st.empty() && s[i]=='D' && st.top()=='C')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.size();
    }
};





// appraoach 2 
// isko sir ne karaya hai 
// ek bar phir se revisit krna hai 
// Revision mark : 0
//T.c  O(n)
// S.c O(n)

// Read and write method 

class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        int i = 0;
        int j = 1;
        while(j<n)
        {
            if(i<0)
            {
                i++;
                s[i]=s[j];
            }
            else if((s[i]=='A' && s[j]=='B') || (s[i]=='C' && s[j]=='D'))
            {
                i--;
            }
            else
            {
                i++;
                s[i]=s[j];
            }
            j++;
            
        }
        return i+1;
    }
};










