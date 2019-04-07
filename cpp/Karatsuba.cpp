#include <iostream>
#include <math.h>
using namespace std;

void eliminate0(string & str){
    unsigned long int it = 0;
    while(str[it]=='0' && it<str.size())
        it++;
    if (it >= str.size()) {
        str = '0';
    } else {
        str = str.substr(it, str.size() - it);
    }
}
string suma(string x, string y){
    int dif = int(y.size()-x.size());
    if(x.size()<y.size()) {
        for(int i = 0; i < dif; i++)
            x="0"+x;
    } else if(x.size()>y.size()) {
        for(int i = 0; i < dif*-1; i++)
            y="0"+y;
    }
    string result;
    int extra = 0;
    int var;
    for(int i = 0; i < y.size(); i++){
        var = extra + (int(x[x.size()-1-i])-48) + (int(y[y.size()-1-i])-48);
        result = to_string(var%10) + result;
        extra = var/10;
    }
    result = to_string(extra) + result;
    eliminate0(result);
    return result;
}

void reduce (string &x, int pos){
    if(x[pos] == '0'){
        x[pos] = '9';
        reduce(x, pos-1);
    }
    else{
        x[pos] = char(x[pos] - 1);
    }
}

string resta(string x, string y){
    string result;
    int dif = int(x.size() - y.size());
    for(int i = 0; i < dif; i++) {
        y = "0" + y;
    }
    int intx [x.size()];
    int var;
    for(int i = 0; i < y.size(); i++){
        if((x[x.size()-1-i]) >= y[y.size()-1-i])
            intx[x.size()-1-i] = int(x[x.size()-1-i])-48;
        else{
            intx[x.size()-1-i] = (int(x[x.size()-1-i])-48)+10;
            reduce(x, int(x.size() - 2 - i));
        }

        var = intx[x.size()-1-i] - (int(y[y.size()-1-i])-48);
        result = to_string(var) + result;
    }

    eliminate0(result);

    return result;
}

string karatsuba(string num1, string num2){

    if(num1.size()<2 && num2.size()<2){
        return to_string(((num1[0])-48)*((num2[0])-48));
    }

    int dif = int(num2.size()-num1.size());
    if(num1.size()<num2.size()) {
        for(int i = 0; i < dif; i++)
            num1="0"+num1;
    } else if(num1.size()>num2.size()) {
        for(int i = 0; i < dif*-1; i++)
            num2="0"+num2;
    }

    int m = min (num1.size(),num2.size());
    m = m/2;

    string high1, low1, high2, low2;

    high1 = num1.substr(0, num1.size() - m);
    low1 = num1.substr(num1.size() - m, m);

    high2 = num2.substr(0, num2.size() - m);
    low2 = num2.substr(num2.size() - m, m);

    eliminate0(high1); eliminate0(low1); eliminate0(high2); eliminate0(low2);

    string z0 = karatsuba(low1,low2);
    string z1 = karatsuba(suma(low1,high1),suma(low2,high2));
    string z2 = karatsuba(high1,high2);

    string prod = suma(suma(z2 + to_string(pow(10,2*m)).substr(1,2*m),resta(z1,suma(z0,z2)) + to_string(pow(10,m)).substr(1,m)),z0);
    eliminate0(prod);
    return prod;
}


int main(){
    string a = "3141592653589793238462643383279502884197169399375105820974944592";
    string b = "2718281828459045235360287471352662497757247093699959574966967627";
    cout<<karatsuba(a,b);

    return 0;
}