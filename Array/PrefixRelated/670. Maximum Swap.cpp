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













// bhaii dekh isko ro revise krna hi parega bina revise kiye krna muskil hi isko 
// isme jo maxRight ke ander jo access kr rhe hai wo thora difficult hai km se km 5 -6  dry run kr lena 
// yanha pr time complexity or space complexity dono reduce ho gya hai 



class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();

        vector<int>maxRight(10,-1) ; // 0,1,2,.......10

        for(int i = 0 ;i<n;i++)
        {
            int currChar = s[i];
            int currDigit = s[i]-'0';
            maxRight[currDigit] = i ;
        }

        for(int i =  0 ;i<n;i++)
        {
            int currChar = s[i];
            int currDigit = s[i]-'0';

            for(int digit = 9 ; digit>currDigit ; digit --)
            {
                if(maxRight[digit]>i)
                {
                    swap(s[i],s[maxRight[digit]]);
                    return stoi(s);
                }

            }
        }
        return num ;
    }
};
