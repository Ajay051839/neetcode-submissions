class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int currChange=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if((bills[i]-5)>currChange)return false;
            else{
                currChange+=5;
            }
        }
        return true;
    }
};