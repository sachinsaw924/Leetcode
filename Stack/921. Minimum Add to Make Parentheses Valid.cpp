
// T.c O(n)
// s.c O(n)
// approach 1

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char>st;
        int open = 0;

        for(int i = 0 ;i<n;i++)
        {
            if(!st.empty() && s[i]==')' && st.top()=='(')
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



// approach 2  


// took hint
// T.c O(n)

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        
        int open = 0;
        int close = 0;

        for(int i = 0 ;i<n;i++)
        {
            
           if(s[i]=='(')
           {
            open++;
           } 
           else if(s[i]==')' && open>0)
           {
            open--;
           }
           else
           {
            close++;
           }
        }
         return (close+open);
    }
};
