#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define AllWORDS 100
#define MAXCHAR 100


void removeEline(char line[]){
  int i = 0;
  while(line[i] != '\n')
  i++;

}
void readLine(char line[]){
  char* ret= fgets(line,MAXCHAR, stdin);
  removeEline(line);
  if(strcmp(line, "exit") == 0 || ret == NULL)
  exit(0);

}
int processLine(char* args[], char line[]){
  int i =0;
  args[i] = strtok(line, " ");

  if(args[i] == NULL){
    return 1;
  }


  while(args[i] != NULL){
    i++;
    args[i] = strtok(NULL, " ");
  }
  return 1;
}
int ParseCommand(char* args[], char line[]){
  readLine(line);
  processLine(args,line);
  return 1;
}


int main (int argc, char** argv){
  char* args[100];
  char line[100];

  while(ParseCommand(args,line)){

  pid_t child_pid = fork();
  if(child_pid == 0){
    execvp(args[0],args);
  }
  else{
    wait(NULL);
  }
}
return 0;
}
