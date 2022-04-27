#include <iostream>
#include <math.h>

using namespace std;

int main(){
    float a, b, c, delta, x1, x2;

    cout<<"Informe o valor de A"<<endl; // saida de dados.
    cin>>a; // entrada de dados.

    cout<<"Informe o valor de B"<<endl; // saida de dados.
    cin>>b; // entrada de dados.

    cout<<"Informe o valor de C"<<endl; // saida de dados.
    cin>>c; // entrada de dados.

    delta = (b*b) - (4 * a * c );

    if(delta >= 0){
        x1 = (-b + sqrt(delta)) / (2 * a);

        x2 = (-b - sqrt(delta)) / (2 * a);

        cout<<"X1 = "<<x1<<" X2 = "<<x2<<endl;
    }

}