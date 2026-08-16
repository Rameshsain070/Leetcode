class Solution {
public:

    int dx[8]={0,0,1,1,-1,-1,-1,1};
    int dy[8]={1,-1,0,1,1,-1,0,-1};

    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int ctr=0;
                for(int r=0;r<8;r++){
                    int nx=i+dx[r];
                    int ny=j+dy[r];

                    if(nx>=0 && ny>=0 && nx<n && ny<m){
                        ctr+=(board[nx][ny]%2);
                    }
                }

                if(board[i][j]==0){
                    if(ctr==3) board[i][j]+=4;
                    else board[i][j]+=2;
                }

                else{
                    if(ctr<2 || ctr>3) board[i][j]+=2;
                    else board[i][j]+=4;
                }
            }
        }



        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2 || board[i][j]==3) board[i][j]=0;
                else board[i][j]=1;
            }
        }


    }
};