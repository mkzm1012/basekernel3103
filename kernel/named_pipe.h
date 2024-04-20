// header file for named pipe

#ifndef NAMED_PIPE_H
#define NAMED_PIPE_H

#include "fs.h"
#include "pipe.h"

#define MAX_NAMED_PIPES 100

struct named_pipe {
    struct pipe *base_pipe;
    char *path; 
};

struct named_pipe_mapping {
    struct named_pipe *named_pipe;
    struct fs_dirent *file;
};

int named_pipe_create(const char *fname); 
int named_pipe_open(const char *fname, struct named_pipe **np_out); 


#endif