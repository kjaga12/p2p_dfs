
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "fs.h"


size_t get_file_size(char *file_path) {
    struct stat st;
    stat(file_path, &st);
    return st.st_size;
}

size_t fread_full(char *file_path, uint8_t *buff, size_t size) {

    int fd = open(file_path, O_RDONLY);
    if (fd < 0) {
        perror("unable to open file.\n");
        return -1;
    }

    size_t offset = 0;
    while(offset < size) {
        int bytes_read = read(fd, buff + offset, size - offset);
        offset += bytes_read;
    }

    return offset;
}

size_t fwrite_full(char *file_path, uint8_t *buf, size_t size);