class dsu{
public:
    vector<int> par;
    int comp;

    dsu(int n){
        par.resize(n,0);
        for(int i=0;i<n;i++) par[i] = i;
        comp = n;
    }

    int get(int node){
        if(node == par[node]) return node;
        return par[node] = get(par[node]);
    }

    void join(int a, int b){
        int sa = get(a), sb=get(b);
        if(sa != sb){
            par[sb] = sa;
            comp--;
        }
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        dsu g(n);
        for(auto& e : edges){
            if(g.get(e[0]) == g.get(e[1])) return false;
            g.join(e[0], e[1]);
        }

        return g.comp==1;
    }
};
