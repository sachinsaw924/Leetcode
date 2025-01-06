// taken hint and solve it by myself

class Solution {
public:
    vector<int> minOperations(string boxes) {
       
        int n = boxes.size();
        vector<int>result;


        for(int i= 0 ; i < n ;i++)
        {   int count = 0 ;
            for(int j = 0 ; j < n ; j++)
            {
                     if(boxes[j] == '0' )
                     {
                        continue;
                     }
                     else
                     {
                        count +=abs(j-i);
                     }
                      
            }
            result.push_back(count);
        }
        return result;
    }
};






/// now with the help of codestorywithmik

