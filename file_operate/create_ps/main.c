#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t fpid;

  fpid = fork();
  // create child process
  if (fpid < 0) {
    printf("error in fork!");
  } else if (fpid == 0) {
    printf("I am the child process, my process id is %d\n", getpid());
    sleep(10);
  } else {
    printf("I am the parent process, my process id is %d\n", getpid());
    wait(NULL);
    // exit(0);
  }
  return 0;
}
