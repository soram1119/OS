#include <stdio.h>
#include <stdlib.h>
#include <string.h> //문자열 관련 함수가 모아져있는 헤더 파일
#include <unistd.h>
#include <pthread.h>

char message[]="Hello World";

void *thread_function(void *arg){
  //이 함수는 쓰레드의 identifier를 출력하고 나간다.
  printf("thread_function is running. Argument was %s\n",(char *)arg);
  sleep(3); //3초간 절전모드
  strcpy(message,"Bye!");
  /* strcpy 함수는 char형 배열에 새로운 문자열을 저장하는 함수
    문자열의 길이를 별도로 입력할 필요없이 자동으로 계산한다.
    마지막에 널문자까지 자동으로 넣어준다.
    사용법 : strcpy(사용할배열명,저장할문자열);
    */
  pthread_exit((void*)"Thank you for the CPU time");
  
}
void main(int argc,char *argv[]) {
    //The main program creates 10 threads and then exits
  int res;
  pthread_t a_thread;//??
  void *tread_result;
  res=pthread_create(&a_thread,NULL,thread_function,(void*)message);
  printf("Wating for thread to finish ...\n");
  res=pthread_join(a_thread,&thread_result);
  printf("Thread joined, it returned %s\n",(char*)thread_result);
  printf("Message is now %s\n",message);
  
  exit(0);
}
