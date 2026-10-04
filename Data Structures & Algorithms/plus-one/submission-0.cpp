class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=0;
        reverse(digits.begin(),digits.end());
        for(int i=0;i<n;i++){
           if(digits[i]!=9 && carry==0){
            digits[i]=digits[i]+1;
            break;
           }else if(digits[i]==9 && carry==0){
            carry=1;
            digits[i]=0;
           }else if(digits[i]==9 && carry==1){
             digits[i]=0;
           }else if(digits[i]!=9 && carry==1){
            carry=0;
            digits[i]=digits[i]+1;
            break;
           }
        }
        if(carry){
            digits.push_back(1);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
