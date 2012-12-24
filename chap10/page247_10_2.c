#include "apue.h" 
#include <pwd.h> 

static void 
my_alarm(int signo) 
{
    struct passwd *rootptr; 

    printf("in signal handler\n"); 

/*    if ((rootptr = getpwnam("hqy")) == NULL)
        err_sys("getpwnam(root) error"); 

    else 
        printf("hqy = %s\n", rootptr->pw_name); 
*/

    alarm(1); 
}

int main() 
{
    struct passwd *ptr; 

    signal(SIGALRM, my_alarm); 
    alarm(1); 

    for( ; ; ) {

        if ((ptr = getpwnam("huangqiyu")) == NULL)
            err_sys("getpwnam error"); 
        if (strcmp(ptr->pw_name, "huangqiyu") != 0) 
            printf("return  value corrupted!, pw_name = %s\n", ptr->pw_name);

       /* else 
            printf("huangqiyu= %s\n", ptr->pw_name); */

    }

    return 0; 
}

