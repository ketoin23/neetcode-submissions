class Solution {
    int res = 0;

    void make(int v, vector<int> &p) {
        p[v] = v;
        ++res;
    }

    int getp(int v, vector<int> &p) {
        if(v == p[v])
            return v;
        
        return p[v] = getp(p[v], p);
    }

    void unionp(int u, int v, vector<int> &p) {
        u = getp(u, p);
        v = getp(v, p);

        if(u != v)
            --res;

        p[u] = v;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        res = 0;
        vector<int> p(n, 0);
        for(int i = 0; i < n; i++) {
            make(i, p);
        }

        for(auto i : edges) {
            unionp(i[0], i[1], p);
        }

        return res;
    }
};
