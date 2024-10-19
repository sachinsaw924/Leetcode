// hint liya hu thora or clearity ke sath code krne ki jarurat hai 
class Solution {
public:
   string reverseString(string s)
   {
    reverse(s.begin(),s.end());
    return s;
   }
   string invertString(string s)
   {
    int n = s.size();
     

    for(int i= 0;i<n;i++)
    {
        if(s[i]=='0') s[i]='1';
        else
        s[i]='0';
    }
     return s;
   }
   
  
    char findKthBit(int n, int k) {
        string ans = "0";
        for(int i = 1 ;i<n;i++)
        {
            ans = ans +"1"+ reverseString(invertString(ans));
        } 
        cout<<ans<<endl;
        
        return ans[k-1];

    }
};
