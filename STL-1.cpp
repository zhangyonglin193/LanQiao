#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1;
    //赋值
    string s2="bcd";
    s2="efg";
    cout<<s2<<endl;
    //复制，长度
    string s("abc");
    string s3(s);
    cout<<s.length()<<endl;
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i];
    }
    cout<<endl;
    //尾添
    s.push_back('d');
    cout<<s<<endl;
    s.append("efg");
    cout<<s<<endl;
    //加连
    s=s+'h';
    s+='i';
    cout<<s<<endl;
    s=s+"jk";
    s+="lmnabc";
    s="xyz"+s;
    cout<<s<<endl;
    //合并
    string s4="uvw";
    cout<<s+s4<<endl;
    //查找
    cout<<"pos of b="<<s.find('b')<<endl;
    cout<<"pos of ef="<<s.find('ef')<<endl;
    cout<<"pos of ab="<<s.find('ab',5)<<endl;
    cout<<"pos of hello="<<(int)s.find("hello")<<endl;
    //截取
    cout<<s.substr(3,5)<<endl;
    //插入
    cout<<s.insert(4,"opq")<<endl;
    //删除
    cout<<s.erase(10,2)<<endl;
    cout<<s.erase(10)<<endl;
    //替换
    cout<<s.replace(2,3,"1234")<<endl;
    cout<<s.replace(s.begin()+7,s.begin()+9,"5678")<<endl;
    //判空
    cout<<s.empty()<<endl;
    s.clear();
    cout<<s.empty()<<endl;
    //比较
    string s5="abc";
    string s6="abc";
    string s7="ab";
    if(s5==s6)
    {
        cout<<"=="<<endl;
    }
    if(s5<s7)
    {
        cout<<"<"<<endl;
    }
    if(s5>s7)
    {
        cout<<">"<<endl;
    }
    if(s5!=s7)
    {
        cout<<"!="<<endl;
    }
    return 0;
}