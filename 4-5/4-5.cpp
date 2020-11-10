/*
3.2	4.2
4.7	1.5
2.2	5.0
5.8	4.0
3.1	2.8
*/

/*
2.2 5.0
3.2 4.2

5.8 4.0
3.1 2.8
4.7 1.5

*/
#include <iostream>
#include <algorithm>
using namespace std;
struct Person
{
    int a;
    int b;
    //
    int s = 0;
};

bool cmp(Person a, Person b)
{
    return min(a.a, b.b) < min(a.b, b.a);
}

int n;
int last[2][2]={{0,0},{0,0}};//0是A 1是B 第二维存看病时间
int tmin[2] = {INT_MAX, INT_MAX};
long long sum[2][2] = {{0, 0}, {0, 0}};
int a, b, c;

int main()
{
    // float aa[5][2];
    int i;
    // int t = 0;
    // float **aa =new float*[5];

    while(cin >> n){
        printf("%d\n", n);
        // cin >> n;

        for (i = 0; i < n; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            // t = min(a, b);
            if (c)
            {
                if (tmin[c] > a)
                {
                    tmin[c] = a;
                    last[c][0] = a;
                    last[c][1] = b;
                }
                sum[c][0] += a;
                sum[c][1] += b;
            }
            else
            {
                if (tmin[c] > b)
                {
                    tmin[c] = b;
                    last[c][0] = a;
                    last[c][1] = b;
                }
                sum[c][0] += a;
                sum[c][1] += b;
            }
        }
        long long sum_max = max(max(sum[0][0] + sum[1][0], sum[0][1] + sum[1][1]), max(sum[0][0] + last[0][1], sum[1][1] + last[1][0]));
    // sum[0] += last[0][1];
    // sum[1] += last[1][0];
    // sort(person,person+i,cmp);
    // for(i=0;i<5;i++)
    //     cout<<person[i].a<<" "<<person[i].b<<endl;
    printf("%lld\n", sum_max);

    }

    return 0;
}

