void deleteDups(LinkedListNode n){
	HashSet<Integer> set = new HashSet<Integer>();
	LinkedListNode prev = null;
	while(n!=null){
		if(set.contains(n.data)){
			prev.next = n.next;
		}else{
			ste.add(n.data);
			previous = n;
		}
		n = n.next;

	}
}