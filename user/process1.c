#include "library/syscalls.h"
#include "library/stdio.h"

// invoked in test programs
void runForSeconds(int seconds)
{
    unsigned int startTime; // seconds
    syscall_system_time(&startTime);
    unsigned int timeElapsed;
    do
    {
        syscall_system_time(&timeElapsed);
        timeElapsed -= startTime;
    } while (timeElapsed < seconds);
}

int main(int argc, char const *argv[])
{
    struct process_info info;
    printf("process1\n");
    int pid = syscall_process_fork();
    if (pid == 0)
    {
        runForSeconds(3);
        return 0;
    }
    else
    {
        printf("pid: %d\n", pid);
        syscall_process_wait(&info, -1);
    }
    printf("process1 done\n\n");
    return 0;
}
