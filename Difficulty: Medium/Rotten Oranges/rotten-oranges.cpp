//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
         int onse = 0;
        
        for(auto i : mat) for(auto j : i) onse += j == 1;
        
        
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>>q;
        
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
            if(mat[i][j] == 2) {
                q.push({i, j});
                mat[i][j] = 0;
            }
        
        int curr = 0;
        while(!q.empty() && onse > 0){
            int s = q.size();
            curr++;
            while(s--){
                auto t = q.front(); q.pop();
                int dx[4] = {0,0,-1,1};
                int dy[4] = {1,-1,0,0};
                
                for(int i = 0; i < 4; i++){
                    int x = t.first + dx[i];
                    int y = t.second + dy[i];
                    
                    if(x >= 0 && y >= 0 && x < n && y < m && mat[x][y] == 1){
                        mat[x][y] = 0;
                        onse--;
                        
                        q.push({x, y});
                    }
                }
            }
        }
        if(onse != 0) return -1;
        return curr;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends