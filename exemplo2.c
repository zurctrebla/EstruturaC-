#include <stdlib.h>
#include <iostream>

using namespace std;

struct s_pos{
    int x;
    int y;
};

struct s_circulo{
    struct s_pos c;
    float r;    
};

int main(){
    struct s_circulo *p;

    p = (struct s_circulo *) malloc(sizeof(struct s_circulo));

    if (!p){
        cout<<"Não foi alocado"<<endl;
        exit(1);
    }

    p->c.x = 2;
    p->c.y = 4;
    p->r = 3.2;

    cout<<"X = "<<p->c.x<<endl;
    cout<<"Y = "<<p->c.y<<endl;
    cout<<"R = "<<p->r<<endl;

    free(p);
    
}