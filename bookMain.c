//#include<stdio.h>
//#include<stdlib.h>
#include"book.h"
int main()							// main method
{
	int size,c=0;
	char name[10];
	printf("\n\t\t\t\t LIBRARY MANAGEMENT PROJECT\n");
	printf("\t----------------------------------********------------------------------------\n\n");
/*	
	printf(" \t\t\t       .--.            .---.\n");	//Copied from GitHub
	printf(" \t\t\t   .---|__|    .-.     |~~~|\n");
	printf(" \t\t\t.--|===|--|    |_|     |~~~|--.\n");
	printf(" \t\t\t||||===|  |.---!~|  .--|   |--|\n");
	printf(" \t\t\t||||   |  ||===| |--|  |   |  |\n");
	printf(" \t\t\t| ||   |  ||   | |__|  |   |  |\n");
	printf(" \t\t\t| ||   |  ||===| |==|  |   |  |\n");
	printf(" \t\t\t|  |   |__||   |_|__|  |~~~|__|\n");
	printf(" \t\t\t|--|===|--||===|~|--|  |~~~|--|\n");
	printf(" \t\t\t`--^---'--'`---^-^--^--^---'--'\n\n\n");
	*/
		
	printf(" \t\t\t       .--.                 .---.\n");	//Copied from GitHub
	printf(" \t\t\t   .---|__|         .-.     |~~~|\n");
	printf(" \t\t\t.--|===|--|         |_|     |~~~|--.\n");
	printf(" \t\t\t||||===|  |     .---!~|  .--|   |--|\n");
	printf(" \t\t\t||||   |  |     |===| |--|  |   |  |\n");
	printf(" \t\t\t| ||   |  |     |   | |__|  |   |  |\n");
	printf(" \t\t\t| ||   |  |     |===| |==|  |   |  |\n");
	printf(" \t\t\t|  |   |__|     |   |_|__|  |~~~|__|\n");
	printf(" \t\t\t|--|===|--|     |===|~|--|  |~~~|--|\n");
	printf(" \t\t\t`--^---'--'     `---^-^--^--^---'--'\n\n\n");
	
	
	printf("\n\tEnter Librarian Name: ");
	scanf("%s",&name);						//user name
	
		printf("\n\t\t********>>> HELLO, %s ! WELCOME TO E-LIBRARY <<<********\n\n",name);
	
	printf("How many books you want to store : ");
	scanf("%d",&size);						//getting size from user
	
	struct library* lib;		// total 57 bytes memory will be allocated for every structure variable
	
	lib=(struct library*)malloc(size*sizeof(struct library));	//dynamic memory allocation
	
	do
	{
	printf("\nMenu:\n1)Store Records\t\t2)Display Records\n3)Update Record\t\t4)Search Record\n");
	printf("5)Sort Record\t\t6)Delete Record\n7)Insert Record\t\t8) Exit [:->>\n\nEnter Choice: ");
	scanf("%d",&c);
	if(c==1)
		storedata(lib,size);
	else if(c==2)	
		displaydata(lib,&size);
	else if(c==3)	
		updatebook(lib,size);
	else if(c==4)
		searchbook(lib,size);
	else if(c==5)
		sortbook(lib,size);
	else if(c==6)
		deletebook(lib,&size);
	else if(c==7)
		insertbook(lib,&size);
	else
	{
		end();
		printf(" %s\n",name);	
	}
	}while(c!=8);
	return 0;
}
