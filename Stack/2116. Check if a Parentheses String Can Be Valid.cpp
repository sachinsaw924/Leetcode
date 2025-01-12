

class Solution {
public:
    bool canBeValid(string s, string locked) {

        // in this question i had thought about some approaches  but it pass only some test cases 
        // later i tried to take help from chatgpt as well but i could not understand
        // later i had watched video of mik which had helped me
        // my mistake was instantly changed the locked bracket but i did not consider the case that it 
        // can be used in further case as well there are some silly mistake i also had done

        int n = s.size();
        if(n%2 != 0 ) return false;
        stack<int>open;
        stack<int>openClose;

        for(int i = 0 ; i < n ;i++)
        {
            if(locked[i] =='0')
            {
                openClose.push(i);
            }
            else if(s[i] == '(')  // it means that it is fixed
            {
                open.push(i);
            }
            else if(s[i] ==')')  // it is fixed i had to find valid parenthesis if it is not find here then i will return false
            {
                if(!open.empty())
                {
                    open.pop();
                }
                else if(!openClose.empty())
                {
                    openClose.pop();
                }
                else
                {
                    return false;
                }
            }
        }



        while(!open.empty() && !openClose.empty() && open.top()<openClose.top())
        {
            open.pop();
            openClose.pop();
        }
    
      return open.empty();

    }
};
