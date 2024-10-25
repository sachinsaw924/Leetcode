


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

       return result;     
    }
};



