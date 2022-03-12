// parent create one child

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    pid_t pid = 0;
    // the status of the parent process
    int status;
    // create a child process
    pid = fork();

    if(pid < 0) {
        printf("Error! Can not create process!\n");
    } else if(pid == 0) {
        printf("Child process start!\n");
        sleep(2);
        printf("Child process over!\n");
    } else if(pid > 0) {
        printf("Parent process wait for child process!\n");
        waitpid(pid, &status, 0);
        printf("Parent process start!\n");
        sleep(2);
        printf("Parent process over!\n");
    }
    printf("This code will be executed by both the child and parent\n");
}
