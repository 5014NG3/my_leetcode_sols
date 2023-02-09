class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t reverse = 0;


        for(int i = 0; i < 32; i++){
            
            //check if n && 1 shifted to the left
            //i times is not 0
            if( (n & (1 << i)) ){
                //31 = 32-1, bits to shift

                //reverse is or'd with the 
                //the current shifted value
                //shift bits from right 
                //to leftmost position
                reverse |= 1 << (31-i);

            }


        }

        return reverse;
        
    }
};