class Solution {
public:






    int numDecodings(string s) {
        
        if(s.empty()){
            return 0;
        }
        

        //assume there is at least
        //one way to decode
        int res = 1;

        //keeps track of previous res
        int pp;
        int n = s.size();

        //keeps track of the current res value
        int cur;

        //go through string from back to front

        //ex 1010

        //
        for(int i = n-1; i>=0; i--){

            //if the current value is zero, then the 
            //current count is zero


            //if we see a 0 reset the cur value
            //i.e invalid sequence

            if(s[i] == '0'){
                cur = 0;
            }
            else{
                //current is the curren res value
                cur = res;
            }

            //if the current value and next value are valid,
            //then increment the current by adding pp
            //which holds the previous res value
            //here s[i+1] can be 0

            if(i < n-1 && (s[i] == '1' || s[i] == '2' && s[i+1] < '7')){

                //add pp to the current value

                //only gets incremented we the sequence is valid
                cur += pp;
   
            }




            pp = res;
            res = cur;

        }






        return res;
        
    }
};