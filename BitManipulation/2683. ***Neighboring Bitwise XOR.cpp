
/// golden approach is if  x^y = z  , y^z = x , z^x = y remeber this rule it is important from this derived
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        vector<int>original(n);
        original[0] = 0 ;

        for(int i = 0 ; i < n-1;i++)
        {
            original[i+1] = derived[i] ^ original[i];
        }

        if(original[n-1] ^ original[0] == derived[n-1]) // last it is condition is given 
        {
            return true;
        }

        original[0] = 1;
        for(int i = 0 ; i < n-1;i++)
        {
            original[i+1] = derived[i] ^ original[i];
        }

        if(original[n-1] ^ original[0] == derived[n-1])
        {
            return true;
        }

        return false;
    }
};



// approach 2

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int value = 0;

        // dekho yanha har number do element ka xor lene se bana
        // derived [] = { a , b, c , d, e}
        // original[] = { a^b,b^c,c^c,d^e,e^a} // to yanah dekhega har element
        // do bar appear ho rha hai to overall xor lega to zero aana chayie agr
        // aa gya to original derived kr lenge nhi to krn payenege simpy yanha
        // count krne se bhi ho jaega kitna count hai 1 number ka

        int n = derived.size();

        for (int i = 0; i < n; i++) {
            value = value ^ derived[i];
        }

        if (value == 0) {
            return true;
        }

        return false;
    }
};







