
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
