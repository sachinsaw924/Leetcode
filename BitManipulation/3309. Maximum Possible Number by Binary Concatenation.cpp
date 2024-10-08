
// Modified by me which is not in comment section 
// do chij sikha pehle num to binary  then binary to int
// ek chiz dhayn rakhna ki num ko jab string me convert kr rha hoga s[i]+'0'
// wapas jab num  me ke liye s[i]-'0'
//Revision mark : 0
 class Solution {
public:
    // Num -> Binary
    // string convert(int num) {
    //     if (num == 0) return "0";
    //     string binary = "";
    //     while (num > 0) {
    //         binary = (num%2 == 0 ? "0" : "1") + binary;
    //         num /= 2;
    //     }
    //     return binary;
    // }

    string convert(int num)
    {
        if(num==0) return "0";
        string binary = "";
        while(num>0)
        {
            binary.push_back((num&1)+'0');
            num = num >> 1;
        }
        reverse(binary.begin(),binary.end());
        return binary;
    }

    // Binary -> int
    // int decimal(string s){
    //     int res =0;
    //     for(int i=0; i < s.length(); i++) {
    //         res = res*2 + (s[i]-'0');
    //     }
    //     return res;
    // }

    int decimal(string s)
    {
        int sum = 0;
        int j = 0;
        for(int i=s.size()-1;i>=0;i--)
        {
            sum = sum + (s[i]-'0')*(1<<j);
            j++;
        }
        return sum;
    }

    int maxGoodNumber(vector<int>& nums) {
        string a = convert(nums[0]);
        string b = convert(nums[1]);
        string c = convert(nums[2]);
        // Returning Max from all Permutations
        return max({
            decimal(a+b+c),
            decimal(a+c+b),
            decimal(b+a+c),
            decimal(b+c+a),
            decimal(c+a+b),
            decimal(c+b+a)
        });
    }
};






/// If we have more than 1 input 


class Solution {
public:
    // Convert integer to binary string
    string convert(int num) {
        if (num == 0) return "0";
        string binary = "";
        while (num > 0) {
            binary.push_back((num & 1) + '0');
            num = num >> 1;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }

    // Convert binary string to integer
    int decimal(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum = sum * 2 + (s[i] - '0');
        }
        return sum;
    }

    // Recursive function to generate all permutations of binary strings
    void permute(vector<string>& binaries, int l, int r, int& maxVal) {
        if (l == r) {
            // Combine all binary strings and convert to decimal
            string combined = "";
            for (string bin : binaries) {
                combined += bin;
            }
            maxVal = max(maxVal, decimal(combined)); // Update max value
        } else {
            for (int i = l; i <= r; i++) {
                swap(binaries[l], binaries[i]);
                permute(binaries, l + 1, r, maxVal);
                swap(binaries[l], binaries[i]); // backtrack
            }
        }
    }

    int maxGoodNumber(vector<int>& nums) {
        vector<string> binaries;
        
        // Step 1: Convert all numbers in nums to binary strings
        for (int num : nums) {
            binaries.push_back(convert(num));
        }

        int maxVal = 0;
        // Step 2: Generate all permutations of binary strings
        permute(binaries, 0, binaries.size() - 1, maxVal);

        // Step 3: Return the maximum decimal value from all permutations
        return maxVal;
    }
};

