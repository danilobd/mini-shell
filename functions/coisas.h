#include <stdlib.h>
#include <sys/wait.h> //lib para usar wait()

#define clear() system("clear cls");

/* DIVITE A STRING POR ESPAÇOS */
void Corta(char *aux, char *comando, char *parametro, char *divideEm){

	int i=0;
	
	char *String = strtok(aux, divideEm);

	while(String){

	    if(i == 0)
	    	strcpy(comando, String);
	    else if(i == 1)
	    	strcpy(parametro, String);

	    String = strtok(NULL, " ");
	    i++;
	}

}

//CALCATENA STRINGS
void Calcatena(char *a, char *b, char *back){

	//JUNTA b EM a
	strcat(back, a);
	strcat(back, b);

}

/*VERIFICA SE O ARQUIVO EXISTE*/
int VerificaComando(char *path, char *comando){

	char aux[154];

	Calcatena(path, comando, aux);
	
	FILE *pointFile = fopen(aux, "r");
	
	if (!pointFile)
		return 0;
	else{
		return 1;
		fclose(pointFile);
	}

}

/* CRIA UM PROCESSO E EXECUTA O PROGRAMA */
void RodaProcesso(char *PATH, char *PROGRAMA, char *PARAMETRO){

	char caminho[102];
	Calcatena(PATH, PROGRAMA, caminho);

	pid_t child_pid;
	int status;

	/* Cria processo filho */
	child_pid = fork();

	if( child_pid == 0 ){
		
		/* Código do processo filho */
		/* Substitui imediatamente sua imagem pelo programa EM 'comando' */
		execl(caminho, PROGRAMA, PARAMETRO, NULL);
		
		perror("execl");
		exit(EXIT_FAILURE);

	}else if( child_pid < 0 ){

		/* Se houver erro ao criar processo filho */
		perror("fork");
		exit(EXIT_FAILURE);

	}else{

		/* Código do processo pai continua aqui */
		/* Aguarda processo filho terminar e recebe status */
		wait(& status);

		/* Verifica se o processo filho terminou normalmente */
		if( WIFEXITED(status) );
			//fprintf(stdout, "\nComando executado com sucesso.\n\n" );
		else
			fprintf(stdout, "\nErro: Comando não executado.\n\n");

	}

}