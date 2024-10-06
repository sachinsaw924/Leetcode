
 //6-10-24 
// approach 1  using permuataion and combination with the help of backtracking 
//Revision mark : 0

class Solution {
public:
   
    
   void solve(int idx,string s1,string s2,bool &result,int n)
   {
    if(idx == n)
    {
        if(s2.find(s1) != string::npos)
        {
            result = true;
        }
        return ;
    }

    for(int i = idx;i<n;i++)
    {
        swap(s1[i],s1[idx]);
        solve(idx+1,s1,s2,result,n);
        swap(s1[i],s1[idx]);
        if(result == true)
        {
            return ;
        }
        
    }
   }
   
     
    bool checkInclusion(string s1, string s2) {
       int  n = s1.length();
       bool result = false ;
        solve(0,s1,s2,result,n);
        return result;
    }
};




/// approach 2 : using sorting method 
// Revision mark : 0 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n>m)
        {
            return false;
        }
        sort(s1.begin(),s1.end());
        for(int i = 0;i<=m-n;i++)
        {
            string substring = s2.substr(i,n);
            sort(begin(substring),end(substring));
            if(s1 == substring)
            {
                return true;
            }
        }
        return false;
    }
};




/// approach 3  sliding window approach
// here one thing I did not get that how we can compare vector to vector 
//Revision mark : 0 

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m)
        {
            return false;
        }

        vector<int>s1_freq(26,0);
        vector<int>s2_freq(26,0);

        for(char &ch : s1)
        {
            s1_freq[ch-'a']++;
        }
        int j = 0 ;
        int i = 0;
        while(j<m)
        {
            s2_freq[s2[j]-'a']++;
            if(j-i+1>n)
            {
               s2_freq[s2[i]-'a']--;
               i++; 
            }
            if(s1_freq == s2_freq)
            {
                return true;
            }
            j++;

        }

  return false;
    }
};
