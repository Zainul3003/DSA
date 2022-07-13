class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ans;
        int r=matrix.size();
        int c=matrix[0].size();
        int startrow=0;
        int startcol=0;
        int endrow=r-1;
        int endcol=c-1;
        int total=r*c;
        int count=0;
        while(count<total)
        {
            for(int j=startcol;j<=endcol && count<total;j++)
            {
                ans.push_back(matrix[startrow][j]);
                count++;
            }
            startrow++;
            for(int i=startrow;i<=endrow && count<total;i++)
            {
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;
            for(int j=endcol;j>=startcol && count<total;j--)
            {
                ans.push_back(matrix[endrow][j]);
                count++;
            }
            endrow--;
            for(int i=endrow;i>=startrow && count<total;i--)
            {
                ans.push_back(matrix[i][startcol]);
                count++;
            }
            startcol++;
        }
        return ans;
    }
};
