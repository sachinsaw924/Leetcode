
// similar to koko eating bananas
// T.C O(nlogn)
// ceil alternate sum +=(products + x -1)/x;
// ceil ek slow function hai isliye

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
           int m = quantities.size();
        int low = 1;
        long long high = *max_element(quantities.begin(),quantities.end());
        int c ;

        
        while(low <= high ) // O(logn)
        {   long long  mid = low + (high-low)/2;
             long long  rh = 0;
            for(int i = 0 ;i < m ;i++) // O(n)
            {
                rh += quantities[i]/mid +( quantities[i]% mid !=0);
               
            }


            if(rh>n)
            {
                low = mid +1;
            }
            else
            {
                c = mid;
                high = mid -1;
            }
        }
        return c;
    }
};
