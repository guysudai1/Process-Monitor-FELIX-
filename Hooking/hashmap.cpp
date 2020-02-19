#include "hashmap.h"

unsigned int hash(char *str, unsigned int max_elements) {
	unsigned int hash = 5381;
	int c;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; // hash * 33 + c 
	return hash % max_elements;
}
