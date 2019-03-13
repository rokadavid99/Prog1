#include <stdio.h>
#include <curses.h>
#include <unistd.h>


main ( void )
{
    WINDOW *ablak;
    ablak = initscr ();

    int x = 0;
    int y = 0; 
   
    int deltax = 1; 
    int deltay = 1; 

    int mx; 
    int my; 
    getmaxyx ( ablak, my , mx ); 
    int magassag[my];
    int szelesseg[mx];
    

    //Feltételes utasítások helyett most for ciklusokat használunk


    for(int i=0;i<mx;i++){
        szelesseg[i]=1;
    }
    
     for(int i=0;i<my;i++){
    magassag[i]=1;
    }
    

    //A keret elérése miatt a kezdő értéket és az utolsó előtti értéket megváltoztatjuk a többi elem abszolút értékére


    szelesseg[0]=-1;
    magassag[0]=-1;
    szelesseg[mx-1]=-1;
    magassag[my-1]=-1;
    
    for ( ;; ) {

        
 
        mvprintw ( y, x, "0" );

        refresh ();
        usleep ( 100000 );

        x = x + deltax; 
        y = y + deltay; 

        deltax*=szelesseg[x];
        deltay*=magassag[y];
    }

    return 0;
}
