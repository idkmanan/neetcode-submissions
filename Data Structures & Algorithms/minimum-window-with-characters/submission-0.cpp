class Solution {
public:
    bool check(unordered_map<char,int>& mps, unordered_map<char,int>& mpt){
        for(auto [c, cnt] : mpt){
            if(mps[c] < cnt) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n=s.size(), m=t.size();
        unordered_map<char, int> mpt, mps;
        for(char c : t) mpt[c]++;
        int i=0,j=0;
        int len=INT_MAX,idx=0;
        while(j<n){
            mps[s[j++]]++;
            while(check(mps,mpt)){
                if(j-i < len){
                    len = j-i;
                    idx = i;
                }
                mps[s[i++]]--;
            }
        }
        return len==INT_MAX? "" : s.substr(idx, len);
    }
};
