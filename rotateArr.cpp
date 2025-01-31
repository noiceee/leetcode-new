#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int>arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = arr.size();
    vector<int>temp;
    int k = 10;

    k %= len;

    for(int i=len-k; i<len; i++) {
        temp.push_back(arr[i]);
    }

    for(int i=0; i<len-k; i++) {
        temp.push_back(arr[i]);
    }

    for(int i:temp) {
        cout << i << " ";
    }

}