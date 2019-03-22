
//structs
struct list_node {
  struct list_node *next;
  //struct list_node *prev;
  char word[50];
  int word_count;
}; 
typedef struct list_node list_node;

struct list {
  struct list_node * head;
  int size;
  };
typedef struct list list;

//create
list * create_list() {
	list * l = (list *) malloc(sizeof(list));
	l->head = NULL;
	l->size = 0;
	return l;
}

//empty
bool empty_list(list * l) {
	return l->size == 0;
}

//add front
void push_front(list * l, char * word) {
	list_node * w = (list_node *) malloc(sizeof(list_node));
	strcpy(w->word, word); //w->word = word
	w->word_count = 1;

	/*w->next = w->prev = NULL;	
	if (empty_list(l))
	{
		l->head = w;
		l->size++;
		return;
	}*/

	w->next = l->head;
	//w->next->prev = w;
	l->head = w;
	l->size++;
}


//free everything
void free_nodes(list * l) {
	list_node *next;
	while(l->head) {
		next = l->head->next;
		free(l->head);
		l->head = next;
	}
	if (l->head == NULL)
		free(l);xw
}

//print
void print_list(list * l) {
  	
  	list_node *tmp = l->head;

	while(tmp) {
    	printf("%30s\t%5d\n", tmp->word, tmp->word_count);
    	tmp = tmp->next;
	}

}

void print_singles(list * l) {
  	
  	int count = 0;
  	list_node *tmp = l->head;

	while(tmp) {
		if (tmp->word_count == 1) {
			count ++;
			printf("%30s\t%5d\n", tmp->word, tmp->word_count);
		}
    	tmp = tmp->next;
	}

	printf("Single word count: %d\n",count);

}

//traverse & compare
int word_exists(list * l, char * word) {
	int exists = 1;
	list_node *tmp = l->head;

	while(tmp) {
		exists = strcmp(tmp->word, word);
    	if (exists == 0) {
    		tmp->word_count++;
 	  		return exists; 
 	  	}
 	  	tmp = tmp->next;

  }
  return exists;
}

