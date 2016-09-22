int findcountofanagrams(string word, string [] dictionary){
	string temp = word;
	sort(word.begin(), word.end());
	
	map<string, string> mymap;
	for(int i =0; i < dictionary.length(); i++){
		string wordholder = dictionary[i];
		sort(dictionary[i].begin(), dictionary[i].end());
		auto it = mymap.find(dictionary[i]);
		if(it != mymap.end()){ //found something
			it->second += wordholder;
		}else{
			mymap[dictionary[i]] = wordholder;
		}
	}

	return mymap.find(word)->second;
}