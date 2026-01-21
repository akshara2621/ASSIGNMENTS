#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main()
{
    int a[30];
    int i;
    int status;
    pid_t c1, c2;

    srand(time(NULL));

    printf("Parent initializing array:\n");
    for(i = 0; i < 30; i++)
    {
        a[i] = rand() % 50 + 1;
        printf("%d ", a[i]);
    }
    printf("\n\n");

    /* -------- CHILD 1 -------- */
    c1 = fork();

    if(c1 == 0)
    {
        int sum1 = 0;

        for(i = 0; i < 15; i++)
        {
            if(a[i] % 2 == 0)
                sum1 = sum1 + a[i];
        }

        exit(sum1);
    }

    waitpid(c1, &status, 0);
    int left_sum = WEXITSTATUS(status);

    /* -------- CHILD 2 -------- */
    c2 = fork();

    if(c2 == 0)
    {
        int sum2 = 0;

        for(i = 15; i < 30; i++)
        {
            if(a[i] % 2 == 0)
                sum2 = sum2 + a[i];
        }

        exit(sum2);
    }

    waitpid(c2, &status, 0);
    int right_sum = WEXITSTATUS(status);

    printf("Even sum (0–14)  = %d\n", left_sum);
    printf("Even sum (15–29) = %d\n", right_sum);

    return 0;
}