#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SECTOR_SIZE 512

int main(int argc, char *argv[]) {
        int offset = 0;
    int length = 5;
    int rc = -1;

    char *sector = aligned_alloc(SECTOR_SIZE, SECTOR_SIZE);
    memset(sector, 0, SECTOR_SIZE);
    /* replace XXX with the source block device */
    int fd=open("hk.zip", __O_DIRECT);

    lseek(fd, offset, SEEK_SET);
    while(1){
        rc = read(fd, sector, SECTOR_SIZE);
         if(rc < 0){
            break;
        }
    };
    free(sector);
    close(fd);
}