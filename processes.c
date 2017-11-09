#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

void handler (int signum) {
  if (signum == SIGINT) {
    int f = open("output.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    char chr[64] = "Process termininated due to signal interrupt\n";
    write(f, chr, 64);
    close(f);
    exit(0);
  } else if (signum == SIGUSR1) {
    pid_t pid = getppid();
    printf("Parent Process ID: %d\n", pid);
  }
}

int main() {
  signal(SIGINT, handler);
  signal(SIGUSR1, handler);
  while (1) {
      pid_t pid = getpid();
      printf("Process ID: %d\n", pid);

      sleep(1);
  }
}
