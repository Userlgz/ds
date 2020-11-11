#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map<int, vector<int>> value;
bool cmp1(int a, int b)
{
    if (b<a)
        return true;
    else
    {
        return false;
    }
        
}
int main(void)
{
    int n,s,num=0;
    int a,b;
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        value[b].push_back(a);
    }
    auto it = value.begin();
    for (it = value.begin(); it != value.end(); it++){
        // printf("%d ", it->first);
        sort(it->second.begin(),it->second.end(),cmp1);
        // for (int i = 0; i < it->second.size();i++)
        // {
        //     printf("%d ", it->second[i]);
        // }
        // printf("\n");
    }
    int res[2][20];
    it = value.begin();
    int mon = s;
    int resnum = 0;
    for (int i = 0; i < it->second.size();i++)
    {
        // printf("%d ", it->second[i]);
        if (mon >= (it->first+it->second[i])){
            res[0][resnum++] = it->second[i];
            mon -= it->first;
        }

    }
    for (it = it+1; it != value.end(); it++){
        // printf("%d ", it->first);
        // sort(it->second.begin(),it->second.end(),cmp1);
        for (int i = 0; i < it->second.size();i++)
        {
            printf("%d ", it->second[i]);
        }
        printf("\n");
    }

    
    // sort(value.begin(),value.end(),cmp1);
    // for (int i = 0; i < (int)value.size(); i++)
    // {
    //     if(s<=value[i].second)
    //         break;
    //     if(value[i].first+value[i].second<=s)
    //     {
    //         s-=value[i].second;
    //         num++;
    //         continue;
    //     }
    //     int tems=s;
    //     for(int j=i-1;j>=0;j--)
    //     {
    //         tems+=value[j].second;
    //         if(value[i].first+value[i].second<=tems)
    //             if(value[i].first+s>=value[j].first+value[j].second)
    //             {
    //                 s-=value[i].second;
    //                 num++;
    //                 break;
    //             }
    //     }
        
    // }
    // printf("%d\n",num);
    system("pause");
}