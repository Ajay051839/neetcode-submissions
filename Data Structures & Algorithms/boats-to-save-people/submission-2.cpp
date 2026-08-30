class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int start=0;
        int end=n-1;
        sort(people.begin(),people.end());
        int ans=0;
        while(start<=end){
            if((people[start]+people[end])<=limit){
                start++;
            }
            end--;
            ans++;
        }
        return ans;
    }
};