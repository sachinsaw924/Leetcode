// solve by looking hint

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size()) 
        {
            return false;
        }

        unordered_map<char,int>mp;
        for(char& ch : s)
        {
            mp[ch]++;
        }

        int oddCount = 0 , evenCount = 0 ;

        for(auto it : mp)
        {
            if(it.second%2 !=0)
            {
                oddCount++;
            }
            else
            {
                evenCount++;
            }

        }

        if(oddCount>k)
        {
            return false;
        }
        return true;
    }
};
