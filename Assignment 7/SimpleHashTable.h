#include "node.h"
#include "helpers.h"


#ifndef ALPHABET
#define ALPHABET = "0123456789abcdefghijklmnopABCDEFGHIJKLMNOP "
#endif

#ifndef SIMPLE_HASH_TABLE_H_INCLUDE
#define SIMPLE_HASH_TABLE_H_INCLUDE

class SimpleHashTable {
private:
	node* data[15628] = { nullptr };

public:
	node* insert(string key, int value) {

	}

	node* contains(string key) {

	}

	node* remove(string key) {

	}
};

#endif