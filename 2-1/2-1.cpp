#include<iostream>
#include<cstring>
using namespace std;
int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 1932053504, 1278945280 };
// int p[] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55};
int p[] = { 0, 9, 17, 24, 30, 35, 39, 42, 44, 45};
int flag[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int res[] = {99, 351, 927, 2151, 4671, 9783, 20079};
//  ' 0 ' 为 48
int num[9];
int len = 0;
int fun();
int fun2(int n)
{
    if (n==len-1)
    {
        return num[0];
    }
    return num[len-n-1]+1;
}
int fun3(int fsum, int n)
{
    if (n==1)
    {
        return 9;
    }
    return fsum*45+9;
}

int main()
{

    // int num = 0;
    // scanf("%d", &num);
    // int sum = 0;

    // int i = 0, j = 0;
    // int f = 0;
    // for (i = 1; i <= num; i++)
    // {
    //     j = i;
    //     while (j > 0)
    //     {
    //         f = j % 10;
    //         flag[f] = 1;
    //         j = j / 10;
    //     }
    //     if(fun())
    //         sum++;
    // }
    // printf("%d", sum);


    //------------------------------------------------------------------------------------

    char a;
    int sum = 0;
    // int len = 0;
    while((a = getchar()) != '\n')
    {
        num[len] = a - 48;
        len++;
    }
    // int n = pow(double(10.0), double(len));
    // printf("%d\n", n);
    sum += res[len - 3];
    // a[len] = '\0';
    int j = 1;
    int fsum = 0;
    // int 
    printf("%d %d\n", num[0], len);
    for (int i = len-1; i >= 1; --i) {
        // compute dp[i]
        flag[num[len-i-1]] = 1;
        fsum = 0;
        j = 1;
        printf("  %d ------------- %d \n", i, num[len-i-1]);
        
        for (j = 1; j < i; ++j)
        {
            
            fsum += factorial[i] / (factorial[j] * factorial[i - j]);
            printf("%d %d\n", j, fsum);
        }
        // fsum = 0;
        // for (j = 1; j < i+1; ++j)
        // {
            
        //     fsum += factorial[i] / (factorial[j] * factorial[i - j]);
        //     printf("%d %d\n", j, fsum);
        // }
        printf("%d %d %d\n", j, fsum, sum);
        
        // fsum = fun3(fsum, i);
        fsum = fsum * p[num[len - i - 1]-1] + num[len - i - 1];
        printf("%d %d %d\n", j, fsum, sum);
        sum += fsum; //* num[len-i-1];
        if(fun()==0)
        {
            break;
        }
        

        printf("%d %d\n", sum, num[len-i-1]);
    }
    
    int f = fun();
    printf("f: %d\n", f);
    if (f==1){
        sum += num[len-1]+1;
    }
    else if (f==2)
    {
        for (int i = 0; i <= num[len-1]; i++)
        {
            sum += flag[i];
            // flag[i] = 0;
        }
        
    }
       
    printf("sum: %d\n", sum);

    // system("pause");
    return 0;

}

int fun()
{
    int f = 0;
    for (int i = 0; i < 10; i++)
    {
        f += flag[i];
        // flag[i] = 0;
    }
    if (f < 3)
    {
        return f;
    }
    return 0;
}