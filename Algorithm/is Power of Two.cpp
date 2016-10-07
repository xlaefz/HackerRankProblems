bool isPowerofTwo(int number){
    if((number & number -1) == 0){
        return true;
    }
    return false;
}

vector < int > isPowerOf2(vector < int > arr) {
    vector <int> result;
    int numCases;
    cin >> numCases;
    for(int i =0; i < arr.size(); i++){
        if(isPowerofTwo(arr[i])){
            result.push_back(1);
        }
        else{
            result.push_back(0);
        }
    }
    return result;
}