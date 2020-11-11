#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Person
{
    int a;
    int b;
    //
    // int s = 0;
}Person;

bool cmp0(Person a, Person b)
{
    return min(a.a, b.b) < min(a.b, b.a);
}
bool cmp1(Person a, Person b)
{
    return min(a.b, b.a) < min(a.a, b.b);
}

int n;
Person person0[1000001];
int cnt0 = 0;
Person person1[1000001];
int cnt1 = 0;

long long sum[2][2] = {{0, 0}, {0, 0}};
long long time0 = 0;
long long time1 = 0;
int a, b, c;
int i, j;

int main()
{
    // while(scanf("%d", &n)){
    //     for (i = 0; i < 2;i++)
    //     for (j = 0; j < 2;j++)
    //         sum[i][j] = 0;
    //     cnt1 = 0;
    //     cnt0 = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        // t = min(a, b);
        if (c)
        {
            person1[cnt1].a = a;
            person1[cnt1].b = b;
            ++cnt1;
            sum[c][0] += a;
            sum[c][1] += b;
        }
        else
        {
            person0[cnt0].a = a;
            person0[cnt0].b = b;
            ++cnt0;
            sum[c][0] += a;
            sum[c][1] += b;
        }

    }
    sort(person0, person0 + cnt0, cmp0);
    sort(person1, person1 + cnt1, cmp1);

    time0 = 0;
    time1 = sum[1][1];

    // time0 = person0[0].a;
    // time1 = person1[0].b;

    for ( i = 0; i < cnt0; i++)
    {
        time0 += person0[i].a;
        time1 = max(time0 + person0[i].b, time1 + person0[i].b);
    }
    sum[1][1] = time1;

    time0 = sum[0][0];
    time1 = 0;
    for ( i = 0; i < cnt1; i++)
    {
        time1 += person1[i].b;
        time0 = max(time0 + person1[i].a, time1 + person1[i].a);
    }

    printf("%lld\n", max(sum[1][1], time0));
    // }

    // for(i=0;i<4;i++)
    //     cout<<person0[i].a<<" "<<person0[i].b<<endl;
    // system("pause");
    return 0;
}
