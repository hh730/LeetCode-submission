class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> vis( row , vector<int> (col, 0));
        // int vis[row][col];
        int freshFruit=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    // q.push({{i,j},0});
                    q.push(make_pair(make_pair(i,j),0));
                    vis[i][j]=2;
                }
                if(grid[i][j]==1){
                    freshFruit++;
                }
            }
        }
        int maxTime=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int rot=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            maxTime=max(maxTime,t);
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    int nrow=r+drow[i];
                    int ncol=c+dcol[i];
                    if(nrow>=0&&nrow<row&&ncol>=0&&ncol<col&&grid[nrow][ncol]==1&&vis[nrow][ncol]==0){
                        // q.push({{nrow,ncol},t+1});
                        q.push(make_pair(make_pair(nrow,ncol),t+1));
                        vis[nrow][ncol]=2;
                        rot++;
                    }
                }
            }
        }
        if(rot!=freshFruit){
            return -1;
        }
        return maxTime;
    }
};