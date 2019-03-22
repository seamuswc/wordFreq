void sort(list * l) {

    int temp_count;
    char temp_word[30];

   	list_node *head = l->head; 

    while(head) {

    	list_node *tmp = l->head; 
    	
    	while(tmp->next != NULL) {
                		
        	if(tmp->word_count > tmp->next->word_count) {
        	  temp_count = tmp->word_count;
          	  strcpy(temp_word, tmp->word);  //char *strcpy(char *dest, const char *src)

          	  tmp->word_count = tmp->next->word_count;
          	  strcpy(tmp->word, tmp->next->word);
          	  
          	  tmp->next->word_count = temp_count;
          	  strcpy(tmp->next->word, temp_word);
        	}
        	tmp = tmp->next;
   		}

		head = head->next;    
		
	}        
}