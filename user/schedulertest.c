#include "library/syscalls.h"
#include "library/stdio.h"
#include "library/errno.h"

int create_process(const char *exec, int priority){
    int pfd = syscall_open_file(KNO_STDDIR, exec, 0, 0);
    if (pfd >= 0){
        int pid = syscall_process_prun(pfd, 0, &exec, priority);
        if (pid > 0){
            printf("created %s with priority %d\n", exec, priority);
        }else{
            printf("couldn't run %s: %s\n", exec, strerror(pid));
        }
        syscall_object_close(pfd);
    }
    else{
        printf("couldn't find %s: %s\n", exec, strerror(pfd));
    }
    return 0;
}

int main(int argc, char const *argv[]){
    create_process("bin/process1.exe", 9);
    create_process("bin/process2.exe", 7);
    create_process("bin/process3.exe", 2);
    create_process("bin/process4.exe", 1);
    create_process("bin/process5.exe", 5);
    syscall_run_all();
    return 0;
}
