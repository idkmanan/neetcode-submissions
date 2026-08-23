class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gs = accumulate(gas.begin(), gas.end(), 0);
        int cs = accumulate(cost.begin(), cost.end(), 0);

        if(cs > gs) return -1;

        int ans=0;
        int sum=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            sum += (gas[i]-cost[i]);
            if(sum < 0){
                ans = i+1;
                sum = 0;
            }
        }
        return ans;
    }
};
