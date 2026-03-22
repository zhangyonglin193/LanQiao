//几个道理
//1.没钱就不装大爷，券多钱少无烦恼
//2.钱多券少后悔恼，一下一下来比较
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define int long long
const int N=50010;
int p[N],c[N];
bool buy[N];
int ans=0;
priority_queue<pair<int ,int>,vector<pair<int,int>>,greater<pair<int,int>>>P,C;
priority_queue<int,vector<int>,greater<int>>D;
signed main()
{
    int n,k,m;
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i]>>c[i];
        P.push(make_pair(p[i],i));
        C.push(make_pair(c[i],i));
    }
    for(int i=1;i<=k;i++)
    {
        D.push(0);
    }
    while(!P.empty()&&!C.empty())
    {
        pair<int,int>p1=P.top();
        pair<int,int>c2=C.top();
        if(buy[p1.second])
        {
            P.pop();
            continue;
        }
        if(buy[c2.second])
        {
            C.pop();
            continue;
        }
        if(D.top()>p1.first-c2.first)//我买的是更省的，不后悔
        {
            m-=p1.first;
            P.pop();
            buy[p1.second]=true;
        }
        else
        //刚开始，只好从此入，最先全用少钱的
        //一旦券没了，就比较已用的券谁省的最多，谁留下
        {
            m-=c2.first+D.top();//后悔了，拿来把你，把省最少的优惠资格给更多的
            C.pop();
            buy[c2.second]=true;
            D.pop();
            D.push(p[c2.second]-c[c2.second]);//记录此次省钱量
        }
        if(m>=0)ans++;//行为成立，增加个数
        else
        break;//仅仅想想，做不到
    }
    cout<<ans;
    return 0;
}