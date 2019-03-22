int get_words(char * filename, list * l) {

    FILE * filp;
    int word_count = 0; 
    char c;
    char word[50];
    int char_count = 0;

    filp = fopen(filename, "r");
    if(filp == NULL) {
        printf("\n %s file not found \n", filename);
        exit(0);
    }

   

    while(  (c = fgetc(filp)) ) {
        if ( isalpha(c) || c == '-' || c == '\'' ) {
            word[char_count] = tolower(c);
            char_count++;
        } else if( c ==  ' ' || c == '\n' || c == '\r' || c == '\0' || c == EOF) {

            //add word count
            word_count++;

            //add a stopper to string end and reset char count
            word[char_count] = '\0';
            char_count = 0;

            //make sure the parse didnt recoginze an empty line as a word
            if (word[0] == '\0' && c != EOF) {
                word_count--;
                continue;
            }

            //add the word to the linked list if does not exist else count++ it on list
            if(word_exists(l,word) !=0)
                push_front(l, word);  

            //if the final word ends on a EOF break loop
            if (c==EOF)
                break;
            
        } 

    }

    //make sure the file was not empty and it got read as having content
    if (word_count == 1 && word[0] == '\0'){
        word_count--;
        free_nodes(l);
    }

    fclose(filp);        
    return word_count;

}



void getFilename(char * filename, int size) {
        
    printf("Please enter the desired file \n");
    fgets (filename , size , stdin);
    
    if ( filename[strlen(filename) - 1] == '\n' )
        filename[strlen(filename) - 1] = '\0' ;

}