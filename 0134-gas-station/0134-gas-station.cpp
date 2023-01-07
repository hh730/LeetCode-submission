class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0;
        int totalCost=0;
        int currCost=0;
        int startPos=0;
        for(int i=0;i<gas.size();i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
            currCost+=gas[i]-cost[i];
            if(currCost<0){
                startPos=i+1;
                currCost=0;
            }
        }
        if(totalGas<totalCost){
            return -1;
        }
        return startPos;
    }
};