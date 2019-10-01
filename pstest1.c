#include "user.h"
#include "types.h"
#include "pstat.h"

int
main(int argc, char **argv)
{
    for(int x=0; x<8; x++)
    {
        int c = fork();
        if(c == 0){
            sleep(10);
            exit();
        }
    }
    ps();
    wait();
    wait();
    wait();
    wait();
    wait();
    wait();
    wait();
    wait();
    exit();
    
    return 0;
}

