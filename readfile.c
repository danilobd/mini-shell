#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> //lib para usar wait()

typedef struct{
	char comando[40];
}MATRIZ;

int main(int argc, char const *argv[])
{

	if(argc < 2){
		printf("Erro: Arquivo não indicado\n");
		return false;
	}

	char linha[40];
	int i = 0;

	MATRIZ *matriz;
	matriz = (MATRIZ *) malloc(1);

	FILE *file = fopen(argv[1], "r");

	if(file == NULL){
		printf("Erro: não foi possivel abrir '%s'\n", argv[1]);
		return false;
	}else{

		while(!feof(file)){

			fgets(linha,40,file);

			//remove o enter que fgets coloca
			linha[strcspn(linha, "\n")] = 0;

			matriz = (MATRIZ *) realloc(matriz, sizeof(MATRIZ) + 1);

			//matriz[i] = linha;
			strcpy(matriz[i++].comando, linha);

		}

		fclose(file);

		for(int e=0;e<i;e++){
			
			pid_t child_pid;
			int status;

			/* Cria processo filho */
			child_pid = fork();
			
			/*CONVERTE O NÚMERO DA LINHA PARA CHAR PARA PODER MANDAR NO 'EXECL()'*/
			char buffer[40];
			snprintf(buffer, sizeof(buffer), "%d", e+1);
			
			if( child_pid == 0 ){
				
				/* Código do processo filho */
				/* Substitui imediatamente sua imagem pelo programa 'interpretador' */
				execl("interpretador","interpretador", matriz[e].comando, buffer, NULL);
				
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

}