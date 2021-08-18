#include "list.h"

int main(int argc, char **argv) { 

        struct list_node *head;
        //struct list_node *tail;
        struct list_node *cursor;
        struct information *element;
        struct list_node *prev;
        struct list_node *next;
        static int game_result = 0;
        static int i;
        int ch1=0;
        int result = 0;
	    
	time_t current_time;
        char* c_time_string;
		

        prev = NULL;
        next = NULL;
        head = NULL;
        //tail = NULL;
      for(int i = 0; i<5; i++){//fill the list
        
	if (head!= NULL) {
		
        result = rand() % 7;
        //taking time stamp
        current_time = time(NULL);
        c_time_string = ctime(&current_time);
         //taked time stamp
        game_result= game_result + result;
		 
        element = create_info("player", result,game_result,c_time_string);
        prev = cursor;
        cursor->next = list_add(&element->list,next,prev);
        cursor = cursor->next;
        element = container_of(cursor->prev, struct information, list);
         //printf("%s,%d,%d,%s\n", element->name, element->result, element->game_result, element->time_stamp);
        // printf("%s,%d,%d,%s\n", cursor->prev->name, cursor->prev->result, cursor->prev->game_result, cursor->prev->time_stamp);
	}
	else {

	result = rand() % 7;
	//taking time stamp
	current_time = time(NULL);
	c_time_string = ctime(&current_time);
	//taked time stamp
	game_result= game_result + result;
	element = create_info("player", result,game_result,c_time_string);
	head = list_add(&element->list,next,prev);
	cursor = head;
        }
      }
      for (; cursor!=NULL; cursor = cursor->prev){
          element = container_of(cursor, struct information, list);
          printf("%s,%d,%d,%s\n", element->name, element->result, element->game_result, element->time_stamp);
          puts("------");
        }
        cursor = head;
        printf("-----new-------\n");
        for (; cursor!=NULL; cursor = cursor->next)
        {
                element = container_of(cursor, struct information, list);
                if (i==3)
                {
                        list_del_after(cursor);
                        printf("deleting will be after this item - %s,%d,%d,%s\n", element->name, element->result, element->game_result, element->time_stamp);
                        puts("------");
                        
                       
                }
                else{ 
                printf("%s,%d,%d,%s\n", element->name, element->result, element->game_result, element->time_stamp);
                puts("------");
                i++;
                }
                //free(element);
        }
        cursor = head;
        printf("-----new-------\n");
        for (; cursor!=NULL; cursor = cursor->next){
         element = container_of(cursor, struct information, list);
          printf("%s,%d,%d,%s\n", element->name, element->result, element->game_result, element->time_stamp);
          puts("------");
        }
       
       
        }