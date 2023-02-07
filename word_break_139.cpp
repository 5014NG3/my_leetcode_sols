class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        
        unordered_set<string> os(wordDict.begin(), wordDict.end());
        vector<bool> f(s.length() + 1);

        //empty string
        f[0] = true;

        for(int i = 1; i <= s.size(); i++){
            //i = current lenght of string we are checking for
            for(int j = 0; j < i; j++){

                //j is the current starting index of substr we are 
                //looking at, j goes from 0 to i, i-j is the lenght of 
                //the sub string
                if(f[j] && os.find(s.substr(j, i-j)) != os.end()){
                    //if we find a match then the dp for the current
                    //length of 

                    //f[j] is the current starting substr index, 
                    //then we get the length using i-j

                    //this determines that
                    //substr between j and i is legit
                    
                    f[i] = true;
                    break;
                }
            }
        }

        return f[s.size()];

        
    }
};