#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define TAILLE_MESSAGE 256 

	pid_t create_process(void)
	{
	    pid_t pid;

	    /* On fork() tant que l'erreur est EAGAIN */
	    do {
		pid = fork();
	    } while ((pid == -1) && (errno == EAGAIN));

	    return pid;
	}

	/* La fonction child_process effectue les actions du processus fils */
	void info_child_process(void)
	{
	    printf(" Nous sommes dans le fils !\n"
		   " Le PID du fils est %d.\n"
		   " Le PPID du fils est %d.\n", (int) getpid(), (int) getppid());
	}

	/* La fonction father_process effectue les actions du processus père */
	void info_father_process(int child_pid)
	{
	    printf(" Nous sommes dans le père !\n"
		   " Le PID du fils est %d.\n"
		   " Le PID du père est %d.\n", (int) child_pid, (int) getpid());
	}


	void proc_largeur(int n){
	
	pid_t pid;


	printf("pid du pere : %d\n\n",getpid());
	for (int i=0; i<n; i++)
	 {
		if (pid!=0) 
			pid = create_process();	
	 }
	 
	 if (pid==0){
	 	info_child_process();
		sleep(2);}
	
	while(wait(0) != -1);//attend que TOUS les fils soient morts
	
	}

	void proc_hauteur(int n, char msg[255]){

	int descripteurTube[2];
    	char messageLire[255], messageEcrire[255];
   
    	if(pipe(descripteurTube) != 0)
    	{
     	   fprintf(stderr, "Erreur de création du tube.\n");
    	}

	pid_t pid;


	if ( n != 0 ) {
		pid = create_process();
		if (pid == 0) {
			
			close(descripteurTube[1]);
			read(descripteurTube[0], messageLire, 255);
			printf("Nous sommes dans le fils (pid = %d).\nIl a reçu le message suivant du père (pid = %d): \"%s\".\n\n\n", getpid(), getppid(), messageLire);
	
			proc_hauteur(n-1, msg);
    		}else{

			close(descripteurTube[0]);
			sprintf(messageEcrire, msg);
			printf("Nous sommes dans le père (pid = %d).\nIl envoie le message suivant au fils : \"%s\".\n\n\n", getpid(), messageEcrire);

			write(descripteurTube[1], messageEcrire, TAILLE_MESSAGE);

			while(wait(0) != -1);}
		}
	}


	
	

	void proc_abr(int n){
		pid_t fgPid;
		pid_t fdPid;

		if ( n != 0 ) {
			fgPid = create_process();
			if (fgPid != 0) fdPid = create_process();
			proc_abr(n-1);			
		}	
		while(wait(0) != -1);
	}

int main(){
	char msg[255];
	sprintf(msg,"Salut mon fils");
	proc_hauteur(4,msg);
	return 0;
}
