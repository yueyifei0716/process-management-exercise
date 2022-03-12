#include <unistd.h>
#include <stdlib.h>
#include "stdio.h"

int value = 5;
int main()
{
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0) {
        sleep(5);
        value += 15;
        execlp("bin/echo","echo","Hello from the child process",NULL);
        printf("CHILD: value = %d\n",value);
    }
    printf("Hello from the parent process\n");
    waitpid(pid, &status, WUNTRACED);
    printf("PARENT: value = %d\n",value);
}

