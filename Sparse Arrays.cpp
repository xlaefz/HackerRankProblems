#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<string,int> mymap;
    int numcount;
    cin>>numcount;
    for(int i =0; i < numcount; i++){
        string word;
        cin>>word;
        if(mymap.find(word) != mymap.end()){
            mymap.find(word)->second +=1;
        }else{
            mymap[word] = 1;
        }
    }
    cin>> numcount;
    for(int i =0; i < numcount ; i ++){
        string word;
        cin>>word;
        if(mymap.find(word) != mymap.end()){
            cout<< mymap.find(word)->second << endl;
        }else{
            cout<< 0 << endl;
        }
    }
    return 0;
}
