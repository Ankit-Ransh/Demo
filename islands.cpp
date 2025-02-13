//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU {
  
public:
    vector<vector<pair<int, int>>> parent;
    vector<vector<int>> rank;
    
    DSU(int n, int m) {
        parent = vector<vector<pair<int, int>>> (n, vector<pair<int, int>> (m, {0, 0}));
        rank = vector<vector<int>> (n, vector<int> (m, 0));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                parent[i][j] = {i, j};
                rank[i][j] = 0;
            }
        }
    }   
    
    pair<int, int> findParent(pair<int, int> node) {
        if(parent[node.first][node.second] == node) 
            return node;
        return parent[node.first][node.second] = findParent(
            parent[node.first][node.second]);
    }
    
    void unionByRank(pair<int, int> u, pair<int, int> v) {
        u = findParent(u);
        v = findParent(v);
        
        if(rank[u.first][u.second] <= rank[v.first][v.second]) {
            rank[v.first][v.second]++;
            parent[u.first][u.second] = v;
        }
        else {
            rank[u.first][u.second]++;
            parent[v.first][v.second] = u;
        }
    }
    
};

class Solution {
  
public:
    // Function to find the number of islands.
    const int N = 8;
    const vector<int> dx = {0, 0, 1, -1, -1, -1, 1, 1};
    const vector<int> dy = {-1, 1, 0, 0, -1, 1, 1, -1};
    
    bool isSafe(int r, int c, int n, int m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        DSU dsu(n, m);
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j]) {
                    for(int k = 0; k < N; ++k) {
                        int r = i + dx[k], c = j + dy[k];
                        if(isSafe(r, c, n, m) && grid[r][c]) 
                            dsu.unionByRank({r, c}, {i, j});
                    }
                }
            }
        }
        
        int island = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(dsu.findParent({i, j}) == pair<int, int>(i, j)) island++;
            }
        }
        
        return island;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends