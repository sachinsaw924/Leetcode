

 // solution 1 


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        vector<int>prefixKaMax(begin(arr),end(arr));
        vector<int>suffixKaMin(begin(arr),end(arr));

        for(int i=1 ; i < n ;i++)
        {
           prefixKaMax[i] = max(prefixKaMax[i-1],prefixKaMax[i]);
        }


        for(int i = n-2 ; i>=0 ;i--)
        {
            suffixKaMin[i] = min(suffixKaMin[i],suffixKaMin[i+1]);
        }

         int  chunk = 0 ; 
        for(int i = 0 ; i < n ; i++)
        {
            int maxi = i==0 ? -1 : prefixKaMax[i-1];
            int mini = suffixKaMin[i];
            if(maxi<mini)
            {
                chunk++;
            }

        }
        return chunk;
    }
};

 








// solution 2 
 


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int cumulativeSum = 0 ;
        int OriginalSum = 0 ; 
        int chunk = 0 ; 

        for(int i = 0 ; i < n ; i++)
        {
            cumulativeSum +=arr[i];

            OriginalSum += i ;

            if(OriginalSum == cumulativeSum)
            {
                chunk++;
            }
        }

        return chunk ;
    }
};





// solution 3
// boht jyda observation chayie bhaii isme 


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int maxi = -1;
        int chunk = 0 ; 

        for(int i = 0 ; i < n ; i++)
        {
            maxi = max(maxi,arr[i]);

            if(maxi == i)
            {
                chunk++;
            }
        }

        return chunk;
    }
};
