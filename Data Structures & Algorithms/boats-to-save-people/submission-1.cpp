class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int start=0;
        int end=n-1;
        sort(people.begin(),people.end());
        int ans=0;
        while(start<=end){
            if(people[end]==limit){
                ans++;
                end--;
            }else if(start!=end && (people[start]+people[end])<=limit){
                start++;
                end--;
                ans++;
            }else if(start!=end && people[end]<limit && (people[start]+people[end])>limit){
                end--;
                ans++;
            }else if(start==end){
                ans++;
                start++;
                end--;
            }
        }
        return ans;
    }
};