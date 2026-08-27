class Solution {
public:
    string longestPalindrome(string s) {
        int len = 1, idx = 0, n=s.size();
        for(int i=0;i<n;i++){
            int nlen = 1, nidx = i;
            for(int j=1;j<=n/2;j++){
                if(i+j < n && i-j >= 0 && s[i+j]==s[i-j]){
                    nlen+=2;
                    nidx = i-j;
                } else break;
            }
            if(len < nlen){
                len = nlen;
                idx = nidx;
            }
        }

        for(double i=0.5;i<n;i++){
            double nlen = 0, nidx = i-0.5;
            for(double j=0.5;j<=n/2;j++){
                if(i+j < n && i-j >= 0 && s[i+j]==s[i-j]){
                    nlen+=2;
                    nidx = i-j;
                } else break;
            }
            if(len < nlen){
                len = nlen;
                idx = nidx;
            }
        }
        return s.substr(idx, len);
    }
};
