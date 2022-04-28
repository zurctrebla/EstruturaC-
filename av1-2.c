#include <iostream>
#include <stdlib.h>

using namespace std;

struct Cliente{
	int codigo = 0;
	long cpf = 0;
	char nome[50] = {};
	char telefone[20] = {};
};

struct Veiculo{ //produto
	int placa = 0;      //
	char modelo[50];    //
	int quantidade;
    char fabricacao[12];    //
	// float valor;
    float valor;       //
};

struct Aluguel{   //venda
	int codigo = 0; //
	char data[20];  //
	long cpf = 0;   //
	int produto;
    char placa[12]; //
    double valor;   //
	double total;
	int dias;       //	    
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

void menuRelatorios(){
    cout<<"1 - Total dos Clientes "<<endl;
    cout<<"2 - Total dos Alugueis "<<endl;
    cout<<"3 - Voltar para o Menu principal "<<endl;
}

// float pegarValor(Produto *produto, int codigo){
// 	float valor = 0;
// 	for(int i = 0; i < 100; i++){
// 		if(produto[i].codigo == codigo){
// 			valor = produto[i].valor;
// 			break;
// 		}
// 	}
// 	return valor;
// }

bool validaCpf(Cliente *cliente, long cpf){
	bool resp = false;
	for(int i = 0; i < 100; i++){
		if(cliente[i].cpf == cpf){
			resp = true;
			break;
		}
	}
	return resp;
}

// bool validaProduto(Produto *produto, int codigo){
// 	bool resp = false;
// 	for(int i = 0; i < 100; i++){
// 		if(produto[i].codigo == codigo){
// 			resp = true;
// 		}
// 	}
// 	return resp;
// }

int main(){			
	
	Cliente *pt_cliente = new Cliente[100]; //  cliente
	Veiculo *pt_veiculo = new Veiculo[100]; //  produto
	Aluguel *pt_aluguel = new Aluguel[100]; //  venda

	int op = 0, respProd;
	float total = 0;
	
	do{
        cout<<" ################## Menu Principal ##################"<<endl;
		menuPrincipal();
		cout<<"Qual opção deseja?."<<endl;
		cin>>op;
		switch(op){
			case 1:
				do{
                    cout<<" ################## Menu Cadastros ##################"<<endl;
                    menuCadastros();
                    cout<<"Qual opção deseja?."<<endl;
                    cin>>respProd;
                    switch (respProd){
                        case 1:
                            do{
                                cout<<" ################## Cadastrar Cliente ##################"<<endl;				
                                for(int i = 0; i < 100; i++){
                                	cout<<"CPF "<<pt_cliente[i].codigo<<endl;
                                	if(pt_cliente[i].codigo == 0){
                                		cout<<"Informe o codigo do cliente"<<endl;
                                		cin>>pt_cliente[i].codigo;
                                		cout<<"Informe o cpf do cliente"<<endl;
                                		cin>>pt_cliente[i].cpf;						
                                		cout<<"Informe o nome do cliente"<<endl;
                                		cin>>pt_cliente[i].nome;						
                                		cout<<"Informe o telefone do cliente"<<endl;
                                		cin>>pt_cliente[i].telefone;						
                                		break;
                                	}
                                }
                                break;
                            }while(respProd == 1);
                        break;
                        case 2:
                            do{
                                cout<<" ################## Cadastrar Veiculo ##################"<<endl;				
                                for(int i = 0; i < 100; i++){
                                	cout<<"Placa "<<pt_veiculo[i].placa<<endl;
                                	if(pt_veiculo[i].placa == 0){
                                		cout<<"Informe a placa do veiculo"<<endl;
                                		cin>>pt_veiculo[i].placa;
                                		cout<<"Informe o modelo do veiculo"<<endl;
                                		cin>>pt_veiculo[i].modelo;						
                                		cout<<"Informe a fabricacao do veiculo"<<endl;
                                		cin>>pt_veiculo[i].fabricacao;						
                                		cout<<"Informe o valor do aluguel do veiculo"<<endl;
                                		cin>>pt_veiculo[i].valor;						
                                		break;
                                	}
                                }
                            }while(respProd == 2);
                        break;
                    }
                    
				}while(respProd != 3);				
			break;
			case 2:
                do{
                    cout<<" ################## Registrar Aluguel ##################"<<endl;
                    for(int i = 0; i < 100; i++){
                        cout<<"Codigo "<<pt_aluguel[i].codigo<<endl;
                        if(pt_aluguel[i].codigo == 0){
                            cout<<"Informe o cpf do cliente"<<endl;
                            cin>>pt_aluguel[i].cpf;
                            cout<<"Informe a placa do veiculo"<<endl;
                            cin>>pt_aluguel[i].placa;						
                            cout<<"Informe a data do veiculo"<<endl;
                            cin>>pt_aluguel[i].data;						
                            cout<<"Informe a quantidade de dias"<<endl;
                            cin>>pt_aluguel[i].dias;						
                            break;
                        }
                    }
                }while(respProd != 3);
				
            break;
			case 3:
                do{
                    cout<<" ################## Menu Relatorios ##################"<<endl;
                    menuRelatorios();
                    cout<<"Qual opção deseja?."<<endl;
                    cin>>respProd;

                }while(respProd != 3);
				
            break;
			case 4:
				cout<<"Encerrando o sistema"<<endl;
				delete(pt_cliente);
				delete(pt_veiculo);
				delete(pt_aluguel);
            break;	
		}			
	}while(op != 4);
	
}