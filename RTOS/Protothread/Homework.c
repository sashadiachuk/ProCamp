#include "pt.h"

#include <stdio.h> /* For printf(). */

/* Two flags that the two protothread functions use. */
static int protothread1_flag,protothread4_flag, protothread2_flag,protothread3_flag,important_stuff_done,new_stuff,wait_stuff,start_prep=0;
int time_for = 1;

static int protothread1(struct pt *pt)
{
    PT_BEGIN(pt);
    while(1) {
    /* Wait until the other protothread has set its flag. */
    PT_WAIT_UNTIL(pt, protothread2_flag != 0);
    printf("Protothread 1 running\n");

    
    protothread2_flag = 0;
    protothread1_flag = 1;
    
  }
    PT_END(pt);

}
static int protothread2(struct pt *pt)
{
    PT_BEGIN(pt);
    
    while(1) {
    /* Let the other protothread run. */
    protothread2_flag = 1;

    /* Wait until the other protothread has set its flag. */
    PT_WAIT_UNTIL(pt, protothread1_flag != 0);
    printf("Protothread 2 running\n");
    
    /* We then reset the other protothread's flag. */
    protothread1_flag = 0;

    /* And we loop. */
  }
    PT_END(pt);
    
}
static int protothread3(struct pt *pt)
{
    PT_BEGIN(pt);
    time_for = 1;
    while(1) {
    /* Let the other protothread run. */
       
       PT_WAIT_UNTIL(pt, important_stuff_done!=1);
       PT_WAIT_UNTIL(pt, wait_stuff!=0);
      
       printf("doing some important stuff...\n");
       time_for--;
       if (time_for == 0)
        {
              printf("time to switch to another important stuff\n");
              important_stuff_done == 1;
              new_stuff = 0;
        }
        
        printf("waiting for a new stuff\n");
        wait_stuff=0;
        new_stuff = 1;
        time_for = 1;
       
    }
    PT_END(pt);
    

}
static int protothread4(struct pt *pt)
{
    PT_BEGIN(pt);
    time_for = 1;
    while (1)
    {
        new_stuff = 0;
        PT_WAIT_UNTIL(pt,new_stuff !=1 );
      
        
        wait_stuff = 1;
        new_stuff = 0;
        important_stuff_done = 0;
       
        printf(" Preparing for important stuff...\n");  
        time_for--;       
        PT_WAIT_UNTIL(pt, time_for != 0);
      
       
    }
  
   PT_END(pt);
    
}  

static struct pt pt1, pt2, pt3, pt4;
int main()
{

  PT_INIT(&pt1);
  PT_INIT(&pt2);
  PT_INIT(&pt3);
  PT_INIT(&pt4);
  /*
   * Then we schedule the two protothreads by repeatedly calling their
   * protothread functions and passing a pointer to the protothread
   * state variables as arguments.
   */

  
     // protothread1(&pt1);
    //  protothread2(&pt2);
      while(PT_SCHEDULE(protothread4(&pt4))) {
         PT_SCHEDULE(protothread3(&pt3)); } 

   
      
   
 
      
    return 0;
}