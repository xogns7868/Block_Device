#define _LARGEFILE64_SOURCE

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
    int size;
    long long address;
    scanf("%d", &size);
    scanf("%lld", &address);
    printf("%lld\n", address);
    char *sector = aligned_alloc(SECTOR_SIZE * size, SECTOR_SIZE * size);
    memset(sector, 0, SECTOR_SIZE);
    /* replace XXX with the source block device */
    int fd=open("/dev/sda", O_LARGEFILE | __O_DIRECT);
    lseek(fd, 512 * address, SEEK_SET);
    rc = read(fd, sector, SECTOR_SIZE * size);
    free(sector);
    close(fd);
}
