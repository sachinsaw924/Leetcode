


// T.C  O ( n * L*L)
// s.c  O(n)

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string>st(begin(folder),end(folder));
        vector<string>result ;

        for(auto currFolder : folder) // O(n)
        {
            bool isPresent = false;
            string tempFolder = currFolder;

            while(!currFolder.empty())  // o(L)
            {
                size_t last_of_slash = currFolder.find_last_of('/');  // O(L)

                currFolder = currFolder.substr(0,last_of_slash);
                if(st.find(currFolder)!=st.end())            //o(L)
                {
                   isPresent = true;
                }
            }
          if(!isPresent)
             {
            result.push_back(tempFolder);
             }
        }











// approach 2



        class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
          sort(begin(folder),end(folder));

          int n = folder.size();
          vector<string>result;
          result.push_back(folder[0]);

          for(int i = 1 ; i < n ;i++)
          {
            string currFolder = folder[i] ;
            string lastFolder = result.back();
            lastFolder += '/';

            if(currFolder.find(lastFolder) != 0)
            {
                result.push_back(currFolder);
            }
          }
          return result;
    }
};

       return result;     
    }
};



