#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h> //lib para usar wait()

//#define clear() system("clear cls");
void Verifica(char *comando);

int main(int argc, char const *argv[])
{

	//clear();

	printf("***************************************************************");
	printf("\n 		Bem vindo ao console!\n");
	printf("\nEm caso de dúvidas, digite 'help'. Para sair digite 'exit'\n\n");

	char comando[150];

	while (strcmp("exit",comando) != 0){

		printf(">> ");

		fgets(comando, 150, stdin );

		//remove o enter que fgets coloca
		comando[strcspn(comando, "\n")] = 0;

		Verifica(comando);

	}

	printf("\nTchau!\n\n");

	return 0;
}

void Verifica(char *comando){

	if(strcmp("exit",comando) != 0){

		pid_t child_pid;
		int status;

		/* Cria processo filho */
		child_pid = fork();

		if( child_pid == 0 ){
			
			/* Código do processo filho */
			/* Substitui imediatamente sua imagem pelo programa 'interpretador' */
			execl("interpretador","interpretador", comando, NULL);
			
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

}