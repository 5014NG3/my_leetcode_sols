        // // Prune #1: If there aren't even enough letters in the board to fit word, then return false
        // if((int) word.size() > R * C) {return false;}
        
        // // Prune #2: For each letter, the board must contain at least as many of that letter as word contains
        // int occ[128] = {};
        // for(const auto &v : board) {for(char c : v) {++occ[c];}}
        // for(char c : word) {
        //     if(--occ[c] < 0) {return false;}
        // }
        
        // Prune #3: Find the longest prefix/suffix of the same character. If the longest suffix is longer
        // than the longest prefix, swap the strigns (so we are less likely to have a long prefix with a lot
        // of the same character)
        // int left_pref = word.find_first_not_of(word[0]);
        // int right_pref = word.size() - word.find_last_not_of(word.back());
        // if(left_pref > right_pref) {
        //     reverse(word.begin(), word.end());
        // }



class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0; i < board.size(); i++ ){

            for(int j = 0; j < board[0].size(); j++ ){

                //check every letter in the map until we find the word

                if(board[i][j] == word[0] && dfs(board,word,0,i,j)){
                    return true;
                }
                
            }          
        }





        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int count,int row, int col){


        if( count == word.size()){
            //count is size of the word, i.e
            //out of range so we found it
            return true;
        }


        if(row < 0 || row >= board.size() ){
            return false;
        }

 
        if(col < 0 || col >= board[0].size()){
            return false;
        }       

        if(board[row][col] != word[count]){
            return false;
        }

        //cross out the current char in the map
        //so we can look for the next char in word

        board[row][col] = '0';

        bool res =
        //up
        dfs(board,word, count + 1, row-1,col) ||
        //right
        dfs(board,word, count + 1, row,col+1) || 
        //left
        dfs(board,word, count + 1, row,col-1) ||
        //down
        dfs(board,word, count + 1, row+1,col);


        //revert the character in the board to the char
        //in the word value for the current count value
        board[row][col] = word[count];


        return res;

        



        







    }
};