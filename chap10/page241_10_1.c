#include "apue.h" 

void sig_usr(int);

int main() 
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) 
        err_sys("can't catch SIGUSR1"); 

    void (*p_sig_usr) (int); 

    if ((p_sig_usr= signal(SIGUSR2, sig_usr)) == SIG_ERR)
        err_sys("can't catch SIGUSR2"); 

    // re-assignment, since signal() reture previous handler address. 
    p_sig_usr = signal(SIGUSR2, sig_usr); 

    if (*p_sig_usr == sig_usr) 
        printf("ok\n"); 

    for( ; ; )
        pause(); 

    return 0; 
}

void sig_usr(int signo) 
{
    if (signo == SIGUSR1) 
        printf("received SIGUSR1\n"); 
    else if (signo == SIGUSR2) 
        printf("received SIGUSR2\n"); 

    else 
        err_dump("received signal %d\n", signo); 
}

