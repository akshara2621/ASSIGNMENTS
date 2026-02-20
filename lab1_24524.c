#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>
int main(){
    int a[30];
    int status;
    pid_t c1,c2;
    int result1=0 , result2=0;
    srand(time(NULL));
    printf("array initialized by parent \n");


    for(int i=0;i<30;i++)
    a[i] = rand()%50 + 1;

    c1=fork();
    if(c1==0){
        int sum1 = 0;
        for(int i=0; i<15;i++){
            if(a[i] % 2==0)
            sum1 +=a[i];
        }
        exit(sum1);
    }
    waitpid(c1,&status,0);
    result1=WEXITSTATUS(status);

    c2 = fork();
    if(c2==0){
        int sum2 = 0;
        for(int i=15; i<30;i++){
            if(a[i]%2==0)
            sum2 +=a[i];
        }
        exit(sum2);
    }
    waitpid(c2,&status,0);
    result2=WEXITSTATUS(status);
    printf("even sum (0-14): %d\n", result1);
    printf("even sum(15-29):%d\n", result2);

    return 0;
}


