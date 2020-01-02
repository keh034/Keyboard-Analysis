typedef struct HashMapNode Node;

struct HashMapNode{
	char* key;
	int value;
	Node* next;
};

typedef struct HashMap HashMap;

struct HashMap {
	int capacity;
	int size;
	Node** buckets;
};

HashMap* makeHashMap();
void destroy(HashMap* h);
HashMap* expandCapacity( HashMap* h);
void insert( HashMap* h, char* k, int v );
char* list( HashMap* h);
int hash(HashMap* h, char* k);
int getValue( HashMap* h, char* k );
