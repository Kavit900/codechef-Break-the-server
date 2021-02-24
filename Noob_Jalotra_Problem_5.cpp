#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int nax = 1e+5 + 5;
vector<pair<int, int>>tree[nax];
vector<vector<int>>g;
vector<ll>path_lengths(nax);


// It computes the path-lengths from root to every other node(u) in the tree
void dfs(int node, int parent, ll path_len_till_now){
    path_lengths[node] = path_len_till_now;
    
    for(pair<int, int>neighbour : tree[node]){
        if(neighbour.first == parent)continue;
        dfs(neighbour.first, node, path_len_till_now + 1ll * neighbour.second);
    }
}

// Finds the LCA of two nodes in O(log(n))
// From Cp-Algorithms (https://cp-algorithms.com/graph/lca_binary_lifting.html)
struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

void test_case(){
    
    int n, q, r;
    cin >> n >> q >> r;
    r--;
    
    // Clear the Tree and Graph for each testcase
    for(int i = 0; i < nax; i++){
        tree[i].clear();
    }
    for(vector<int>&x : g){
        x.clear();
    }
    g.resize(n);
    
    // Build Tree and graph
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        tree[u].push_back(make_pair(v, w));
        tree[v].push_back(make_pair(u, w));
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    // Algorithm 
    /*
     * We know that the the shortest path from a node u to a node v is unique.
     * And it has to go though the LCA(u, v).
     * Then the path_length(u, v) = path_length(root, u) + path_length(root, v) - 2 * path_length(root, lca(u, v))
     */
     
     // Precomputing the Path-Lengths
     dfs(r, -1, 0);
    
    // Finding LCA - Using a Seg-Tree
    struct LCA here(g, r);
    
     for(int qq = 0; qq < q; qq++){
         int u, v;
         cin >> u >> v;
         u--, v--;
         int lca = here.lca(u, v);
         
         ll ans = path_lengths[u] + path_lengths[v] - 2 * path_lengths[lca];
         cout << ans << '\n';
     }
    
    
    
} 


int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        test_case();
    
    return 0;
} 


 
