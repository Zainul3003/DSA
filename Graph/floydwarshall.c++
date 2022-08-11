//-1 denotes infinity
	    int n=matrix.size();
	    int m=matrix[0].size();
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<m;j++)
	            {
	                if(matrix[i][k]==-1 || matrix[k][j]==-1)continue;
	                else if(matrix[i][j]==-1)matrix[i][j]=matrix[i][k]+matrix[k][j];
	                else
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
