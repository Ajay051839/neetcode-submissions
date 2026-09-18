class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({abs(x-arr[i]),arr[i]});
        }
        vector<int>ans;
        while(k){
            auto &[p1,p2]=pq.top();
            ans.push_back(p2);
            pq.pop();
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};