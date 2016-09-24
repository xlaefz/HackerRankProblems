//remove duplicates in a sorted array

int removeDuplicates(int[] A){
	if(A.length < 2) return A;
	int j = 0;
	int i = 1;
	while(i < A.length){
		if(A[i] == A[j]){
			i++;
		}else{
			j++;
			A[j] = A[i];
			i++;
		}
	}
	int [] B = Arrays.copyOF(A, j+1);
	return B;
}