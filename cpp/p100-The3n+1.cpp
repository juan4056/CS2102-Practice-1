#include <string>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

unsigned long int cache[1000000] = {0};

unsigned long int totalcycles(unsigned long int n){
    if(n==1)
        return 1;
    if (n < 1000000) {
        if (cache[n] != 0)
            return cache[n];
    }
    unsigned long int cycles;
    if (n % 2 == 0)
        cycles = 1 + totalcycles(n/2);
    else
        cycles = 2 + totalcycles((3*n+1)/2);
    if (n < 1000000)
        cache[n] = cycles;

    return cycles;
}

int main(){
    unsigned long int a,b,max;
    while(cin>>a>>b) {
        max = 0;
        cout << a << " " << b << " ";
        if(a>b){
            unsigned long int c = b;
            b = a;
            a = c;
        }
        for (unsigned long  i = a; i <= b; i++) {
            unsigned long int cycles = totalcycles(i);
            if (max < cycles)
                max = cycles;
        }
        cout<< max << endl;
    }
}

