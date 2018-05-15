#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

	//VERIFICA SE RECEBEU PARAMETROS

	if(argc > 1){

		//EXECUTA O PROGRAMA DE LER ARQUIVO, JA QUE FOI PASSADO O NOME DO ARQUIVO
		//COMO ARGUMENTO: './main arquivo.txt'
		execl("readfile","readfile", argv[1], NULL);//local - nome do programa - parametros - indica o final
		
	}
	else
		//SE NÃO RECEBEU, EXECUTA O O PROGRAMA 'console'
		//PARA PODER DIGITAR OS COMANDOS
		execl("console", "console", NULL);


	return 0;
}