class Solution{
    int minEle;
    stack<pair<int,int>> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty())return -1;
           else return s.top().second;
       }
       
       /*returns poped element from stack*/
       int pop()
       {
           if(s.empty())return -1;
           else
           {
               auto t=s.top();
               s.pop();
               return t.first;
           }
       }
       
       /*push element x into the stack*/
       void push(int x)
       {
           if(s.empty())
           {
               s.push({x,x});
           }
           else
           s.push({x,min(x,s.top().second)});
       }
};
