#include<iostream>
using namespace std;
int matrix[1001][1001];
int row[1001];
int col[1001];
int main()
{
    int i = 0, j = 0, k = 0;
    int n, m, q, op, x, y;
    // cin >> n >> m >> q;
    scanf("%d %d %d", &n, &m, &q);
    n += 1;
    m += 1;
    // cout << n << " " << m << " " << q << endl;
    // int **matrix = new int *[n];

    // int *row = new int[n];
    for (i = 1; i < n; i++)
    {
        row[i] = i;
    }
    
    // int *col = new int[m];
    for (i = 1; i < m; i++)
    {
        col[i] = i;
    }

    for (i = 1; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
            // cout << matrix[i][j] << " ";
        }
        // cout << endl;
    }
    for (k = 0; k < q; k++)
    {
        // cin >> op >> x >> y;
        scanf("%d %d %d", &op, &x, &y);
        // cout << op << " " << x << " " << y << endl;
        // x -= 1;
        // y -= 1;
        if (op == 0)
        {
            row[x] = row[x] ^ row[y];

            row[y] = row[y] ^ row[x];

            row[x] = row[x] ^ row[y];
        }
        else if (op == 1)
        {
            col[x] = col[x] ^ col[y];

            col[y] = col[y] ^ col[x];

            col[x] = col[x] ^ col[y];
        }
        else
        {
            // cout << matrix[row[x]][col[y]] << endl;
            printf("%d\n", matrix[row[x]][col[y]]);
        }
    }
    // system("pause");
}