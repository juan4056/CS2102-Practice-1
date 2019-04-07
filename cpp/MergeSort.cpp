#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int>vector1, vector<int>vector2, vector<int> &vectorMerge){// {5} {1}
    vectorMerge.clear();
    long int pos1 = 0, pos2 = 0;
        while(pos1 < vector1.size() && pos2 < vector2.size()){
        if(vector1[pos1]<vector2[pos2]){
            vectorMerge.push_back(vector1[pos1]);
            pos1++;
        }
        else{
            vectorMerge.push_back(vector2[pos2]);
            pos2++;
        }
    }

    while (pos1<vector1.size()) {
        vectorMerge.push_back(vector1[pos1]);
        pos1++;
    }
    while (pos2<vector2.size()) {
        vectorMerge.push_back(vector2[pos2]);
        pos2++;
    }
}

void MergeSort(vector<int> &list){
    if(list.size()>1) {
        vector<int> first, second;
        for (long int i = 0; i < list.size() / 2; i++)
            first.push_back(list[i]);
        for (long int i = (list.size() / 2); i < list.size(); i++)
            second.push_back(list[i]);

        MergeSort(first);
        MergeSort(second);

        Merge(first, second, list);
    }
}

int main(){
    vector<int> myvec;
    myvec = {4,1,7,2,9};
    MergeSort(myvec);
    for (int i : myvec) {
        cout<< i <<" ";
    }
    return 0;
}