class Solution {
private:
 void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board)
{
    int m=board.size();
    int n=board[0].size();

    vis[row][col]=1;

    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};

    for(int k=0;k<4;k++)
    {
        int nrow=row+delrow[k];
        int ncol=col+delcol[k];

        if(nrow>=0 && nrow<m &&
           ncol>=0 && ncol<n &&
           !vis[nrow][ncol] &&
           board[nrow][ncol]=='O')
        {
            dfs(nrow,ncol,vis,board);
        }
    }
}
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<n;i++)//traversing first and last row 
        {
            if(!vis[0][i]&&board[0][i]=='O')//first row
            {
                dfs(0,i,vis,board);
            }
            if(!vis[m-1][i] && board[m-1][i]=='O')//last row
            {
                dfs(m-1,i,vis,board);
            }
        }
        for(int i=0;i<m;i++)//traversing first and last col 
        {
            if(!vis[i][0]&&board[i][0]=='O')//first col
            {
                dfs(i,0,vis,board);
            }
            if(!vis[i][n-1] && board[i][n-1]=='O')//last col
            {
                dfs(i,n-1,vis,board);
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }

    }
};