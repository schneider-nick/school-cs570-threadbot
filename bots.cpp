/*
*Name: Nick Scneider, Brian Dobransky
*Username: cssc1093, cssc1094
*Class: CS570, Summer 2017
*Assignment: Assignment #1, bots
*Due: 6-5-2017
*Instructor: Prof. Leonard
*File: bots
*/
extern "C"{
#include <unistd.h>//need for getpid
#include <semaphore.h>// need for semaphore
#include <stdlib.h>//need for exit
#include <pthread.h>//need to use pthread calls
#include "bots.h"
}
#include <iostream>//need to use cin and cout
#include <fstream>//need for fstream
#include <vector>//need for vector
#include <string>//need for string
#include <ctime>//need for time

using namespace std;

#define threadnum 7

string even = "controlling complexity is the essence of computer programming.";
string odd = "computer science is no more about computers then astronomy is about telescopes.";
sem_t FLAG;

void print_file(string quote,void *id){
	fstream file("quote.txt",ios::out|ios::app);
	if(!file.is_open())
		perror("file didnt open");
	file<<"thread<"<<id<<">"<<quote<<"\n";
	file.close();
	cout<<"thread<"<<id<<">"<<endl;
	}

void print_pid(){
	fstream file("quote.txt", ios::out|ios::app);
	if(!file.is_open())
		perror("file did not open");
	file<<"Process PID = "<<getpid() <<endl;
	file.close();
	}

void *even_thread(void *id){
	int check = 0;
	while(check < threadnum){
		sleep(2);
		sem_wait(&FLAG);
		print_file(even,id);
		sem_post(&FLAG);
		check++;
		}
	pthread_exit(NULL);
	}

void *odd_thread(void *id){
	int check = 0;
	while(check < threadnum){
		sleep(3);
		sem_wait(&FLAG);
		print_file(odd,id);
		sem_post(&FLAG);
		check++;
		}
	pthread_exit(NULL);
	}

void run_thread(){
	int i, status;
	vector<pthread_t> threads(threadnum+1);
	for(i = 1; i <= threadnum; i++){
		if(i%2 == 0){
			status = pthread_create(&threads[i],NULL,even_thread,(void *)i);
			if(status != 0)
				perror("thread failed to create");
		}else{
			status = pthread_create(&threads[i],NULL,odd_thread,(void *)i);
			if(status !=0)
				perror("thread failed to create");
			}
	}
	for(i = 1; i <= threadnum; i++){
		pthread_join(threads[i],NULL);
		}
	}

void bots::run(){
	int status;
	if(sem_init(&FLAG,0,1) != 0)
		perror("sem init failed.");
	print_pid();
	run_thread();
	status = sem_destroy(&FLAG);
	if(status != 0)
		perror("semaphore wasnt destoryed");
	return ;
}
bots::bots(){
//construtor
}


