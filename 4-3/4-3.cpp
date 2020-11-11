#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef struct Book
{
    int rent = 0;    //租金
    int deposit = 0; //押金
    Book *next;
} Book;

typedef struct Records
{
    Book head;
    Book *last;
    int remain = 0; //剩余remain元

} Records;

bool cmp(Book a, Book b)
{
    // if (b.deposit>(a.deposit+a.rent))
    //     return true;
    if (a.rent == b.rent)
    {
        return a.deposit > b.deposit;
    }

    return a.rent < b.rent;
}


int n, s;
int a, b;
int i, j;
int m = 0;
int cnt = 1;
int num = 0;
int mon = 0;
Book books[1000001];
// Book books[20];
Records records;

int main()
{
    scanf("%d %d", &n, &s);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        if (a + b <= s)
        {
            ++num;
            books[i].deposit = a;
            books[i].rent = b;
        }
    }
    if (num == 0)
    {
        printf("0");
        return 0;
    }
    sort(books, books + num, cmp);
    // sort(books, books + num, cmp2);
    
    records.last = &books[0];
    records.head.next = &books[0];
    records.remain = s;
    s -= books[0].rent;

    for (i = 1; i < num; i++)
    {
        m = books[i].deposit + books[i].rent;
        if (s >= m)
        {
            ++cnt;
            records.last->next = &books[i];
            records.last = &books[i];
            s -= books[i].rent;
        }
        else if (s >= books[i].rent)
        {
            Book *temp = records.head.next;
            Book *pre = &records.head;
            mon = records.remain;
            while (temp != nullptr)
            {
                if (mon >= m && (mon - books[i].rent) >= (temp->deposit + temp->rent))
                {
                    pre->next = &books[i];
                    books[i].next = temp;
                    ++cnt;
                    s -= books[i].rent;
                    if (mon == m || (mon - books[i].rent) == (temp->deposit + temp->rent))
                    {
                        records.head = *pre;
                        records.remain = mon;

                        // printf("head: %d %d %d\n", pre->deposit, pre->rent, mon);
                        // printf("----: %d %d %d\n", temp->deposit, temp->rent, mon);
                    }
                    break;
                }
                else
                {
                    mon -= temp->rent;
                    pre = temp;
                    temp = pre->next;
                }
            }
        }
    }

    // printf("\n----------------------\n");
    // Book *temp = records.head.next;
    // while (temp != nullptr)
    // {
    //     printf("%d %d\n", temp->deposit, temp->rent);
    //     temp = temp->next;
    // }
    printf("%d\n", cnt);

    // system("pause");
    return 0;
}
/*

3 10
1 2
3 4
5 6

8 20
17 1
1 1
1 1
1 1
18 2
16 2
14 2
12 2

8 20
17 1
1 1
1 1
1 1
18 2
15 2
12 2
10 2

*/