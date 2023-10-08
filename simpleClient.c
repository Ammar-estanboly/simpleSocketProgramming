#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {

  int client_fd = socket(AF_INET6, SOCK_STREAM, 0);
  if (client_fd < 0) {
    perror("socket failed");
    exit(1);
  }
  struct sockaddr_in server;
  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(1234);
  server.sin_addr = inet_addr("127.0.0.1");
  int ret = Connect(client_fd, (struct sockaddr *)&server, sizeof(server));
  if (ret < 0) {
    perror("connect failed");
    exit(2);
  }
  char buffer[1024];
  strcpy("hello", buffer);
  ret = write(client_fd, buffer, strlen(buffer));
  if (ret < 0) {
    perror("write failed");
    exit(3);
  }
  ret = read(client_fd, buffer, sizeof(buffer));
  if (ret < 0) {
    perror("read failed");
    exit(4);
  }
  buffer[ret] = 0
  printf("read: %s\n", buffer);
  close(client);
  return 0;
}
