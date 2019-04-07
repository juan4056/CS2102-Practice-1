#include <iostream>
#include <string>

using namespace std;

int main(){
    string str, ans;
    while(getline (cin,str)){
        int i = 0;
        for(int i = 0; i < str.size(); i++){
            str[i] = str[i]-7;
        }
        cout<<str<<endl;
    }
}
