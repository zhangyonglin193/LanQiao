#include <iostream>
#include <cmath>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
ll op1(ll x)
{
    return (ll)floor(10 * sqrt(x));
}
ll op2(ll x)
{
    return (ll)floor(0.7 * x + 30);
}
ll op3(ll x)
{
    return (ll)floor(1.2 * x);
}
ll op4(ll x)
{
    return x + 5;
}
int main()
{
    ll T;
    cin>>T;
    while(T--)
    {
        ll x;
        int a1,a2,a3,a4;
        //memset(dp,-1,sizeof(dp)); 
        cin>>x>>a1>>a2>>a3>>a4;
        vector<vector<vector<vector<ll>>>> dp(
            a1 + 1, vector<vector<vector<ll>>>(
                a2 + 1, vector<vector<ll>>(
                    a3 + 1, vector<ll>(a4 + 1, -1)
                )
            )
        );
        dp[0][0][0][0]=x;
        ll max_score=x;
        for(int c1=0;c1<=a1;c1++)
        {
            for(int c2=0;c2<=a2;c2++)
            {
                for(int c3=0;c3<=a3;c3++)
                {
                    for(int c4=0;c4<=a4;c4++)
                    {
                        ll cur=dp[c1][c2][c3][c4];
                        if(cur==-1)     continue;
                        if(cur>max_score)
                        {
                            max_score=cur;
                        }
                        if(c1<a1)
                        {
                            ll nx=op1(cur);
                            if(nx>dp[c1+1][c2][c3][c4])
                            {
                                dp[c1+1][c2][c3][c4]=nx;
                            }
                        }
                        if(c2<a2)
                        {
                            ll nx=op2(cur);
                            if(nx>dp[c1][c2+1][c3][c4])
                            {
                                dp[c1][c2+1][c3][c4]=nx;
                            }
                        }
                        if(c3<a3)
                        {
                            ll nx=op3(cur);
                            if(nx>dp[c1][c2][c3+1][c4])
                            {
                                dp[c1][c2][c3+1][c4]=nx;
                            }
                        }
                        if(c4<a4)
                        {
                            ll nx=op4(cur);
                            if(nx>dp[c1][c2][c3][c4+1])
                            {
                                dp[c1][c2][c3][c4+1]=nx;
                            }
                        }
                    }
                }
            }
        }
        cout<<max_score<<endl;
    }
    return 0;
}