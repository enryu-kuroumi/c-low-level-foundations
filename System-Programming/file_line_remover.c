#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#define MAX 400

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDWR);
    if (fd < 0) {
        perror("Błąd ");
        return 1;
    }
    char n;
    int frln = 0;
    while (read(fd, &n, 1) > 0) {
        frln++;
        if (n == '\n') break;
    }
    long rozm = lseek(fd, 0, SEEK_END);
    long read_pos = frln;
    long write_pos = 0;
    char buf[MAX];
    int bread;
    while (1) {
        if (lseek(fd, read_pos, SEEK_SET) < 0) {
            perror("Błąd lseek");
            return 1;
        }
        bread = read(fd, buf, sizeof(buf));
        if (bread <= 0) break;
        if (lseek(fd, write_pos, SEEK_SET) < 0) {
            perror("Błąd lseek");
            return 1;
        }
        if (write(fd, buf, bread) != bread) {
            perror("Błąd");
            return 1;
        }
        
        read_pos += bread;
        write_pos += bread;
    }
    if (ftruncate(fd, rozm-frln) < 0) {
        perror("Błąd ftruncate");
        close(fd);
        return 1;
    }
    if (close(fd) < 0) {
        perror("Błąd ");
        return 1;
    }
    return 0;
}
