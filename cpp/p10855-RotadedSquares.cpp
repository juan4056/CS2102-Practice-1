#include <string>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void rotate(string * &square, int n){
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            char temp = square[i][j];
            square[i][j] = square[n - 1 - j][i];
            square[n - 1 - j][i] = square[n - 1 - i][n - 1 - j];
            square[n - 1 - i][n - 1 - j] = square[j][n - 1 - i];
            square[j][n - 1 - i] = temp;
        }
    }
}

int main(){
    int n, m, n_1, m_1;
    int rotation[4] = {0};
    cin>>n>>m;
    while(n>0 && m>>0){
        n_1 = n;
        m_1 = m;
        auto * squaref = new string [n], * squares = new string [m];
        while(n_1){
            cin>>squaref[n-n_1];
            n_1--;
        }
        while(m_1){
            cin>>squares[m-m_1];
            m_1--;
        }

        for (int &r : rotation) {
            for (int i = 0; i < n - (m - 1); i++) {
                for (int j = 0; j < n - (m - 1); j++) {
                    if (squaref[i].substr(j, m) == squares[0]) {
                        int x = 1;
                        for (; x < m; x++) {
                            if (squaref[i + x].substr(j, m) != squares[x])
                                break;
                        }
                        if(x == m)
                            r++;
                    }
                }
            }
            rotate(squares, m);
        }

        cout<<rotation[0]<<" "<<rotation[1]<<" "<<rotation[2]<<" "<<rotation[3]<<endl;

        delete [] squaref;
        delete [] squares;
        for (int &rr : rotation)
            rr = 0;
        cin>>n>>m;
    }
}