class Solution {
public:
    bool isPalindrome(string s) {

         if(s.size() == 0 ){
             return true;
         }


         int start = 0;
         int end = s.size()-1;

         char left,right;


         while(start < end){
                left = tolower(s[start]);
                right = tolower(s[end]);

                //check if alphanumeric for left and right
                //move left to the right until it is alpha numeric
                //have to check if start < end every time we move start or end


                while(  !(left <= 'z' &&  left >= 'a' || left <= '9' &&  left >= '0')  && start < end ){
                    start += 1;
                    left = tolower(s[start]);

                    

                }




                while(  !(right <= 'z' &&  right >= 'a' || right <= '9' &&  right >= '0' ) && start < end  ){
                    end -= 1;
                    right = tolower(s[end]);


                }



                if(start < end){
                    if( left == right){
                        start += 1;
                        end -= 1;
                    }
                    else{
                        return false;
                    }

                }

         }

         //if we are able to reach this point then it is valid

         return true;
        
    }
};