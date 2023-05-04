#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //Fun��o respons�vel por registrar os cadastros no sistema.
{
	//in�cio da cria��o das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio.
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir o mesmo arquivo j� criado.
	fprintf(file, ","); //adicionar v�rgula para separar os campos.
	fclose(file); //fechar o arquivo.
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio.
	scanf("%s",nome); //%s refere-se a string.
	
	file = fopen(arquivo, "a"); //abrir o mesmo arquivo j� criado.
	fprintf(file,nome); //adicionar o nome a ser cadastrado.
	fclose(file); //fechar o arquivo.
	
	file = fopen(arquivo, "a"); //abrir o mesmo arquivo j� criado.
	fprintf(file, ","); //adicionar v�rgula para separar os campos.
	fclose(file); //fechar o arquivo.
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio.
	scanf("%s", sobrenome); //%s refere-se a string.
	
	file = fopen(arquivo, "a"); //abrir o mesmo arquivo j� criado.
	fprintf(file,sobrenome); //adicionar o sobrenome a ser cadastrado.
	fclose(file); //fechar o arquivo.
	
	file = fopen(arquivo, "a"); //abrir o mesmo arquivo j� criado.
	fprintf(file, ","); //adicionar v�rgula para separar os campos.
	fclose(file); //fechar o arquivo.
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio.
	scanf("%s", cargo); //%s refere-se a string.
	
	file = fopen(arquivo, "a"); //abrir o mesmo arquivo j� criado.
	fprintf(file,cargo); //adicionar o cargo a ser cadastrado.
	fclose(file); //fechar o arquivo.
	
	printf("\nCadastro finalizado com sucesso!\n\n");
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	//in�cio da cria��o das vari�veis/string.
	char cpf[40];
	char conteudo [200];
	//final da cria��o das vari�veis/string.
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio.
	scanf("%s",cpf); //%s refere-se a string.
	
	FILE *file; //chamar o arquivo
	file = fopen(cpf,"r"); //consultar o arquivo pelo n�mero do CPF e o "r" significa ler. 
	
	if(file == NULL) //caso o arquivo n�o seja encontrado.
	{
		printf("Arquivo n�o localizado.\n\n"); //mensgem de erro da consulta.
	}
	
	while(fgets(conteudo, 200, file) != NULL) //arquivo encontrado.
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //mensagem de confirma��o de arquivo encontrado.
		printf("%s", conteudo); //mostrar informa��es salvas no arquivo.
		printf("\n\n"); //pular linhas (est�tica na tela do aplicativo).
	}
	
	fclose(file); //fechar o arquivo.
	system("pause");
	
}

int deletar()
{
	//in�cio da cria��o das vari�veis/string.
	char cpf[40];
	//final da cria��o das vari�veis/string.
	
	printf("Digite o CPF do Usu�rio a ser deletado: "); //coletando informa��o do usu�rio.
	scanf("%s",cpf); //%s refere-se a string.
	
	remove(cpf); //apagar registro.
	printf("\nUsu�rio deletado com sucesso!\n\n"); //mensagem de confirma��o de registro deletado.
	system("pause");
	
	FILE *file; //chamar o arquivo
	file = fopen(cpf,"r"); //consultar o arquivo pelo CPF e o "r" significa ler.
	
	if(file == NULL) //caso o arquivo n�o seja encontrado.
	{
		printf("\nUsu�rio n�o se encontra no sistema!\n\n"); //mensagem de arquivo n�o encontrado.
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1; //chamar la�o de repeti��o.
	
	for (laco=1; laco=1;) //permanecer no la�o de repeti��o, sem incremento (n�mero de vezes) ou encerrar o programa.
	{
	
		system("cls"); //limpar a tela.
	
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem.
	
		printf("### Cart�rio da EBAC ###\n\n");//in�cio do menu.
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");//fim do menu.
	
		scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
		system("cls"); //limpar a tela.
		
		switch(opcao)
		{
			case 1:
			registrar(); //chamada de fun��o.
			break;
			
			case 2:
			consultar(); //chamada de fun��o.
			break;
			
			case 3:
			deletar(); //chamada de fun��o.
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n\n"); //mensagem de erro caso op��o n�o exista.
			system("pause");
			break;
		}
	
		
		printf("Esse software � de livre uso dos alunos da EBAC\n");
	}
}
