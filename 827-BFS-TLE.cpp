class Solution {
public:
    bool isValid(int row, int col, int n){
        return (row >= 0 && row < n && col >= 0 && col < n);
    }

    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<int>> zeroes;
        int n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) zeroes.push_back({i, j});
            }
        }
        if (zeroes.size() == 0) return n*n;
        int ans = 1;
        for(vector<int> i:zeroes){
            queue<vector<int>> queue;
            queue.push(i);
            int currCount = 0;
            vector<vector<int>> tempGrid(n, vector<int>(n, -1));
            while(!queue.empty()){
                vector<int> dx = {1, -1, 0, 0};
                vector<int> dy = {0, 0, -1, 1};
                for(int j=0; j<4; j++){
                    vector<int> front = queue.front();
                    int currRow = front[0] + dx[j];
                    int currCol = front[1] + dy[j];
                    if (isValid(currRow, currCol, n) && grid[currRow][currCol] && tempGrid[currRow][currCol] == -1) {
                        // cout << currRow << " " << currCol << endl;
                        tempGrid[currRow][currCol] = 1;
                        queue.push({currRow, currCol});
                    }
                }
                queue.pop();
                currCount++;
            }
            ans = max(ans, currCount);
        }
        return ans;
    }
};