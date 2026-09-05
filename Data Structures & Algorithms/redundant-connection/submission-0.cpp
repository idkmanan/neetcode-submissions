class dsu{
public:
    vector<int> par;
    int comp;

    dsu(int n){
        par.resize(n+1, 0);
        for(int i=1;i<=n;i++) par[i] = i;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu g(n);

        for(auto e : edges){
            int u=e[0], v=e[1];
            if(g.get(u) != g.get(v)){
                g.join(u, v);
            } else {
                return e;
            }
        }
        return {};
    }
};
