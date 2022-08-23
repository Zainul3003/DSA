vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    long long n=A.size();
    long long sum=(n*(n+1))/2;
    long long sqr=(n*(n+1)*(2*n+1))/6;
    for(auto i:A)
    {
        sum-=(long long)i;
        sqr-=(long long)(i)*(long long)(i);
    }
    long long t=sqr/sum;
    int b=(sum+t)/2;
    int a=t-b;
    return {a,b};
}
