#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int>vector1, vector<int>vector2, vector<int> &vectorMerge, long int pos1, long int pos2){
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

void TriMerge(vector<int>vector1, vector<int>vector2, vector<int>vector3, vector<int> &vectorMerge){
    long int pos1 = 0, pos2 = 0, pos3 = 0;
    while(pos1 < vector1.size() && pos2 < vector2.size() && pos3 < vector3.size()){
        if(vector1[pos1]<=vector2[pos2] && vector1[pos1]<=vector3[pos3]){
            vectorMerge.push_back(vector1[pos1]);
            pos1++;
        }
        else if(vector2[pos2]<=vector1[pos1] && vector2[pos2]<=vector3[pos3]){
            vectorMerge.push_back(vector2[pos2]);
            pos2++;
        }
        else{
            vectorMerge.push_back(vector3[pos3]);
            pos3++;
        }
    }
    if(pos1 >= vector1.size())
        Merge(vector2,vector3,vectorMerge,pos2,pos3);
    else if(pos2 >= vector2.size())
        Merge(vector1,vector3,vectorMerge,pos1,pos3);
    else
        Merge(vector1,vector2,vectorMerge,pos1,pos2);
}

void ThreeMergeSort(vector<int> &list){
    if(list.size()>1) {
        vector<int> first, second, third;
        for (long int i = 0; i < list.size() / 3; i++)
            first.push_back(list[i]);
        for (long int i = list.size() / 3; i < 2 * list.size() / 3; i++)
            second.push_back(list[i]);
        for (long int i = 2 * list.size() / 3; i < list.size(); i++)
            third.push_back(list[i]);

        ThreeMergeSort(first);
        ThreeMergeSort(second);
        ThreeMergeSort(third);

        list.clear();
        TriMerge(first, second, third, list);

    }
}