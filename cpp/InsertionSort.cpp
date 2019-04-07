#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int> &list){
    if(list.size()>1){
        int key;
        for(int i = 1; i < list.size(); i++){
            key = list[i];
            int j = i-1;
            while(j >= 0 && list[j] > key){
                list[j+1] = list[j];
                j--;
            }
            list[j+1] = key;
        }
    }
}

int main(){
    vector<int> myvec;
    myvec = {4,1,7,2,9};
    InsertionSort(myvec);
    for (int i : myvec) {
        cout<< i <<" ";
    }
    return 0;
}