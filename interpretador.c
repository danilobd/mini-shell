#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "functions/coisas.h"

int main(int argc, char const *argv[])
{
	
	char comando[75], parametro[75];
	char argNovo[150];
	char path[] 	= "functions/"; // Local onde fica as funções
	char divideEm[] = " ";

	// Transfere o comando inteiro para uma variavel auxiliar, porque não funciona passando direto
	strcpy(argNovo, argv[1]);

	// Chama a função para separar o comando do parametro: 'mov' e 'a/b'
	Corta(argNovo, comando, parametro, divideEm);

	// Chama a função que verifica se tem um arquivo na pasta $path com o nome do comando
	if(!VerificaComando(path, comando)){

		if(argv[2]) // Se na 3º possição do argv vier a o número de linha (quando é no console)
			printf("'%s' não definido na linha %s\n", comando, argv[2]); //SE NÃO EXISTIR, DA COMANDO NÃO ENCONTRADO COM A LINHA DO COMANDO NO ARQUIVO
		else	
			printf("'%s' não definido\n", comando); // Se não existir, da comando não encontrado
		
	}
	else{

		// Pasta / nome do programa - comando (nome do programa) - parametros do comando
		RodaProcesso(path, comando, parametro);

	}

}