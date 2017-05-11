#include "../include/list.h"
#define NULL ((void *)0)
void list_init(list_head_t *list)
{
	list->head = list->tail = NULL;
}

void list_add_head(list_head_t *list, list_t * element)
{
	element->next = list->head;
	list->head = element;
	if (element->next == NULL) {
		list->tail = element;	
	}
}

void list_add(list_head_t *list, list_t *element)
{
	if (list->head == NULL) {
		list->head = list->tail = element;
	} else {
		list->tail->next = element;
		list->tail = element;
	}
	element->next = NULL;
}

void list_remove(list_head_t *list, list_t *element)
{
	list_t *l = list->head;
	if (l != NULL) {
		//remove first
		if (element == l) {
			list->head = l->next;
			if (list->head == NULL) {
				list->tail = NULL;
			}
		} else {
			for (; (l->next) && (l->next != element); (l = l->next));
			
			if (l->next != NULL) {
				//remove element
				if (list->tail == l->next) {
					list->tail = l;
				}
				l->next = l->next->next;
			}
		}
	}
}
