#include <stdio.h>
#include "HashMap.h"

int main() {
	HashMap* hm = makeHashMap();
	insert( hm, "ab", 3); 
	
	Node* it;
	for( int i = 0; i < hm->capacity; i++ ) {
		it = hm->buckets[i];
		while( it != NULL ) {
			it = it->next;
		}
	}
	return 0;
}
