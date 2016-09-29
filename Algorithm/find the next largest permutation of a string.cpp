//find the next largest string permutation

void swap(char&a, char& b){
	char temp =  b;
	b = a;
	a = temp;
}
string nextLargest(string word){
	int left = word.length()-1;
	while(left > 0 && word[left-1] >= word[left]){
		left--;
	} //runs until left is right before is smaller than the current

	if(left <= 0) return word;
	int right = word.length()-1; //starts at the way right of the word
	while(word[right] <= word[left-1]){ //runs until right is bigger than the number left bigger than
		right --;
	}
	swap(word[j] , word[left-1]);
	right = word.length()-1;
	while(left < right){
		swap(word[left], word[right]);
		left++;
		right--;
	}
	return word;

}