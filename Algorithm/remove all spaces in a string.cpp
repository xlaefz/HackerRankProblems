//remove arbitrary spaces in a string

void removeSpaces(char* str){
	int count = 0;
	for(int i =0; str[i]; i++){
		if(str[i] != ' '){
			str[count++] = str[i];
		}
	}
	str[count] = '\0';
}