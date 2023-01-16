class Solution {
public:
    int lengthOfLongestSubstring(string s) {



        std::map<char,int> lookup;


        int left = 0;
        int right = 0;
        int max = 0;
        int len = 0;

        const int size = s.size();


  

        while (right < size){
            
            //if the value doesn't exist, the add it to the table
            //this condition determines the window size
            //by looking ahead we are able to see if we have 
            //already seen the value or are inserting a new value
            //if the value has already been seen, then we are 
            //kind of popping values in the front, while simulteanously
            //having knowledge of the future character and determining
            //if we want to insert of disregard future characters
            //based on if we have already seen them
            if(lookup.count(s[right]) == 0){
                lookup.insert ( std::pair<char,int>(s[right++],1) );

                len = lookup.size();

                if(len > max){
                    max = len;
                }
                

            }

            //delete the value from the last encountered location 
            //this cut off the repetition
            // ex : pwwkew -> pw|wkew, make left go to the second occurence of w
            //p: right = 1, w:right = 2, w: erase p(left = 0, then left+=1), k:right = 3, e:right = 4, w: erase w(left = 1, then left +=1)
            //this is where the window is formed
            
            else{


                lookup.erase (lookup.find(s[left++]));


            }


        }



        
        return max;
    }
};