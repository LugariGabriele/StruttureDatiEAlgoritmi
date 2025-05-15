#ifndef VECTOR_H
#define VECTOR_H


#include "list.h"

enum ConversionType
{
	kInOrder,
	kReverse
};

extern Item* vector2List(const ElemType* v, size_t v_size, enum ConversionType c);
extern ElemType* List2Vector(const Item* i, size_t v_size, enum ConversionType c);

#endif // !VECTOR_H
