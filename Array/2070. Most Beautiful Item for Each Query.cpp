
// I had done this it is just passed only test case solution it does not pass any solution
// fault of this solution is I had created aaray so for large value of this it is inefficient
// Time Complexity: 
 
// Time Complexity:O(nlogn+maxiQuery+q)
// Space Complexity: O(maxiQuery+q+n)


 class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        int maxiQuery = *max_element(begin(queries), end(queries));   
        sort(begin(items), end(items));  

      
        vector<int> itemsStore(maxiQuery + 1, 0);   
        
        int j = 0;   
        int currentMaxBeauty = 0;

        for (int i = 0; i <= maxiQuery; i++) {
            
            while (j < items.size() && items[j][0] <= i) {
                currentMaxBeauty = max(currentMaxBeauty, items[j][1]);   
                j++;
            }
            itemsStore[i] = currentMaxBeauty;   
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int queryNumber = queries[i];
            ans.push_back(itemsStore[queryNumber]);  
        }
        
        return ans;
    }
};


//t.c O(nlogn+olgm)

class Solution {
public:
     int customBinarySearch(vector<vector<int>>& items, int queryPrice)
     {
        int l = 0 ;
        int r = items.size()-1;
        int mid ;
        int maxBeauty = 0 ;

        while(l<=r)
        {
          mid = l+(r-l)/2;

          if(items[mid][0]>queryPrice)
          {
            r = mid-1;
          }
          else
          {
            maxBeauty =max(maxBeauty, items[mid][1]);
            l = mid +1;
          }
        }
return maxBeauty;
         
     }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();
        sort(begin(items),end(items));
        vector<int>result(m);
        int currentMaxBeauty = 0;


        for(int i=0;i<n;i++)
        {
          currentMaxBeauty = max(currentMaxBeauty,items[i][1]);
          items[i][1] = currentMaxBeauty;
        }

        for(int j = 0;j<m;j++)
        {
            int queryPrice = queries[j];
            result[j] = customBinarySearch(items,queryPrice);

        }
        return result;
    }
};



