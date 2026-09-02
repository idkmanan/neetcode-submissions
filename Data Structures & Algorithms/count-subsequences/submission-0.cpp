class Solution {
public:
    map<pair<int, string>, int> mp;
    int f(int i,string str, string& s, string& t){
        if(i == s.size()) return str == t;
        if(mp.count({i,str})) return mp[{i,str}];
        return mp[{i,str}] = f(i+1, str+s[i], s, t) + f(i+1, str, s, t);
    }
    int numDistinct(string s, string t) {
        string str;
        return f(0, str, s, t);
    }
};
