#ifndef DATATYPES_H_
#define DATATYPES_H_

#include <stdlib.h>

typedef int BOOL;
enum {FALSE,TRUE};

typedef void * TYPE;

TYPE int_create(int i);
TYPE float_create(float f);
TYPE char_create(char c);
TYPE double_create(double d);
TYPE string_create(char *s);
int int_val(TYPE d);
float float_val(TYPE d);
char char_val(TYPE d);
double double_val(TYPE d);
char *string_val(TYPE d);



#endif /* DATATYPES_H_ */