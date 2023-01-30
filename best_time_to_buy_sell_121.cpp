class Solution {
public:
    int maxProfit(vector<int>& prices) {

        //set the buy index to be the first index

        int buy = 0;

        //assume profit is 0
        int val = 0;


        for(int i = 0; i < prices.size(); i++){
            
            //if the current price on a given day is less than the 
            //the previou buy day, change the buy day
            if(prices[i] < prices[buy]){
                buy = i;
            }

            //update profit if greater than previous

            if(prices[i] - prices[buy] > val){
                val = prices[i] - prices[buy];
            }

        }






        
        return val;
    }