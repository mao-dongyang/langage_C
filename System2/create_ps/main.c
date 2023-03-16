#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  pid_t fpid;

  fpid = fork();
  // create child process
  if (fpid == -1)
  {
    perror("perror in fork!");
    exit(EXIT_FAILURE);
  }

  if (fpid == 0)
  {
    printf("I am the child process, my process id is %d\n", getpid());
    sleep(1);
    printf("child process DONE\n");
    exit(EXIT_SUCCESS);
  }
  else
  {
    printf("I am the parent process, my process id is %d\n", getpid());
    wait(NULL);
    printf("parent process DONE\n");
    exit(EXIT_SUCCESS);
  }
  exit(EXIT_SUCCESS);
}
