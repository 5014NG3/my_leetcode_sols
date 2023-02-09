class Solution {
public:
    int hammingWeight(uint32_t n) {

        int counter = 0;
        //create mask
        uint32_t mask = 1;
        for(int i = 0; i < 32; i++){
            
            //shift the 1 to the left
            //mask n, and see if the current 
            //position is 1 or not
            if( (n & (mask << i))){
                //count how many times this happens
                counter++;
            }


        }

        return counter;
        
    }
};