WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com

/*
$ dcc list_directory.c
$ ./a.out .
list_directory.c
a.out
.
..
$
*/
#include <stdio.h>
#include <dirent.h>

// list the contents of directories specified as command-line arguments
int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        DIR *dirp = opendir(argv[arg]);
        if (dirp == NULL) {
            perror(argv[arg]);  // prints why the open failed
            return 1;
        }

        struct dirent *de;

        while ((de = readdir(dirp)) != NULL) {
            printf("%ld %s\n", de->d_ino, de->d_name);
        }

        closedir(dirp);
    }
    return 0;
}
