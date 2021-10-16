#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



int main()
{
   int data = 10;
   printf("status of queue - %d\n",isEmpty());
   //enqueue(data);
   
   for (int i =0; i<100; i++)
   {
       enqueue(data+i);
   }
   for (int i =0; i<100; i++)
   {
     printf("%d ",queue[i]);
     
   }
   printf("\nstatus of queue - %d\n",isEmpty());
   printf("back => %d\n", getBack());
   printf("%d\n", dequeue());
   printf("Front => %d\n", getFront());
   
}



