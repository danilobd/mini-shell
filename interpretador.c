#include <stdio.h>
#include <string.h>
#include <unistd.h>

void Corta(char *aux, char *comando, char *parametro);
int VerificaComando(char *path);

int main(int argc, char const *argv[])
{
	
	char comando[75], parametro[75];
	char aux[150];
	char path[79] = "functions/";

	//TRANSFERE O COMANDO INTEIRO PARA UMA VARIAVEL AUXILIAR
	strcpy(aux, argv[1]);

	//CHAMA A FUNÇÃO PARA SEPARAR O COMANDO DO parametro: 'mov' e 'a/b'
	Corta(aux, comando, parametro);

	//PEGA O COMANDO E JUNTA COM 'functions/': 'functions/mov'
	strcat(path, comando);

	//CHAMA A FUNÇÃO QUE VERIFICA SE TEM UM ARQUIVO NA PASTA functions COM O NOME DO COMANDO
	int fileExist = VerificaComando(path);


	if(fileExist == 0)
		printf("'%s' não encontrado\n", comando); //SE NÃO EXISTIR, DA COMANDO NÃO ENCONTRADO
	else
		execl(path, comando, parametro, NULL); //SE EXISTIR, EXECUTA AQUELE ARQUIVO

}

/*DIVITE A STRING POR ESPAÇOS*/
void Corta(char *aux, char *comando, char *parametro){

	int i=0;
	
	char *String = strtok(aux," ");

	while(String){

	    if(i == 0)
	    	strcpy(comando, String);
	    else if(i == 1)
	    	strcpy(parametro, String);

	    String = strtok(NULL, " ");
	    i++;
	}

}

/*VERIFICA SE O ARQUIVO EXISTE*/
int VerificaComando(char *path){

	FILE *pointFile = fopen(path, "r");
			
	if (!pointFile)
		return 0;
	else{
		return 1;
		fclose(pointFile);
	}

}