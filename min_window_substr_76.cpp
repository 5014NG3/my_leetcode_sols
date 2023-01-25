class Solution {
public:
    string minWindow(string s, string t) {
        //exact match for t in s, can be in any order

        //t is in s but has letter sandwiched
        //example: s-> "BSSSSANSSSSSSSC"
        //         t-> "ABC"


        //need to have copy of t in every window
        //iteration as we have to see if every 
        //value in t is in s, we have to "erase"
        //the current character we are looking at
        //from the temp t that is in the current
        //s window we are looking at

        //we have to check if the current window is bound
        //by two values 

        if(s.size() == 0 || t.size() == 0){
            return "";
        }

        //create map for characters
        vector<int> table(128,0);

        //required is length of t
        int required = t.size();

        //insert t into the map
        for(int i = 0; i < required; i++){
            //count the amount of each character in t
            table[t[i]]++;
        }

        int min = INT_MAX;
        int start = 0;
        int left = 0;
        int i = 0;

        while(i <= s.size() && start < s.size()){
            if(required != 0){
                //there are still character that need to be 
                //contained
                if(i == s.size()){
                    //we have reached past the length of string
                    //break out
                    break;
                }

                //decrease the current letter, could be from s or t
                table[s[i]]--;

                //check if it is positive
                if(table[s[i]] >= 0){

                    //if it is positive then that means 
                    //it is from t
                    required--;
                }

                //increment i 
                i++;
            }


            //required == 0, we have seen all of the letters in t

            else{


                //check if length of the current string
                //i - start < min, if so the we have new
                //min = i - start
                //left of official substring is possibly start
                //and min is the length following the starting point
                if(i - start < min){
                    min = i - start;
                    left = start;
                }

                //increment current starting point
                //to check if we can make it positive
            

                table[s[start]]++;

                //if we are able to make the value 
                //in the table positive, this means
                //that we can increment the required
                //because we are looking at a char
                //that is in t

                //it is possible to hit this various time as the 
                //the other condition checks if required != 0
                //however if it is not we keep on incrementing start
                //to check the characters in here
                if(table[s[start]] > 0){
                    required++;
                }

                //no more letters then increment the starting point 
                //of the "substring"
                start++;



            }





        }


        //left is the starting index of the min substring 
        //that contains all of the t chars, and min
        //is the length following this starting index

        return min == INT_MAX? "": s.substr(left,min);


        
    }
};