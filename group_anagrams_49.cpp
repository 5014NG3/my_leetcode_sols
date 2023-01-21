class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;


        //optimization can be to store the 
        //index instead of the string itself 
        //and then insert the strings into the
        //final result vector

        std::map<string, std::vector<std::string> > table;
        string cur_string;
        string sorted_string;


        for(int i = 0; i < strs.size(); i++){

            cur_string = strs[i];


            sorted_string = cur_string;
            //sort the current string to see if it exists
            // in the lookup table

            std::sort(sorted_string.begin(), sorted_string.end());

            //if it doesn't exist, create an entry
            if(int(table.count(sorted_string) == 0)){

                table[sorted_string] = {cur_string};



            }

            //otherwise append the value to the vector in the table
            //hash list or whatever for collisions
            else{
                table[sorted_string].push_back(cur_string);
            }

        }


        //insert the anagrams vetors into the final result vector
        for (auto const& [key, value] : table) {

            res.push_back(value);
        }   






        return res;
    }
};