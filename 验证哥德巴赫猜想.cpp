#include<iostream>
bool zhishu[101];
void filter_zhishu()
{
    zhishu[1] = 0;
    zhishu[2] = 1;
    int i = 3;
    for (; i <= 100; i += 2)
    {
        zhishu[i] = 1;
        zhishu[i + 1] = 0;
        for (int j = 3; j * j <= i; j += 2)
        {
            if (i % j == 0)
            {
                zhishu[i] = 0;
                break;
            }
        }
    }
}

void search_zhishu()
{
    for (int i = 4; i < 100; i += 2)
    {
        printf("%d", i);
        for (int j = 2; j <= i / 2; j++)
        {
            if (zhishu[j] && zhishu[i - j])
            {
                printf("=%d+%d", j, i - j);
            }
        }
        printf("\n");
    }
}

int main()
{
    filter_zhishu();
    search_zhishu();
}