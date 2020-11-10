#include<iostream>
#include<time.h>
using namespace std;
int fun(int x, int y)
{
    // printf("%d  %d\n", x, y);
    if (y == 0)
    {
        return 999999;
    }
    else if (y == 1)
    {
        return x;
    }
    return x / y + fun(y, x % y);
}
int main()
{
    int n = 0;
    scanf("%d", &n);

    time_t begin_t  = clock();
    
    int mmin = 0;
    // printf("%d::  %d\n\n", n, min);
    int i = 1;
    int t1 = 1, t2 = 1, nextTerm;
 
    // printf("斐波那契数列: ");
    while (t2<n)
    {
        mmin++;
        // printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    // // printf("%d,  %d\n", t2,mmin);
    // if (t2==n)
    // {
    //     printf("%d\n", mmin);
    // }
    // else
    // {
        
    // }

    int t = 0;
    int min = fun(n, 1) - 1;
    for (i = 2; i < n / 2 + 1; i++)
    {
        // printf("%d: \n", i);
        if (n % i == 0)
        {
            continue;
        }
        t = fun(n, i) - 1;
        // printf("t: %d\n\n", t);
        if (t <= mmin)
        {
            min = t;
            break;
        }
        if (t < min)
        {
            min = t;
        }
    }
    printf("%d \n", min);
    time_t finish_t = clock();
    cout << "it cost " << (double)(finish_t - begin_t) / CLOCKS_PER_SEC << " s" << endl;
    // system("pause");
    return 0;
}

// 1000000
// 斐波那契数列: 1346269,  30

// #include <stdio.h>
 
