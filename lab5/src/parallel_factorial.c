#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <getopt.h>
#include <sys/time.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

typedef struct args
{
    uint64_t factorial;
    uint64_t result;
    uint64_t multiplier;
    uint64_t mod;
}args;

void *calculations(void* arg)
{
    args* buff = (args*)arg;
    buff->factorial *= buff->multiplier;
    buff->result *= buff->multiplier;
    buff->result %= buff->mod; 
    return (void*)buff;
}


int main(int argc, char* argv[])
{
  uint32_t k = 0;
  uint32_t pnum = 0;
  uint32_t mod = 0;

  static struct option options[] = {{"k", required_argument, 0, 0},
                                      {"pnum", required_argument, 0, 0},
                                      {"mod", required_argument, 0, 0},
                                      {0, 0, 0, 0}};
  
  while (true) {
    int current_optind = optind ? optind : 1;

    int option_index = 0;
    int c = getopt_long(argc, argv, "", options, &option_index);

    if (c == -1) break;

    switch (c) {
      case 0:
        switch (option_index) {
          case 0:
            k = atoi(optarg);

            break;
          case 1:
            pnum = atoi(optarg);

            if(pnum == 0)
           {
               printf("Threads number is a positive number\n");
           }

            break;
          case 2:
            mod = atoi(optarg);

            if(mod == 0)
           {
               printf("Module is a positive number.\n");
           }

            break;

          defalut:
            printf("Index %d is out of options\n", option_index);
        }
        break;

      default:
        printf("getopt returned character code 0%o?\n", c);
    }
  }

  if (optind < argc) {
    printf("Has at least one no option argument\n");
    return 1;
  }

  if (pnum == 0 || mod == 0) {
    printf("Usage: %s --k \"num\" --pnum \"num\" --mod \"num\" \n",
           argv[0]);
    return 1;
  }
  
  args* arguments;
  arguments->mod = mod;
  arguments->factorial = 1;
  arguments->result = 1;
  pthread_t threads[pnum];

  for(uint64_t i = 0;i < pnum; i++)
  {
      arguments->multiplier = i + 1;
    if(pthread_create(&threads[i], NULL, calculations, (void*) arguments) != 0)
    perror("pthread_create");
  }

    return 0;
}