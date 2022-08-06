class Solution {
public:
    void solve(int ind,string digits,string ds,vector<string> &ans,unordered_map<int,string> &mp)
    {
        if(ind==digits.size())
        {
            ans.push_back(ds);
            return;
        }
        int number=digits[ind]-'0';
        string str=mp[number];
        for(int i=0;i<str.size();i++)
        {
            ds.push_back(str[i]);
            solve(ind+1,digits,ds,ans,mp);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        if(digits=="")return ans;
        string ds="";
        unordered_map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        solve(0,digits,ds,ans,mp);
        return ans;
    }
};
