class Solution {
public:
    string longestPalindrome(string s) {

        //babad -> aba

        int left,right;
        int long_start = 0;
        int max_len = 1;
        int cur_len;
        const int n = s.size();


        for(int i = 0; i < n; i++){

            right = i;

            //find furthest point where start is equal the right
            //this is for cases like abbba, all the centers are equal
            while(right < n && (s[i] == s[right]) ){
                
                right++;
                
            }
            // s[i, right - 1] inclusive are equal characters e.g. "aaa"

            //set the left index to be before starting index i 
            //because we know that s[i] != s[right]


            //# while s[left] == s[right], s[left, right] inclusive is palindrome e.g. "baaab"
            left = i - 1;

            //check if the parts that are equal are surround 
            // by different letters that are equal
            //now we do the expansion, where we move left and right simultaneiously
            //until they are not equal to eachother

            while( left >= 0 && right <n && (s[left] == s[right]) ){
                left -=1;
                right +=1;
                       
            }


            //# s[left + 1, right - 1] inclusive is palindromic
            //this was the last equal left,right pair before they werent equal
            //right - 1 - (left + 1) + 1 == length
            cur_len = right - left - 1;

            

            if(cur_len > max_len){
                max_len = cur_len;

                //longest palindrome starts at left + 1
                long_start = left + 1;

            }






            





        } 

        

        return s.substr(long_start,  max_len);
        
    }
};