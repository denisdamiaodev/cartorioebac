#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //Função responsável por registrar os cadastros no sistema.
{
	//início da criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário.
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir o mesmo arquivo já criado.
	fprintf(file, ","); //adicionar vírgula para separar os campos.
	fclose(file); //fechar o arquivo.
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário.
	scanf("%s",nome); //%s refere-se a string.
	
	file = fopen(arquivo, "a"); //abrir o mesmo arquivo já criado.
	fprintf(file,nome); //adicionar o nome a ser cadastrado.
	fclose(file); //fechar o arquivo.
	
	file = fopen(arquivo, "a"); //abrir o mesmo arquivo já criado.
	fprintf(file, ","); //adicionar vírgula para separar os campos.
	fclose(file); //fechar o arquivo.
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário.
	scanf("%s", sobrenome); //%s refere-se a string.
	
	file = fopen(arquivo, "a"); //abrir o mesmo arquivo já criado.
	fprintf(file,sobrenome); //adicionar o sobrenome a ser cadastrado.
	fclose(file); //fechar o arquivo.
	
	file = fopen(arquivo, "a"); //abrir o mesmo arquivo já criado.
	fprintf(file, ","); //adicionar vírgula para separar os campos.
	fclose(file); //fechar o arquivo.
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário.
	scanf("%s", cargo); //%s refere-se a string.
	
	file = fopen(arquivo, "a"); //abrir o mesmo arquivo já criado.
	fprintf(file,cargo); //adicionar o cargo a ser cadastrado.
	fclose(file); //fechar o arquivo.
	
	printf("\nCadastro finalizado com sucesso!\n\n");
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	//início da criação das variáveis/string.
	char cpf[40];
	char conteudo [200];
	//final da criação das variáveis/string.
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário.
	scanf("%s",cpf); //%s refere-se a string.
	
	FILE *file; //chamar o arquivo
	file = fopen(cpf,"r"); //consultar o arquivo pelo número do CPF e o "r" significa ler. 
	
	if(file == NULL) //caso o arquivo não seja encontrado.
	{
		printf("Arquivo não localizado.\n\n"); //mensgem de erro da consulta.
	}
	
	while(fgets(conteudo, 200, file) != NULL) //arquivo encontrado.
	{
		printf("\nEssas são as informações do usuário: "); //mensagem de confirmação de arquivo encontrado.
		printf("%s", conteudo); //mostrar informações salvas no arquivo.
		printf("\n\n"); //pular linhas (estética na tela do aplicativo).
	}
	
	fclose(file); //fechar o arquivo.
	system("pause");
	
}

int deletar()
{
	//início da criação das variáveis/string.
	char cpf[40];
	//final da criação das variáveis/string.
	
	printf("Digite o CPF do Usuário a ser deletado: "); //coletando informação do usuário.
	scanf("%s",cpf); //%s refere-se a string.
	
	remove(cpf); //apagar registro.
	printf("\nUsuário deletado com sucesso!\n\n"); //mensagem de confirmação de registro deletado.
	system("pause");
	
	FILE *file; //chamar o arquivo
	file = fopen(cpf,"r"); //consultar o arquivo pelo CPF e o "r" significa ler.
	
	if(file == NULL) //caso o arquivo não seja encontrado.
	{
		printf("\nUsuário não se encontra no sistema!\n\n"); //mensagem de arquivo não encontrado.
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1; //chamar laço de repetição.
	
	for (laco=1; laco=1;) //permanecer no laço de repetição, sem incremento (número de vezes) ou encerrar o programa.
	{
	
		system("cls"); //limpar a tela.
	
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem.
	
		printf("### Cartório da EBAC ###\n\n");//início do menu.
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//fim do menu.
	
		scanf("%d", &opcao);//armazenando a escolha do usuário
	
		system("cls"); //limpar a tela.
		
		switch(opcao)
		{
			case 1:
			registrar(); //chamada de função.
			break;
			
			case 2:
			consultar(); //chamada de função.
			break;
			
			case 3:
			deletar(); //chamada de função.
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível\n\n"); //mensagem de erro caso opção não exista.
			system("pause");
			break;
		}
	
		
		printf("Esse software é de livre uso dos alunos da EBAC\n");
	}
}
