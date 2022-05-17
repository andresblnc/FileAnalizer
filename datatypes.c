#include "datatypes.h"

TYPE int_create(int i)
{
	int *data = malloc(sizeof(int));
	*data = i;
	return(data);
}

TYPE float_create(float f)
{
	float *data = malloc(sizeof(float));
	*data = f;
	return(data);
}

TYPE char_create(char c)
{
	char *data = malloc(sizeof(char));
	*data = c;
	return(data);
}

TYPE double_create(double d)
{
	double *data = malloc(sizeof(double));
	*data = d;
	return(data);
}

TYPE string_create(char *s)
{
	int len,i;
	char *s1=s;
	char *snew;

	while(*s1)
		s1++;
	len = s1 - s;

	snew = malloc(len);

	for(i=0;i<len+1;i++)
		snew[i] = s[i];

	return(snew);
}

int int_val(TYPE d)
{
	int retval = *((int *) d);
	// free(d);
	return retval;
}

float float_val(TYPE d)
{
	float retval = *((float *) d);
	// free(d);
	return retval;
}

char char_val(TYPE d)
{
	char retval = *((char *) d);
	// free(d);
	return retval;
}

double double_val(TYPE d)
{
	double retval = *((double *) d);
	// free(d);
	return retval;
}

char *string_val(TYPE d)
{
	return d;
}
