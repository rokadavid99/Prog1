#include <curses.h> 
#include <unistd.h> 
#include <stdlib.h> 

int main ( void )
{

    WINDOW *ablak;   	
    ablak = initscr (); 
    int mx;  	
    int my;

    int xj = 0, xk = 0, yj = 0, yk = 0; /

    for ( ;; ) {	


        getmaxyx ( ablak, my , mx ); 			    
   
	      xj = (xj - 1) % mx;	
        xk = (xk + 1) % mx;

        yj = (yj - 1) % my;
        yk = (yk + 1) % my;						
				     		
	    
        mvprintw ( abs (yj + (my - yk) ), abs (xj + (mx - xk)) , "O" ); 

        refresh ();		
        usleep ( 50000);	

	clear();		




    }

    return 0;
}
