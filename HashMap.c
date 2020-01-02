#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HashMap.h"

HashMap* makeHashMap() {
	HashMap* hm = calloc(1, sizeof(HashMap) );
	hm->capacity = 10;
	hm->size = 0;
	hm->buckets = calloc(hm->capacity, sizeof(Node*) );
	return hm;
}
void destroy(HashMap* h) {
	Node* it;
	Node* old;
	for( int i = 0; i < h->capacity; i++ ) {
		it = (h->buckets)[i];
		old = (h->buckets)[i];
		while( it != NULL ) {
			old = it;
			free( old->key );
			free( old );
			it = it->next;
		}
	}
	free( h->buckets );
	free( h );

}
HashMap* expandCapacity(HashMap* h) {
	HashMap* hm = calloc(1, sizeof(HashMap));
	hm->capacity = h->capacity * 2;
	hm->size = 0;
	hm->buckets = calloc( hm->capacity,  sizeof(Node*) );

	Node* ab;
	for( int i = 0; i < h->capacity; i++ ) {
		ab = (h->buckets)[i];
		while( ab != NULL ) {
			insert( hm, ab->key, ab->value );
			ab = ab->next;
		}
	}

	destroy(h);
	return hm;
}
void insert( HashMap* h, char* k, int v ) {
	Node* n = calloc(1, sizeof( Node ) );
	n->key = calloc(1, sizeof(char*) );
	strcpy(n->key, k);
	n->value = v;
	n->next = NULL;

	int loc = hash(h, k);
	Node* it = (h->buckets)[loc];
	Node* prev = it;
	
	if( (h->buckets)[loc] == NULL ) {
		(h->buckets)[loc] = n;
	}  else {
		while( it != NULL ) {
			if( strcmp( it->key, k ) == 0 ) {
				it->value = it->value + v;
				free( n );
				return;
			}
			prev = it;
			it = it->next;
		}
		prev->next = n;
	}
	h->size = h->size + 1;
}


char* list( HashMap* h) {
	char* init = "``";
	char* topFive[5];
	
	for( int i = 0; i < 5; i++ ) {
		topFive[i] = init;
	}

	Node* it;
	for( int i = 0; i < h->capacity; i++ ) {
		it = (h->buckets)[i];
		while( it != NULL ) {
			
			for( int a = 0; a < 5; a++ ) {
				if( getValue(h,it->key) >= getValue(h,topFive[a]) ) {
					
				}
			}


			it = it->next;
		}
	}

	return topFive[0];
}

int getValue( HashMap* h, char* k ) {
	int loc = hash( h, k );

	Node* it = (h->buckets)[loc];
	while( it != NULL ) {
		if( strcmp( it->key, k ) == 0 ) {
			return it->value;
		}
		it = it->next;
	}
	return 0;
}

int hash(HashMap* h, char* k ) {
	int ret = 0;
	for( int i = 0; i < strlen(k); i++ ) {
		ret += ret*3 + k[i];
	}
	return ret % h->capacity;
}
