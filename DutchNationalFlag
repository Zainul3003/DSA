class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int l=0,m=0,h=nums.size()-1;
        while(m<=h)
        {
            if(nums[m]==0)
            {
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
            else if(nums[m]==1)
            {
                m++;
            }
            else
            {
                swap(nums[h],nums[m]);
                h--;
            }
        }
    }
};


//----------------------------
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,t=0;
        for(int i=0;i<nums.size();i++)
        {
             if(nums[i]==0)z++;
             if(nums[i]==1)o++;
             if(nums[i]==2)t++;
        } 
        int k=0;
        for(int i=0;i<z;i++)nums[k++]=0;
        for(int i=0;i<o;i++)nums[k++]=1;
        for(int i=0;i<t;i++)nums[k++]=2;
    }
};
