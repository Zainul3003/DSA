class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        set<vector<int>> st;
        unordered_map<int,int> mp;
        for(auto a:nums)mp[a]++;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]--;
            for(int j=i+1;j<n;j++)
            {
                mp[nums[j]]--;
                if(mp[-nums[i]-nums[j]]>0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(-nums[i]-nums[j]);
                    temp.push_back(nums[j]);
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
