#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> value;
bool cmp1(pair<int, int> a, pair<int, int> b)
{
    if(a.second < b.second)
        return true;
    if(a.second == b.second)
        if(a.first > b.first)
            return true;
    return false;
}
int main(void)
{
    int n,s,num=0;
    int a,b;
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        value.push_back(make_pair(a,b));
    }
    sort(value.begin(),value.end(),cmp1);
    for (int i = 0; i < (int)value.size(); i++)
    {
        if(s<=value[i].second)
            break;
        if(value[i].first+value[i].second<=s)
        {
            s-=value[i].second;
            num++;
            continue;
        }
        int tems=s;
        for(int j=i-1;j>=0;j--)
        {
            tems+=value[j].second;
            if(value[i].first+value[i].second<=tems)
                if(value[i].first+s>=value[j].first+value[j].second)
                {
                    s-=value[i].second;
                    num++;
                    break;
                }
        }
        
    }
    printf("%d\n",num);
    // system("pause");
}