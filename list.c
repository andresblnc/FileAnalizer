#include "list.h"

LIST list_create()
{
	LIST new = malloc(sizeof(struct STRLIST));

	new->first = NULL;
	new->last = NULL;
	new->size = 0;
	return new;
}

void list_add(LIST list,TYPE data)
{
	LNODE new = malloc(sizeof(struct STRLNODE));
	new->letra = data;
	new->prior = NULL;
	new->next = NULL;

	if(list->first == NULL)	// �La lista est� vac�a?
	{
		list->first = new;
	}
	else
		list->last->next = new;

	new->prior = list->last;
	list->last = new;
	list->size++;
}

int list_size(LIST list)
{
	return(list->size);
}

TYPE list_get(LIST list,int pos)
{
	LNODE ptr = list->first;
	int i;

	for(i=0;i<pos;i++)
		ptr = ptr->next;

	return(ptr->letra);
}

TYPE list_pop(LIST list){
	LNODE ptr = list->first;
	TYPE data;

	if(list->first == NULL)
		return NULL;

	data = ptr->letra;
	list->first = ptr->next;
	list->first->prior = NULL;
	free(ptr);
	list->size--;
	return data;
}

void list_modify(LIST list,int pos,TYPE data){
	LNODE ptr = list->first;
	int i;

	for(i=0;i<pos;i++)
		ptr = ptr->next;

	ptr->letra = data;
}

void list_destroy(LIST list)
{
	LNODE ptr = list->first;
	LNODE aux;

	while(ptr != NULL)
	{
		aux = ptr->next;
		free(ptr);
		ptr = aux;
	}
	free(list);
}