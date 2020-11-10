#include <iostream>
#include <algorithm>
#include<math.h>
#include <time.h>
using namespace std;

class Solution {
public:

    int x1[1001] = {1, 0, 0, 0};
    int x2[1001] = {1, 0, 0, 0};
    int sum = 0;
    // int *x = x1;
    int x_max = 1000000007;
    bool flag = true;

    int *cal2(int i, int j)
    {
    
        if(flag)
        {
            if (sum - j < j){
                x2[j] = x2[sum - j];
            }
            else
            {
                x2[j] = (x2[j - 1] + x1[j]) % x_max;
                if (i <= j)
                {
                    x2[j] = ((x2[j] - x1[j-i]) + x_max)  % x_max;
                }
            }

            // flag = 0;
            return x2;
        }
        else
        {
            if (sum - j < j){
                x1[j] = x1[sum - j];
            }
            else
            {
                // int s = j - i;
                x1[j] = (x1[j - 1] + x2[j]) % x_max;
                if (i <= j)
                {
                    x1[j] = ((x1[j] - x2[j-i]) + x_max)  % x_max;
                }
            }
            return x1;
        }
    }


    int kInversePairs(int n, int t) {

        int i = 0, j = 0;
        if (n==1)
        {
            return x1[t];
        }
        else
        {
            int temp = t;
            for (i = 2; i < n + 1; i++)
            {
                temp = t;
                sum += i - 1;
                temp = min(sum, t);
                flag = !flag;
                for ( j = 1; j < temp+1; j++)
                {
                    if(flag)
                    {
                        if (sum - j < j){
                            x2[j] = x2[sum - j];
                        }
                        else
                        {
                            x2[j] = (x2[j - 1] + x1[j]) % x_max;
                            if (i <= j)
                            {
                                x2[j] = ((x2[j] - x1[j-i]) + x_max)  % x_max;
                            }
                        }

                        // flag = 0;
                    }
                    else
                    {
                        if (sum - j < j){
                            x1[j] = x1[sum - j];
                        }
                        else
                        {
                            // int s = j - i;
                            x1[j] = (x1[j - 1] + x2[j]) % x_max;
                            if (i <= j)
                            {
                                x1[j] = ((x1[j] - x2[j-i]) + x_max)  % x_max;
                            }
                        }
                    }
                }
            }
            // printf("%d\n", x[t]);
            if(flag)
                return x2[t];
            else
                return x1[t];
        }
        
        // system("pause");
        
    }

};

int fib()
{
    int i, n, t1 = 1, t2 = 2, nextTerm;
 
    printf("输出几项: ");
    scanf("%d", &n);
 
    printf("斐波那契数列: ");
 
    for (i = 1; i <= n; ++i)
    {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return 0;
}

void num()
{
    int i = 0, n = 0;

    printf("输出几项: ");
    scanf("%d", &n);
 
    printf("\n");
 
    for (i = 1; i <= n; ++i)
    {
        printf("%d ", i);
    }
}

void q3_3()
{
    int max = INT_FAST32_MAX;
    max %= 1000000007;

    if(-100)
        printf("%d\n", max);
    else
        printf("false");
}


class Q4_5{
    public:
    typedef struct Person
    {
        int a;
        int b;
        //
        int s = 0;
    }Person;

    bool cmp0(Person a, Person b)
    {
        return min(a.a, b.b) < min(a.b, b.a);
    }
    bool cmp1(Person a, Person b)
    {
        return min(a.b, b.a) < min(a.a, b.b);
    }
    
    void ans(int n)
    {
        Person person0[1000001];
        int cnt0 = 0;
        Person person1[1000001];
        int cnt1 = 0;

        long long sum[2][2] = {{0, 0}, {0, 0}};
        long long time0 = 0;
        long long time1 = 0;
        int a, b, c;
        int i;
        // scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            // t = min(a, b);
            if(c)
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
        sort(person0, person0 + cnt0, this->cmp0);
        sort(person1, person1 + cnt1, this->cmp1);

        // time0 = sum[0][0];
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

        printf("%lld", max(sum[1][1], time0));

        // for(i=0;i<4;i++)
        //     cout<<person0[i].a<<" "<<person0[i].b<<endl;

        // return 0;
    }
};

int main()
{
    // fib();
    // num();
    // q3_3();
    // Solution solution;
    // printf("%d\n", solution.kInversePairs(3, 1));
    // q4_5();
    int a = INT_MAX;
    if(1<2&&!(2>3))
    cout << a;
    // Q4_5 q4_5;
    // while(cin>>a)
    //     q4_5.ans(a);
    // system("pause");
    return 0;
}
