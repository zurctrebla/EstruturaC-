#include <iostream>
#include <stdlib.h>

using namespace std;

struct Produto{
	int codigo = 0;
	char nome[50];
	int quantidade;
	float valor;
};

struct Cliente{
	int codigo = 0;
	long cpf = 0;
	char nome[50] = {};
	char telefone[20] = {};
};

struct Venda{
	int codigo = 0;
	char data[20];
	long cpf = 0;
	int produto;
	double total;
	int quantidade;	
};

void menuPrincipal(){
	cout<<"1 - Cadastrar Produtos "<<endl;
	cout<<"2 - Cadastrar Clientes "<<endl;
	cout<<"3 - Registrar Vendas "<<endl;
	cout<<"4 - Exibir o total de todas as vendas "<<endl;
	cout<<"5 - Sair do Sistema "<<endl;		
}

float pegarValor(Produto *produto, int codigo){
	float valor = 0;
	for(int i = 0; i < 100; i++){
		if(produto[i].codigo == codigo){
			valor = produto[i].valor;
			break;
		}
	}
	return valor;
}

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

bool validaProduto(Produto *produto, int codigo){
	bool resp = false;
	for(int i = 0; i < 100; i++){
		if(produto[i].codigo == codigo){
			resp = true;
		}
	}
	return resp;
}

int main(){			
	
	Cliente *pt_cliente = new Cliente[100];
	Produto *pt_produto = new Produto[100];
	Venda *pt_venda = new Venda[100];

	int op = 0, respProd;
	float total = 0;
	
	do{
		menuPrincipal();
		cout<<"Informe a operação desejada."<<endl;
		cin>>op;
		switch(op){
			case 1:
				do{
					cout<<"Cadastrar Produtos"<<endl;
					for(int i = 0; i < 100; i++){						
						if(pt_produto[i].codigo == 0){
							cout<<"Informe o codigo do produto"<<endl;
							cin>>pt_produto[i].codigo;
							cout<<"Informe o nome do produto"<<endl;
							cin>>pt_produto[i].nome;
							cout<<"Informe a quantidade do produto"<<endl;
							cin>>pt_produto[i].quantidade;
							cout<<"Informe o valor do produto"<<endl;
							cin>>pt_produto[i].valor;
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
			case 3:
				cout<<"Cadastrar Vendas"<<endl;
				long cpf;
				int produto;
				
				for(int i = 0; i < 100; i++){
					cout<<"CPF "<<pt_venda[i].cpf<<endl;
					if(pt_venda[i].codigo == 0){
						cout<<"Informe o cpf do cliente"<<endl;
						cin>>cpf;
						if(validaCpf(pt_cliente, cpf)){
							pt_venda[i].cpf = cpf;
						}else{
							break;
						}						
							
						cout<<"Informe o codigo do produto"<<endl;
						cin>>produto;
						if(validaProduto(pt_produto, produto)){
							pt_venda[i].produto = produto;	
						}else{
							break;
						}
												
						cout<<"Informe o codigo da venda"<<endl;
						cin>>pt_venda[i].codigo;
						cout<<"Informe a data da venda"<<endl;
						cin>>pt_venda[i].data;					
						cout<<"Informe a quantidade do produto"<<endl;
						cin>>pt_venda[i].quantidade;						
												
						break;
					}
				}
				
				break;
			case 4:
				total = 0;
				for(int i = 0; i < 100; i++){
					if(pt_venda[i].codigo > 0){
						total += pegarValor(pt_produto, pt_venda[i].produto) * pt_venda[i].quantidade;
					}
				}
				cout<<"Total: "<<total<<endl;
				break;
			case 5:
				cout<<"Encerrando o sistema"<<endl;
				delete(pt_cliente);
				delete(pt_produto);
				break;	
		}			
	}while(op != 5);
	
}





