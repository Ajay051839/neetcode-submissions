class Solution {
public:
    int hammingWeight(uint32_t n) {
      int checkBit=1;
      int cnt=0;
      while(n){
       if(n&checkBit)cnt++;
       n=n>>1;
      }
      return cnt;

    }
};
