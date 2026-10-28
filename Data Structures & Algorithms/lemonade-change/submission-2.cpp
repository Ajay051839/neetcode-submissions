class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int currChange=0;
        int n=bills.size();
        int five=0;
        int ten=0;
        int twenty=0;
        for(int i=0;i<n;i++){
            if((bills[i]-5)>currChange)return false;
            else{
                if(bills[i]==5){
                    five++;
                }else if(bills[i]==10){
                    if(five){
                        five--;
                        ten++;
                    }
                    else{
                        return false;
                    }
                }else if(bills[i]==20){
                    if(five && ten){
                        five--;
                        ten--;
                        twenty++;
                    }else if(five>=3){
                        five-=3;
                        twenty++;
                        }else{
                        return false;
                    }
                }
                currChange+=5;
            }
        }
        return true;
    }
};