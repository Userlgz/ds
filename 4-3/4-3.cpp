#include <iostream>
#include <algorithm>
#include <queue>
// #include<map>
// #include<vector>
using namespace std;
// map<int, vector<int>> lib;
typedef struct Book
{
    int rent = 0; //租金
    int deposit = 0; //押金
}Book;

typedef struct Record
{
    int need = 0; //租需要need元 
    int remain = 0; //剩余remain元
}Record;

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
bool cmp2(Book a, Book b)
{
    if (b.deposit>(a.deposit+a.rent))
        return false;
    else
    {
        return true;
    }
        
    if (a.rent == b.rent)
    {
        return a.deposit > b.deposit;
    }

    return a.rent < b.rent;
}

bool operator > (Book a, Book b)
{
    if (b.deposit>=(a.deposit+a.rent))
        return true;
        
    if (a.rent == b.rent)
    {
        return a.deposit < b.deposit;
    }

    return a.rent > b.rent;
}

// bool cmp1(Record a, Record b)
// {
//     if (a.rent == b.rent)
//     {
//         return a.deposit > b.deposit;
//     }

//     return a.rent < b.rent;
// }

int n, s;
int a, b;
int i, j;
int m = 0;
int cnt = 0;
int num = 0;
Book books[1000001];
Book temp[1000001];

priority_queue<Book, vector<Book>, greater<Book> > que1;

// priority_queue<int, pair<int, int>, cmp1> rec;

int	main()
{
    scanf("%d %d", &n, &s);
    // rec[0][0] = 0;
    // rec[0][1] = s;
    for ( i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        if (a+b<=s)
        {
            Book book;
            book.deposit = a;
            book.rent = b;
            que1.push(book);
            ++num;
        }
        
        
    }

    sort(books, books + num, cmp);
    sort(books, books + num, cmp2);
/*
    for ( i = 0; i < num; i++)
    {
        m = books[i].deposit + books[i].rent;
        if (rec[cnt][1] >= m)
        {
            ++cnt;
            rec[cnt][0] = m;
            rec[cnt][1] = rec[cnt - 1][1] - books[i].rent;
        }
        else
        {
            for ( j = cnt-1; j >= 0; j--)
            {
                if (rec[j][1] >= m && rec[j][1] - books[i].rent >= rec[j + 1][0])
                {
                    rec[j + 2][0] = rec[j + 1][0];
                    rec[j + 2][1] = rec[j + 1][1];
                    rec[j + 1][0] = m;
                    rec[j + 1][1] = rec[j][1] - books[i].rent;
                    ++cnt;
                    break;
                }
            }
            
        }
        
    }
*/
    printf("\n");

    while(!que1.empty()){
    	cout << que1.top().deposit << " " << que1.top().rent << endl;
    	que1.pop();
    }
    
    // for ( i = 0; i < num; i++)
    // {
    //     printf("%d %d\n", books[i].deposit, books[i].rent);
    // }

    // system("pause");
    return 0;
}
