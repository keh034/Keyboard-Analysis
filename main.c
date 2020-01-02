#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashMap.h"

int main () 
{
	FILE* fp;
	char buff[255];
	int value;
	char* letSeq;
	char* key = malloc( sizeof(char) * 2 );
	fp = fopen("./scrape.txt", "r");

	HashMap* h = makeHashMap();
	
	while( fscanf(fp, "%s", buff) != EOF ) {
		value = strtol(buff, NULL ,10);
		//printf("%d", value);
		//printf("\t");

		if( fscanf( fp, "%s", buff ) != EOF ) {
			letSeq = buff;
			for( int i = 0; i < strlen(buff)-1; i++ ) {
				strncpy( key, letSeq, 2 );
				//printf("%s ",key);
				
				if( ((float) h->size/h->capacity) > 0.75 ) {
					h = expandCapacity( h );
				}

				insert(h, key, value);
				letSeq++;
			}
			//printf("\n");
		}
	}

	
	printf("%d\n", getValue( h, "ax" ));
	
	//table is filled with the tally
	//find the most common two letter sequences
       //table.list()
       //	implement inside the table class
       //	needs to go through the entire array O(n)
       //		look through the array in table and find the highest five
       //	implementing X letter sequence
       //		issue: ab + bc = abc?
       //		assume not an issue
       //		get the X before we start and then run above to look for X letter seq
       //			easy for list now (still O(n))	
       //table.get("abcde")
       //	ab + bc + cd = de = get(key for each) and add values together

	destroy(h);
	return 0;
}
