class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row=matrix.size();
        int col=matrix[0].size();
        int rowCount=0,colCount=col-1;
        while(rowCount<row && colCount>=0)
        {
            int element=matrix[rowCount][colCount];
            if(element==target)return 1;
            if(element<target)rowCount++;
            else colCount--;
        }
        return 0;
    }
};
