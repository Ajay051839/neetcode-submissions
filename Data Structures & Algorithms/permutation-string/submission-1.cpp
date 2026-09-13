class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2)return false;
        vector<int>alpha(26);
        for(int i=0;i<n1;i++){
            alpha[s1[i]-'a']++;
        }
        for(int i=0;i<n1;i++){
            alpha[s2[i]-'a']--;
        }
        if(alpha==vector<int>(26,0))return true;
        for(int end=n1;end<n2;end++){
            alpha[s2[end-n1]-'a']++;
            alpha[s2[end]-'a']--;
            if(alpha==vector<int>(26,0))return true;
        }
        return false;
    }
};
