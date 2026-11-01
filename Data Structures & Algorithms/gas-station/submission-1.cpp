class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalGas=0;
        int totalCost=0;
        int diff=INT_MIN;
        int indx=-1;
        for(int i=0;i<n;i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
        }
        if(totalCost>totalGas)return -1;
        for(int i=n-1;i>=0;i--){
            if((gas[i]-cost[i])>=diff){
                diff=(gas[i]-cost[i]);
                indx=i;
            }
        }
        return indx;
    }
};
