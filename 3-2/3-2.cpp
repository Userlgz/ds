#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int, int> fib;
int n = 0;
// int dp[3000][3000];
int t[3000];
int main()
{
    int k = 0;
    // int t;


    scanf("%d", &n);
    for (k = 0; k < n; k++)
    {
        scanf("%d", &t[k]);
        fib[t[k]] = k;
    }

    // auto i=fib.begin(), j=fib.begin();
    int i = 0, j = 0;

    auto left = fib.begin(), right = fib.begin();
    // int left = 0, right = 0;

    int count = 0;
    int max = 0;
    // for ( i = 0; i < n-1; i++)
    //     dp[i][i + 1] = 2;

    // for (i = fib.begin(); i != fib.end(); ++i)
    for (i = 0; i < n; ++i)
    {
        if (max > n - i || max > n / 2)
        {
            // printf("break %d %d\n", i, j);
            // flag = 1;
            break;
        }
        // count = 2;
        left = fib.find(t[i]);

        // for (j; j != fib.end(); ++j)
        for (j = i + 1; j < n; ++j)
        {
            if (max > n - j || max > n / 2)
            {
                // printf("break %d %d\n", i, j);
                // flag = 1;
                break;
            }
            right = fib.find(t[j]);
            count = 2;
            auto iter = fib.find(t[i] + t[j]);
            
            while ( iter != fib.end()) 
            {
                // cout << iter->first << " ";
                ++count;
                
                // if (dp[left->second][right->second] >= count)
                // {
                //     // dp[left->second][right->second] = count;
                //     break;
                // }
                // printf("\nvalue: %d %d %d\n", left->first, left->second, count);
                // dp[left->second][right->second] = count;
                left = right;
                right = iter;
                // printf("\n%d \n", right->first + left->first);
                iter = fib.find(right->first + left->first);
                // left = right;
            }

            

            if (max < count)
            {
                max = count;
                // printf("\nvalue: %d %d %d\n", right->first, right->second, count);
            }

        }
        
        // if (flag)
        // {
        //     break;
        // }
        
    }
    if (max > 2)
    {
        printf("%d", max);
    }
    else
    {
        printf("-1");
    }
    

    return 0;
}