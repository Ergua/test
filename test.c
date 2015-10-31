#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

void doeventopen_test(void);
void doeventclose_test(void);
void doeventwait_test(void);
void doeventsig_test(void);
void doeventinfo_test(void);
void doeventchown_test(void);
void doeventchmod_test(void);
void doeventstat_test(void);

void main()
{
	int num;
	while(1){
		printf("\n1:Create events 2:Close event 3:Test wait  \n");
		printf("Enter an option(1~8)(0 to exit): ");
		scanf("%d",&num);
		switch(num){
			case 1:
			       doeventopen_test(); break;
		    case 2:
			       doeventclose_test(); break;
		    case 3:
			       doeventwait_test(); break;
		    case 4:
			       doeventsig_test(); break;
		    case 5:
			       doeventinfo_test(); break;
		    case 6:
			       doeventchown_test(); break;	
		    case 7:
			       doeventchmod_test(); break;
		    case 8:
			       doeventstat_test(); break;				  				   			   
		    case 0:
			default:
			       exit(0);
		}
		
	}
}


void doeventopen_test()
{
	int num,i,id;
	printf("Enter the number of events to create:");
	scanf("%d",&num);
	for(i=0; i<num; i++){
		id =syscall(181, NULL);
		printf("ID of event %d: %d\n",i+1,id);
	}
}

void doeventclose_test(){
	int eventID, a;
	printf("Event ID to close:");
	scanf("%d",&eventID);
	a = syscall(182, eventID);
	if(a == -1){
		printf("Failed to close Event %d",eventID);
	}else{
		printf("Event %d closed",eventID); ///
	}
	
}
void doeventwait_test(){
	int eventID,a;
	printf("Event ID to wait:\n");
	scanf("%d",&eventID);
	if(fork() == 0){
		a = syscall(182, eventID);
		if(a == 1){
			printf(" Succeed in waiting event %d",eventID)
		}else{
			printf("Failed to wait Event %d",eventID);
		}
		printf("Child exits");
		exit(0);
	}else{
		printf("Parent continues");
	}
	
	
}

//lalallalalalalalaalalalalalalalala
