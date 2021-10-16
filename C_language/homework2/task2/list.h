
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
/////BLOCK OF LIST LISTING
#define container_of(ptr, type, member) (type *)( (char *)(ptr) - offsetof(type,member) )//marco 
struct list_node{
        struct list_node *next;
        struct list_node *prev;
};
/////BLOCK OF LIST DATA

struct information {
        struct list_node list;
        char* name;
        int result;
        int game_result;
        char* time_stamp;
};
struct list_node *list_add(struct list_node *new,struct list_node *next, struct list_node *prev);
struct list_node *list_del_after(struct list_node *pos);
struct information *create_info(char* name, int result, int game_result,char* time_stamp);