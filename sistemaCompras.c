#include <iostream>
#include <stdlib.h>
// #include <windows.h>

using namespace std;

struct Produto{
    int codigo = 0;
    char nome[50];
    int quantidade;
    float valor;
};

struct Cliente{
    long cpf;
    char nome[50];
    char telefone[20];
};

struct Venda{
    int codigo = 0;
    char data[20];
    long cpf;
    int produto;
    float total;
    int quantidade;
};


void menuPrincipal(){
    cout<<"1 - Cadastrar Produtos "<<endl;
    cout<<"2 - Cadastrar Clientes "<<endl;
    cout<<"3 - Registrar Vendas"<<endl;
    cout<<"4 - Exibir o total de todas as vendas "<<endl;
    cout<<"5 - Sair do Sistema "<<endl;
}

bool validarCliente(Cliente *cliente, long cpf, int n){
    bool resp = false;
    for(int i = 0; i < n; i++){
        if(cliente[i].cpf == cpf){
            resp = true;
            break;
        }
    }
    return resp;
}

bool validarProduto(Produto *produto, int codigo, int n){
    bool resp = false;
    for(int i = 0; i < n; i++){
        if(produto[i].codigo == codigo){
            resp = true;
            break;
        }
    }
    return resp;
}

float precoProduto(Produto *produto, int codigo, int n){
    float valor = 0;
    for(int i = 0; i < n; i++){
        if(produto[i].codigo == codigo){
            valor = produto[i].valor;
            break;
        }
    }
    return valor;
}

int main(){
    int op =0, respProd, n;
    float total;

    cout<<"Informe a quantidade de operações desejada"<<endl;
    cin>>n;

    struct Cliente *cliente = (struct Cliente*) malloc(n * sizeof(struct Cliente));
    struct Produto *produto = (struct Produto*) malloc(n * sizeof(struct Produto));
    struct Venda *venda = (struct Venda*) malloc(n * sizeof(struct Venda));

    for(int i = 0; i < n; i++){
        produto[i].codigo = 0;
        cliente[i].cpf = 0;
        venda[i].codigo = 0;
    }

    do{
        menuPrincipal();
        cout<<"Informe a operação desejada."<<endl;
        cin>>op;
        switch(op){
            case 1:
                do{
                    cout<<"Cadastrar Produtos"<<endl;
                    for(int i = 0; i < n; i++){
                        cout<<"Codigo: "<<produto[i].codigo<<endl;
                        if(produto[i].codigo == 0){
                            cout<<"Informe o codigo do produto"<<endl;
                            cin>>produto[i].codigo;
                            cout<<"Informe o nome do produto"<<endl;
                            cin>>produto[i].nome;
                            cout<<"Informe a quantidade do produto"<<endl;
                            cin>>produto[i].quantidade;
                            cout<<"Informe o valor do produto"<<endl;
                            cin>>produto[i].valor;
                            break;
                        }
                    }
                    cout<<"Deseja cadastrar outro produto? [1 = SIM]"<<endl;
                    cin>>respProd;
                    system("cls");
                }while(respProd == 1);
            break;
            case 2:
                cout<<"Cadastrar Clientes"<<endl;

                for(int i = 0; i < n; i++){
                    cout<<"codigo "<<cliente[i].cpf<<endl;
                    if(cliente[i].cpf == 0){
                        cout<<"Informe o cpf do cliente"<<endl;
                        cin>>cliente[i].cpf;
                        cout<<"Informe o nome do cliente"<<endl;
                        cin>>cliente[i].nome;
                        cout<<"Informe o telefone do cliente"<<endl;
                        cin>>cliente[i].telefone;
                        break;
                    }
                }
                system("cls");
                break;
            case 3:
                cout<<"Registrar Vends"<<endl;
                long validarCpf;
                int validaProduto;

                for(int i = 0; i < n; i++){
                    if(venda[i].codigo == 0){
                        cout<<"Informe o cpf do cliente"<<endl;
                        cin>>validarCpf;

                        if(validarCliente(cliente, validarCpf, n)){
                            venda[i].cpf = validarCpf;
                            cout<<"entre cpf"<<endl;
                        }else{
                            cout<<"cpf invalido"<<endl;
                            break;
                            // Sleep(10000000);
                        }

                        cout<<"informe o codigo do produto"<<endl;
                        cin>>validaProduto;
                        if(validarProduto(produto, validaProduto, n)){
                            venda[i].produto = validaProduto;
                        }else{
                            cout<<"Produto invalido"<<endl;
                            break;
                            // Sleep(10000000);
                        }

                        cout<<"Informe o codigo do produto"<<endl;
                        cin>>validaProduto;
                        if(validarProduto(produto, validaProduto, n)){
                            venda[i].produto = validaProduto;
                        }else{
                            cout<<"Produto invalido"<<endl;
                            break;
                            // Sleep(10000000);
                        }

                        cout<<"Informe o codigo da venda"<<endl;
                        cin>>venda[i].codigo;

                        cout<<"Informe a data da venda"<<endl;
                        cin>>venda[i].data;

                        cout<<"Informe a quantidade do produto"<<endl;
                        cin>>venda[i].quantidade;
                        cout<<"Informe o total da venda"<<endl;
                        cin>>venda[i].total;
                        break;
                    }
                }
                system("cls");
                break;
            case 4:
                cout<<""<<endl;
                total = 0;
                for(int i = 0; i < n; i++){
                    if(venda[i].codigo > 0){
                        total = total + (venda[i].quantidade * precoProduto(produto, venda[i].produto, n));
                    }
                }
                cout<<total<<endl;
                cin;
                break;
            case 5:
                cout<<"Encerrando o sistema"<<endl;
                free(cliente);
                free(produto);
                free(venda);
                break;
        }
    }while(op != 5);

}