#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void jelkezelo(){
    printf("Signal\n");
};

int main(){

    for(;;){
        if(signal(SIGINT, jelkezelo)==SIG_IGN)
            signal(SIGINT, SIG_IGN);
    }

    typedef void (*sighandler_t)(int);

    return 0;

}