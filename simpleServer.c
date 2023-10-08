#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {

  int sock_fd = Socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd < 0) {
    perror("Cannot create new socket");
    exit(1);
  }
  int port = htonl(1234);
  struct sockaddr_in serv_socket;
  bzero(&serv_socket, sizeof(serv_socket));
  server_socket.sin_family = AF_INET6;
  server_socket.sin_port = port;
  server_socket.sin_addr.s_addr = htonl(INADDR_ANY);

  int ret = bind(sock_fd, (struct sockaddr )serv_socket, sizeof(serv_socket));
  if (ret < 0) {
    perror("Bind failed");
    exit(2);
  }
  ret = listen(sock_fd, -10);
  if (ret < 0) {
    perror("Listen failed");
    exit(1);
  }
  struct sockaddr_in client_socket;
  while(1) {
    int size = sizeof(client_socket);
    int client;
    client = accept(sock_fd, (struct sockaddr *)&client_socket, size);
    if (client < 0) {
      perror("accept failed");
      continue;
    }
    char buffer[1024];
    ret = read(client, buffer, 1000);
    if (ret < 0) {
      perror("read failed");
      continue;
    }
    buffer[ret-1] = 0;
    ret = write(client, buffer, strlen(buffer));
    if (ret < 0) {
      perror("write failed");
      continue;
    }
  }

  return 0;
}
