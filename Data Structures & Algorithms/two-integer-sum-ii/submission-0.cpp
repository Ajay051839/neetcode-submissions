class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int k=numbers[i];
            int rem=target-k;
            int start=i+1;
            int end=n-1;
            while(start<end){
                int mid=(start+end)/2;
                if(numbers[mid]==rem){
                    ans.push_back(++i);
                    ans.push_back(++mid);
                    break;
                }else if(numbers[mid]>rem){
                    end--;
                }else if(numbers[mid]<rem){
                    start++;
                }
            }
        }
        return ans;
    }
};
