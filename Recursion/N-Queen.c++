class Solution {
public:
    bool place(int r,int c,vector<string> board,int n)
    {
        int i=r;
        int j=c;
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q')return false;
            i--;
            j--;
        }
        i=r,j=c;
        while(j>=0)
        {
            if(board[i][j]=='Q')return false;
            j--;
        }
        i=r,j=c;
        while(i<n && j>=0)
        {
            if(board[i][j]=='Q')return false;
            i++;
            j--;
        }
        return true;
    }
public:
    void queen(int c,vector<string> &board,vector<vector<string>> &ans,int n)
    {
        if(c==n)
        {
            ans.push_back(board);
            return ;
        }
        for(int r=0;r<n;r++)
        {
            if(place(r,c,board,n))
            {
                board[r][c]='Q';
                queen(c+1,board,ans,n);
                board[r][c]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        queen(0,board,ans,n);
        return ans;
    }
};
