#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include "list.h"


struct list_node *list_add(struct list_node *new,struct list_node *next, struct list_node *prev) {
        new->next = next;
        new->prev = prev;
        return new;
}
struct list_node *list_del_after(struct list_node *pos) {
       struct list_node *deleted = pos->next;
       if ( pos->next!= NULL) {
          pos->next = pos->next->next;  
       }
   
	return 0;
}

//struct information - we will fill via  function <create_info>
struct information *create_info(char* name, int result, int game_result,char* time_stamp) {//tool for list creating

        struct information *info = malloc(sizeof(struct information));
        info->result = result;
        info->name = name;
        info->game_result = game_result;
        info->time_stamp = time_stamp;
        info->list.next =NULL;
	info->list.prev = NULL;
        return info;
      
   };