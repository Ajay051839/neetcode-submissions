class Solution {
 using p=pair<int,pair<int,int>>;   
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int INF=2147483647;
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<vector<int>> dist(n,vector<int>(m,INF));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    dist[i][j]=0;
                    pq.push({0,{i,j}});
                }
            }
        }
        //direction array
        int dr[4]={1,0,0,-1};
        int dc[4]={0,1,-1,0};
        while(!pq.empty()){
           int dis=pq.top().first;
           int r=pq.top().second.first;
           int c=pq.top().second.second;
           pq.pop();
           for(int i=0;i<4;i++){
              int row=r+dr[i];
              int col=c+dc[i];
              if(row>=0 && col>=0 && row<n && col<m && grid[row][col]==INF){
                if(dist[row][col]>dis+1){
                grid[row][col]=dis+1;
                pq.push({dis+1,{row,col}});
                }
              }
           }
        }
    }
};
