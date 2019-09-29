#include "user.h"
#include "pstat.h"

int
main(int argc, char **argv)
{
    int f1 = fork();

    if(f1 != 0){
        ps();
        wait();
        exit();
    }
    else
    {

    }
    
    return 0;
}

