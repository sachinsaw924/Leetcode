typedef long long ll;
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        // time complexity is O(n)
        //space complexity is O(n)
      int m = nums1.size();
      int n = nums2.size();
      unordered_map<ll,ll>mp;

      for(int &num : nums1)
      {
          mp[num] += n;
      }  
      for(int &num : nums2)
      {
        mp[num] += m;
      } 
         int result = 0 ;
      for(auto &it : mp)
      {
        int num = it.first;
        int freq = it.second;

        if(freq %2 != 0)
        {
            result = result ^ num ;
        }
      }

      return result;
