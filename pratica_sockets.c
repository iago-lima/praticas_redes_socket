#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[]){
	// Declarar variáveis
	struct sockaddr_in s_hora;
	int e_socket;
	int connect_server;
	int recv_server;
	char *hora;
	// Criar socket
	e_socket = socket(AF_INET,SOCK_STREAM,0);
	if(e_socket < 0){
		printf("Erro no socket");
		exit(1);
	}
			
	s_hora.sin_family = AF_INET;
	//Endereço do servidor a se conectar
	s_hora.sin_addr.s_addr = inet_addr("172.18.104.158");
	//zera o resto da estrutura
	bzero(&(s_hora.sin_zero),8);	
	// Conectar ao servidor
	connect_server = connect(e_socket, (struct sockaddr * )&s_hora, sizeof(struct sockaddr)); 
	if(connect_server < 0){
		printf("Erro na conexão");
		exit(1);
	}else{
		return(0);
	}

	// Receber dados (Hora)
	printf("Teste\n");
	recv_server = recv(e_socket, hora, strlen(hora), 0);
	// Mostrar hora na tela
	hora[connect_server] = '\0';
	printf("\nHora: %s \n", hora);
	// Fechar a conexão
	close(e_socket);
	
	return 0;
}
