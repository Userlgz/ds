#include <iostream>
// #include<math.h>
// #include <time.h>
using namespace std;
int x1[1001] = {1, 0, 0, 0};
int x2[1001] = {1, 0, 0, 0};
int sum = 0;
int x_max = 1000000007;
bool flag = true;
int n, t;

int	main()
{
    scanf("%d %d", &n, &t);

    // printf("开始\n");
    // time_t begin_t  = clock();

    // for (int ii=1;ii<t+1;ii++){
    //     x1[ii]=0;
    //     x2[ii]=0;
    // }

    int i = 0, j = 0;

    int temp = t;
    for (i = 2; i < n + 1; i++)
    {
        temp = t;
        sum += i - 1;
        temp = min(sum, t);
        flag = !flag;
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
                    x2[j] = (x2[j - 1] + x1[j]) % x_max;
                    if (i <= j)
                    {
                        x2[j] = ((x2[j] - x1[j-i]) + x_max)  % x_max;
                    }
                }
                else
                {
                    x1[j] = (x1[j - 1] + x2[j]) % x_max;
                    if (i <= j)
                    {
                        x1[j] = ((x1[j] - x2[j-i]) + x_max)  % x_max;
                    }
                    
                }
            }
        }
    }
    if(flag)
        printf("%d\n", x2[t]);
    else
        printf("%d\n", x1[t]);

    // time_t finish_t = clock();
    // cout<<"it cost " << (double )(finish_t - begin_t )/CLOCKS_PER_SEC <<" s"<<endl;


    // system("pause");
    return 0;
}