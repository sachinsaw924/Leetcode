// is question me bhut jaruri hai dry run krna agr nhi krega to wapas bhul jayega isliye  dry run kr lena 
// dusra maine yanhainitial approach laga liya tha  lekin bad me mughe samajh nhi aaya tha aage kaise kru 
// Revision mark : 0 
// T.c O ( n) 
// S.c O(n)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int> maxRight(n);
        maxRight[n-1] = n-1;

        for(int i = n-2 ; i>=0 ; i--)
        {
            int maxRightInd = maxRight[i+1];
            int maxRightElem = s[maxRightInd];

            maxRight[i] = (s[i]> maxRightElem ? i : maxRightInd);
        }
         
         for(int i = 0 ;i<n;i++)
         {
            int maxRightInd = maxRight[i];
            int maxRightEle = s[maxRightInd];
            if(s[i]< maxRightEle)
            {
                swap(s[i],s[maxRightInd]);
                 return stoi(s);
            }
            
         }
        return num;
    }
};
