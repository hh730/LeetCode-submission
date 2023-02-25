class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int size=prices.size();
        int maxProfit=0;
        int minPrice=INT_MAX;
        int currProfit=0;
        for(int i=0;i<size;i++){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }
            currProfit=prices[i]-minPrice;
            maxProfit=max(currProfit,maxProfit);
        }
        return maxProfit;
    }
};