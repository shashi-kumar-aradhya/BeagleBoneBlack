#ifndef __LIST_H_
#define __LIST_H_

typedef struct l_list {
	struct  l_list *next;
} list_t;

typedef struct {
	list_t *head;
	list_t *tail;
} list_head_t;

void list_init(list_head_t *list);
void list_init(list_head_t *list);
void list_add(list_head_t *list, list_t *element);
void list_add_head(list_head_t *list, list_t *element);
void list_remove(list_head_t *list, list_t *element);

#endif



