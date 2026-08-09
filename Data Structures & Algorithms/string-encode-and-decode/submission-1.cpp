class Solution {
private:
vector<int>v;    
public:

    string encode(vector<string>& strs) {
        string temp="";
        for(auto i:strs){
            temp+=i;
            int k=temp.size();
            v.push_back(k);
        }
       return temp;
    }

    vector<string> decode(string s) {
     vector<string>decoded;
     int start=0;
      for(int i=0; i<v.size(); i++){
        int end=v[i];
        decoded.push_back(s.substr(start,(end-start)));
        start=end;
      }
      return decoded;
    }
};
