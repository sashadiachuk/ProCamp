#include "pt.h"

#include <stdio.h> /* For printf(). */

/* Two flags that the two protothread functions use. */
static int protothread1_flag,protothread4_flag, protothread2_flag,protothread3_flag,important_stuff_done,new_stuff,time_for_important_stuff = 100;

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
    
    while(1) {
    /* Let the other protothread run. */
       PT_WAIT_UNTIL(pt,new_stuff!=0);
       
        time_for_important_stuff--;
        printf("doing some important staff...\n");
        if (time_for_important_stuff == 0) 
            important_stuff_done = 1;
        }
        new_stuff = 1;
        protothread4_flag++;
         printf("time to switch to another important staff\n");
    PT_END(pt);
    
}
static int protothread4(struct pt *pt)
{
    PT_BEGIN(pt);
   
    while (protothread4_flag != 10)
    {
        
        
        PT_WAIT_UNTIL(pt, time_for_important_stuff != 0);
       // PT_WAIT_UNTIL(pt, important_stuff_done!=1);
        printf("start doing some important stuff...\n");
       
        
        time_for_important_stuff = 100;
        important_stuff_done = 0;
        new_stuff = 1 ;
       
        printf("rest");
    }
    return 0;
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
      
   while(PT_SCHEDULE(protothread4(&pt4))) {
         PT_SCHEDULE(protothread3(&pt3));
   }
   /*while(PT_SCHEDULE( protothread4(&pt4))) {
     
      protothread1(&pt1);
      protothread2(&pt2);
      protothread3(&pt3);
     
 
  }*/
    
      
    return 0;
}