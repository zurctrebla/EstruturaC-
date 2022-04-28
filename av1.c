#include <iostream>
#include <stdlib.h>
// #include <windows.h>

using namespace std;

struct Veiculo{
    int codigo = 0;
    char placa[10];
    char modelo[50];
    int fabricacao;
    float valor;
};

struct Cliente{
    long cpf;
    char nome[50];
    char telefone[20];
};

struct Aluguel{
    int codigo = 0;
    char data[20];
    long cpf;
    int produto;
    float total;
    int quantidade;
};


void menuPrincipal(){
    cout<<"1 - Cadastros "<<endl;
    cout<<"2 - Registrar Aluguel  "<<endl;
    cout<<"3 - Relatórios "<<endl;
    cout<<"4 - Sair do Sistema "<<endl;
}

void menuCadastros(){
    cout<<"1 - Cadastrar Cliente "<<endl;
    cout<<"2 - Cadastrar Veiculo "<<endl;
    cout<<"3 - Voltar para o Menu principal "<<endl;
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
    struct Veiculo *veiculo = (struct Veiculo*) malloc(n * sizeof(struct Veiculo));
    struct Aluguel *aluguel = (struct Aluguel*) malloc(n * sizeof(struct Aluguel));
    

    for(int i = 0; i < n; i++){
        cliente[i].cpf = 0;
        veiculo[i].codigo = 0;
        aluguel[i].codigo = 0;
    }

    do{
        menuPrincipal();
        cout<<"Qual opção deseja?."<<endl;
        cin>>op;
        switch(op){
            case 1:
                do{
                    cout<<"Cadastrar Cliente"<<endl;
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
                    cout<<"Deseja cadastrar outro cliente ? [1 = SIM]"<<endl;
                    cin>>respProd;
                    system("cls");
                }while(respProd == 1);
            break;
            case 2:
                cout<<"Registrar Aluguel"<<endl;
                for(int i = 0; i < n; i++){
                    cout<<"codigo "<<veiculo[i].placa<<endl;
                    if(veiculo[i].placa == 0){
                        cout<<"Informe a placa do veiculo"<<endl;
                        cin>>veiculo[i].placa;
                        cout<<"Informe o modelo do veiculo"<<endl;
                        cin>>veiculo[i].modelo;
                        cout<<"Informe o fabricacao do veiculo"<<endl;
                        cin>>veiculo[i].fabricacao;
                        cout<<"Informe o valor do aluguel do veiculo"<<endl;
                        cin>>veiculo[i].aluguel;
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
                cout<<"Encerrando o sistema"<<endl;
                free(cliente);
                free(veiculo);
                free(aluguel);
                break;
        }
    }while(op != 4);

}