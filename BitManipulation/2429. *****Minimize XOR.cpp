
// time complexity is O(logn) 
// because total number of bits in 1 integer is logn 

class Solution {
public:
    int countSetBit(int num) {

        int count = 0;

        while (num!= 0) {
            num= num & (num - 1);
            count++;
           
        }
        return count;
    }

    bool isSet(int &x , int bit)
    {
        return x & (1 << bit);
    }

    void setBit(int &x , int bit)
    {
        x = x | (1<<bit);
    }

    void unSet(int &x , int bit)
    {
        x =  x &  ~(1<<bit);
    }

    
    int minimizeXor(int num1, int num2) {
        int currentSetBit = countSetBit(num1);
        int requiredSetBit = countSetBit(num2);

        int x = num1;
        int bit = 0 ;

        if (currentSetBit < requiredSetBit) {

            while (currentSetBit < requiredSetBit) {
                if(!isSet(x , bit))
                {  
                    setBit(x,bit);
                    currentSetBit++;
                }
                bit++;
            }
        } 
        else if(currentSetBit> requiredSetBit)
        {

            while(currentSetBit> requiredSetBit)
            {
                if(isSet(x,bit))
                {
                    unSet(x,bit);
                    currentSetBit--;
                }
                bit++;
            }
        }

        return x ;
    }
};
