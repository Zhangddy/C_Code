#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* array;
	size_t size;
	size_t capicity;
}SeqList;

#endif //SEQLIST_H_