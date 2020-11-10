#include<iostream>
#include<time.h>
using namespace std;
int a[26];
int b[26];
int c[26];
int d[26];
int n,m,t;
int i = 0, j = 0;
int count = 0;
int func(int a[], int m)
{
    int temp[26];
    int sum1 = 0;
    int sum2 = 0;
    int sum = 0;
    if (m == 0)
    {
        for (i = 1; i < n; i++)
        {
            sum += (a[i] * c[i]);
            
        }
        // printf("\n %-d    %-d\n\n", ++count, sum);
        return sum;
    }
        
    for (i = 1; i < n; i++)
    {
        temp[i] = a[i] ^ b[i];
        
        // sum1 += temp[i] * c[i];
    }
    // printf(" 1 ");
    sum1 = func(temp, m - 1);
    for (i = 1; i < n; i++)
    {
        temp[i] = a[d[i]] + t;
        
        // sum2 += temp[i] * c[i];
    }
    // printf(" 2 ");
    sum2 = func(temp, m - 1);
    if (sum1 > sum2)
    {
        return sum1;
    }
    else 
    {
        return sum2;
    }
}
int main()
{
    
    // 读入
    scanf("%d %d %d", &n, &m, &t);
    n += 1;
    // printf("%d %d %d\n", n, m, t);
    for (j = 1; j < n; j++)
    {
        scanf("%d", &a[j]);
    }
    for (j = 1; j < n; j++)
    {
        scanf("%d", &b[j]);
    }
    for (j = 1; j < n; j++)
    {
        scanf("%d", &c[j]);
    }
    for (j = 1; j < n; j++)
    {
        scanf("%d", &d[j]);
    }
    // printf("开始\n");
    // time_t begin_t  = clock();

    int sum = func(a, m);
    printf("%d\n", sum);

    // time_t finish_t = clock();
    // cout<<"it cost " << (double )(finish_t - begin_t )/CLOCKS_PER_SEC <<" s"<<endl;

    // system("pause");
}