#include <iostream>
#include <math.h>

using namespace std;

void eliminate0(string & str){
    unsigned long int it = 0;
    while(str[it]=='0' && it<str.size())
        it++;
    if (it >= str.size())
        str = '0';
    else
        str = str.substr(it, str.size() - it);
}

int to_int(char c){
    return int(c)-48;
}

string invertir(char a[], int n){
    string res;
    for(;n>0;n--)
        res += a[n-1];
    return res;
}

string multiplys(string x, string y){
    char a[x.size()], b[y.size()], pro[x.size()+y.size()];
    string product;
    for(int p = 0; p < x.size(); p++)
        a[p] = x[x.size()-(p+1)];
    for(int q = 0; q < y.size(); q++)
        b[q] = y[y.size()-(q+1)];
    for(int r = 0; r < x.size()+y.size(); r++)
        pro[r] = '0';

    for(int b_i = 0; b_i<y.size();b_i++){
        int carry = 0;
        for (int a_i = 0; a_i < x.size(); a_i++){
            int prod_a_b = to_int(a[a_i])*to_int(b[b_i]);//24
            int temppro = to_int(pro[a_i+b_i]);                 //0
            temppro+=carry+prod_a_b;                            //24
            carry = temppro/10;                                 //2
            pro[a_i+b_i] = char('0' + (temppro % 10));          //4
        }
        pro[b_i + x.size()] = char('0'+carry);
    }

    product = invertir(pro, x.size()+y.size());
    eliminate0(product);

    return product;
}

int main(){
    string a = "3141592653589793238462643383279502884197169399375105820974944592";
    string b = "2718281828459045235360287471352662497757247093699959574966967627";
    cout<<multiplys(a,b);
}
