class Solution {
public:
    bool isValid(string s) {

        //if there is an odd number of parens
        //then test fails 

        if(s.size() % 2 != 0){
            return false;
        }


        //means lenght of s is > 1 and even
        //if the previous test fails
        std::stack<char> parens;

        //push first paren to check against the rest
        parens.push(s[0]);

    

        for (int i = 1; i < s.size(); i++){

            if(int(parens.size()) == 0){
                parens.push(s[i]);
            }

            else{
                //there should be symmetry if
                //there is a pair for each of the parens
                if(parens.top() == '(' && s[i] == ')'){
                    parens.pop();
                }
                else if(parens.top() == '[' && s[i] == ']'){
                    parens.pop();
                }
                else if(parens.top() == '{' && s[i] == '}'){
                    parens.pop();
                }
                else{
                    //if there isn't a pair 
                    //push the current value
                    //the matching pair could be coming in the future, or not
                    parens.push(s[i]);
                }

            }



        }


        //if the stack still has values, then there isn't valid parens

        return int(parens.size()) == 0;
        
    }
};