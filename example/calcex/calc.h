#ifndef LexCalc_h#define LexCalc_h#include <math.h>typedef union calc_type {	double value;	char* name;	int length;} calc_type;#define YYSTYPE calc_type#endif