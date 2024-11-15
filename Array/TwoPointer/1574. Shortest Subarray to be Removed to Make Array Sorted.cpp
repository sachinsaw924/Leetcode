
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int i = 0 ; 
        int j = arr.size()-1;
        int n = arr.size();

        while(j>0 && arr[j]>=arr[j-1])
        {
            j--;  // piche check krte ja rhe hai janah tak element shorted hoga matalab 
                   // itna to element shorted hoga hi hoga
        }
        int result = j;  // agr zero me pahuch gya to matlab all the element is shorted hai
                         // wrna janha tk pahucha wanha se hum check krna suru krenge
                         // i++ badha badha ke find krenge minimum result ko 


         while(i<j && (i==0 || arr[i]>=arr[i-1]))  // yanah pr i<j isliye kyunki wanha j tak to 
                                                  // se shorted hai bhaii
         {
            
            while(j<n && arr[i]>arr[j])
            {
                j++;
            }
            result = min(result,j-i-1);
             


            i++;
         }
    return result;
    }
};
