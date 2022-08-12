class Solution {
public:
    void DFS(int i,int j,vector<vector<char>>& board)
    {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!='O')return ;
        board[i][j]='#';
        DFS(i,j-1,board);
        DFS(i,j+1,board);
        DFS(i+1,j,board);
        DFS(i-1,j,board);
    }
    void solve(vector<vector<char>>& board) 
    {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')DFS(i,0,board);
            if(board[i][n-1]=='O')DFS(i,n-1,board);
        }
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O')DFS(0,j,board);
            if(board[m-1][j]=='O')DFS(m-1,j,board);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='#')board[i][j]='O';
            }
        }
    }
};
