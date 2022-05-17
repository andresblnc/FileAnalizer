#include "datatypes.h"

#ifndef LIST_H_
#define LIST_H_

struct STRLNODE {
	TYPE letra;
	struct STRLNODE *prior,*next;
};

typedef struct STRLNODE * LNODE;

struct STRLIST {
	LNODE first,last;
	int size;
};

typedef struct STRLIST * LIST;

LIST list_create();
void list_add(LIST list,TYPE data);
TYPE list_pop(LIST list);
int list_size(LIST list);
void list_modify(LIST list,int pos,TYPE data);
TYPE list_get(LIST list,int pos);
void list_destroy(LIST list);

#define list_has_prior(l) (l->prior!=NULL)
#define list_has_next(l) (l->next!=NULL)
#define list_prior(l) (l->prior)
#define list_next(l) (l->next)
#define list_data(l) (l->data)

#endif /* LIST_H_ */