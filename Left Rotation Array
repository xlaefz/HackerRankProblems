#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numcount, numrot;
    cin>> numcount;
    cin >> numrot;
    vector<int> mvec;
    for(int i =0; i < numcount; i++){
        int num;
        cin>>num;
        mvec.push_back(num);
    }
    
    if(numrot > numcount){
        numrot = numrot %numcount;
    }else{
        for(int i = numrot; i < numcount; i ++){
            cout<< mvec[i] <<  " ";
        }
        for(int i =0; i < numrot; i++){
            cout<<mvec[i] << " ";
        }
    }
    return 0;
}
