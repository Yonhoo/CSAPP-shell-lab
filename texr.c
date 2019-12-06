#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

volatile sig_atomic_t p_id;

void sig_child(int sig)
{
    printf("i'm a child signal\n");
}

void sig_stop(int sig)
{
    kill(-p_id,SIGSTOP);
    printf("i'm a stop signal\n");
}

void sig_int(int sig){
    kill(-p_id,SIGINT);
    printf("i'm a int signal\n");
}


int main(int argc,char *argv[])
{
    pid_t pid;


    if((pid=fork())==0)
    {
        setpgid(0,0);
        printf("c %d\n",getpid());
        while (1)
        {
            printf("i'm a child\n");
            sleep(1);
        }
        
        //execve("./myspin","./myspin 1",NULL);
    }
    else if(pid>0)
    {
        signal(SIGCHLD,sig_child);
        signal(SIGTSTP,sig_stop);
        signal(SIGINT,sig_int);

        p_id=pid;
        printf("p  %d\n",getpid());
        int status;
        while((pid=waitpid(pid,&status,NULL))>0)
        {
            if(WIFSTOPPED(status)){
            //子进程停止引起的waitpid函数返回
            printf(" (%d) stop by signal %d\n",pid, WSTOPSIG(status));
            }else {
                if(WIFSIGNALED(status)){
                //子进程终止引起的返回,这里主要是sigint的信号过来的
                printf(" (%d) terminated by signal %d\n", pid, WTERMSIG(status));
                }

            }
        }
        
    }
     
}
