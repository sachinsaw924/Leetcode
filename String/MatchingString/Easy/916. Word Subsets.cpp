


class Solution {
public:
    bool isSubset(vector<int>& freq2, vector<int>& freq1) {

        for (int i = 0; i < 26; i++) {
            if (freq2[i] > freq1[i]) {
                return false;
            }
        }

        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<string> result;
        vector<int> freq2(26);
        // time complexity O(n*l)  n = no of words   &&  l = length of word in
        // both the loops space compexity is constant as we are using only 26
        // length of array

        for (auto& word : words2) {
            int temp[26] = {0};

            for (auto& ch : word) {
                temp[ch - 'a']++;
                freq2[ch - 'a'] = max(temp[ch - 'a'], freq2[ch - 'a']);
            }
        }

        for (string& word : words1) {
            vector<int> freq1(26, 0);

            for (auto& ch : word) {
                freq1[ch - 'a']++;
            }

            if (isSubset(freq2, freq1)) {
                result.push_back(word);
            }
        }

        return result;
    }
};
