WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com

/*
$ dcc mkdir.c
$ ./a.out new_dir
$ ls -ld new_dir
drwxr-xr-x 2 z5555555 z5555555 60 Oct 29 16:28 new_dir
$
*/

#include <stdio.h>
#include <sys/stat.h>

// create the directories specified as command-line arguments
int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        if (mkdir(argv[arg], 0755) != 0) {
            perror(argv[arg]);  // prints why the mkdir failed
            return 1;
        }
    }

    return 0;
}
