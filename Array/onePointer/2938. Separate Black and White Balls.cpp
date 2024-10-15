//Revision mark = 0;

// just taken hint 
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long count = 0 ;
        long long ans = 0;

         for(int i = 0;i<n;i++)
         {
            if(s[i]=='0')
            {
                ans = ans + count;
            } else if(s[i]=='1')
            {
                count++;
            }
         }
        return ans ;
    }
};
