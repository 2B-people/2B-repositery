#include <stdio.h>

#define MAX 10

int data[MAX] = {0};

typedef struct fifo_data
{
    int *base;
    int read;
    int front;
} fifo_t_e;

void fifo_add(void);
void fifo_del(void);
void fifo_show(void);
void fifo_len(void);

fifo_t_e P;

int main(int argc, char const *argv[])
{
    char line[100];
    int menu;

    P.front = P.read = 0;
    while (1)
    {
        printf("Enter (1) to Add data into fifo\n"
               "      (2) to Delete data  in fifo\n"
               "      (3) to show fifo\n"
               "      (4) to len fifo\n"
               "      (5) to Quit\n");
        fflush(stdout);
        gets(line);
        if (sscanf(line, "%d", &menu) != 1)
        {
            printf("incorrect entry");
            continue;
        }
        if (menu < 1 || menu > 5)
        {
            printf("incorrect selection");
            continue;
        }

        if (menu == 1)
            fifo_add();
        else if (menu == 2)
            fifo_del();
        else if (menu == 3)
            fifo_show();
        else if (menu == 4)
            fifo_len();
        else
            break;
    } /*endwhile*/
    return 0;
}

void fifo_add(void)
{
    int num;
    printf("please input data");
    scanf("%d", &num);

    if ((P.read + 1) % MAX == P.front)
    {
        printf("fifo 满了\n");
        return;
    }

    else
    {
        data[P.read] = num;
        P.read = (P.read + 1) % MAX;
        /* code */
    }
}
void fifo_del(void)
{
    int e;
    e = data[P.front];
    data[P.front] = 0;
    P.front = (P.front + 1) % MAX;
    return;
}
void fifo_show(void)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
void fifo_len(void)
{
    if (P.read >= P.front)
    {
        printf("%d", P.read - P.front);
    }
    
    else
    {
        printf("%d",P.front - P.read +MAX);
    }
    
}