#include <stdio.h>
#include <string.h>
#include <stlib.h>
#include <signal.h>
char *convert(int number)
{
    int count=0;
    int numbertmp=number;
    while(numbertmp>0)
    {
        int digit= numbertmp%10;
        numbertmp/=10;
        count++;
    }
    char * value= (char * ) calloc (count,sizeof(unsigned char)  );
    numbertmp=number;
    count--;
    while(numbertmp>0)
    {
        int digit= numbertmp%10;
        numbertmp/=10;
        char x=(char) 48+digit;
        *(value+count)=x;
        count--;
    }

    return value;
}

int pipefd[2];

void Topla(){
    printf("Topla\n");
    int pid= fork();
    if(pid==0){
        execve("topla",NULL,NULL);
        perror("error");
    }else{
        //wait(&ev);
        char s[10];
        do{
            scanf("%s",s);
            write(pipefd,s,strlen(s));
        }while(strcmp(s,"topla")!=0);
        wait(&ev);
    }
}
void Carp(){
    printf("Carp\n");
    if(pid==0){
        execve("carp",NULL,NULL);
        perror("error");
    }else{
        //wait(&ev);
        char s[10];
        do{
            scanf("%s",s);
            write(pipefd,s,strlen(s));
        }while(strcmp(s,"carp")!=0);
        wait(&ev);
    }
}
main(){
    if (pipe(pipefd) < 0) {
        perror("pipe");
        exit(1);
    }

    int choice=0;
    while(choice!=3){
        printf("1-Topla\n");
        printf("2-Carp\n");
        printf("3-Cikis\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                Topla();
            break;
            case 2:
                Carp();
            break;
            case 3:
                exit(0);
            break;
            default:
            printf("Yanlis parametre\n");
        }
    }
}