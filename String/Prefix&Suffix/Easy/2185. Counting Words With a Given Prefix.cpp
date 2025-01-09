
 // done by myself 
 // time complexity O(n*m)   where n is the number of words and m is the length of pref 
  // space complexity O(1) as here it is not taking any space

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0 ; 
        int n = words.size();

        for(int i = 0 ; i < n ;i++)
        {
            string word = words[i];

            if(word.find(pref) == 0)  // yanah pr word me pref check krna hai na ki ulta 
            {
                count++;
            }
        }
        return count;
    }
};
