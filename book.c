#include<stdlib.h>
#include<string.h>
#include"book.h"
	int i;		//global
///////////////////////////////////////////////
void storedata(struct library* lib,int size)		// Book Storing function
{
	printf("\n\tYou can store the record of %d Books only...\n");
	for(i=0;i<size;i++)
	{
		printf("Enter Book ID: ");
		scanf("%d",&lib[i].bid);
	//	fflush(stdin);
		printf("Enter Book Name: ");
		gets(lib[i].bname);
		printf("Book Category: ");
		gets(lib[i].category);
		printf("Author Name: ");
		gets(lib[i].author);
		printf("Publication Name: ");
		gets(lib[i].publication);
		printf("Enter Book Price: ");
		scanf("%lf",&lib[i].price);
	}
	printf("\nTotal %d records stored...\n",size);	// size var. will print count of stored record
}
void displaydata(struct library* lib,int* size)		// Book Showing function
{
	printf("\n\n\t\t\t All Records with Details:\n\n");
	printf("---------------------------------------------------------------------------------------\n");
	printf("B_ID\tBook_Name\t\tCategory\tAuthor\t\tPublication\tPrice\n");
	printf("---------------------------------------------------------------------------------------\n");
	for(i=0;i<*size;i++)
	{
		printf("%-7d %-23s %-15s %-15s %-15s %.2lf\n",lib[i].bid,lib[i].bname,lib[i].category,lib[i].author,lib[i].publication,lib[i].price);
	}
	printf("---------------------------------------------------------------------------------------\n");
}	
void updatebook(struct library* lib, int size)		// Book Updating function
{
	int no=0,c=0;		//no(for ID), c(for counter)
	printf("\nEnter ID to update Record: ");
	scanf("%d",&no);
	for(i=0;i<size;i++)
	{
		if(lib[i].bid==no)
		{
			printf("What you want to change exactly: \n");
			printf("1) B.Name\n2) Category\n3) Author\n4) Publication\n5) Price\n6) All Record\n");
			int choice=0;
			scanf("%d",&choice);
		
			switch(choice)
			{
				case 1:
					{
					//	fflush(stdin);
						printf("\nEnter Book Name: ");
						gets(lib[i].bname);
						c++;
					}
					break;
				case 2:
					{
					//	fflush(stdin);
						printf("Book Category: ");
						gets(lib[i].category);
						c++;
					}
					break;
				case 3:
					{
					//	fflush(stdin);
						printf("Author Name: ");
						gets(lib[i].author);
						c++;
					}
					break;
				case 4:
					{
					//	fflush(stdin);
						printf("Publication Name: ");
						gets(lib[i].publication);
						c++;
					}
					break;
				case 5:
					{
					//	fflush(stdin);
						printf("Enter Book Price: ");
						scanf("%lf",&lib[i].price);
						c++;	
					}
					break;	
				case 6:
					{
					//	fflush(stdin);
						printf("\nEnter Book Name: ");
						gets(lib[i].bname);
						printf("Book Category: ");
						gets(lib[i].category);
						printf("Author Name: ");
						gets(lib[i].author);
						printf("Publication Name: ");
						gets(lib[i].publication);
						printf("Enter Book Price: ");
						scanf("%lf",&lib[i].price);	
						c++;
					}	
					break;	
				default:
					printf("Enter correct choice: ");
					break;		
			}
		}
	}
	if(c==0)
		printf("\n\t\t\t--- Please Enter Correct ID ---\n");
}
void searchbook(struct library* lib, int size)		// Book Searching function
{
	int a=0,no=0,c=1;	//a(for choice), no(for ID), n(for string) nd c(counter variable)
	char n[20];
	printf("What do you have ?\n 1) ID or 2)Autor Name (press 1 or 2): ");
	scanf("%d",&a);		// getting choice from user
	if(a==1)
	{
		printf("\nEnter ID: ");
		scanf("%d",&no);
	}
	if(a==2)
	{
		printf("\nEnter Author Name: ");
	//	fflush(stdin);
		gets(n);
	}
	for(i=0;i<size;i++)
	{
		if((lib[i].bid==no) || (strcmp(lib[i].author,n))==0)//comparing both using || operator
		{
			printf("---------------------------------------------------------------------------------------\n");
			printf("\nB_ID\tBook_Name\t\tCategory\tAuthor\t\tPublication\tPrice\n\n");
			printf("%-7d %-23s %-15s %-15s %-15s %.2lf\n",lib[i].bid,lib[i].bname,lib[i].category,lib[i].author,lib[i].publication,lib[i].price);
			printf("---------------------------------------------------------------------------------------\n");
			c=0;
		}
	}
	if(c)
		printf("\n\t\t\tSorry... Record Not Found\n");
}
void sortbook(struct library* lib, int size) 		// Book Sorting function
{
	struct library temp;		//structure variable	
	int choice,j;		// j(for 2nd loop)
	printf("Enter choice for sorting: \n\t1) Ascending 2) Descending:(By using ID)--> ");
	scanf("%d",&choice);
	if(choice==1)			// Sorting in Ascending order
	{
		for(i=0;i<size;i++)
		{
			for(j=i+1;j<size;j++)
			{
				if(lib[i].bid>lib[j].bid)
				{
					temp=lib[i];
					lib[i]=lib[j];
					lib[j]=temp;
				}
			}
		}
		printf("\n\tSorted Successfully(Done By ID)\n");
	}
	else if(choice==2)		// Sorting in Descending order
	{
		for(i=0;i<size;i++)
		{
			for(j=i+1;j<size;j++)
			{
				if(lib[i].bid<lib[j].bid)
				{
					temp=lib[i];
					lib[i]=lib[j];
					lib[j]=temp;
				}
			}
		}
		printf("\n\tSorted Successfully(Done By ID)\n");
	}
}
void deletebook(struct library* lib, int* size)		//Record Deleting function
{
	int in,j,flag=0;	//in(usr input(ID))
	printf("Enter ID to delete record: ");
	scanf("%d",&in);
	for(i=0;i<*size;i++)
	{
		if(lib[i].bid==in)
		{
			flag=1;
			for(j=i;j<*size-1;j++)
			{
				lib[j]=lib[j+1];
			}
		}
	}
	if(flag==1)
	{
		*size=*size-1;		// actual size will be decreased by 1
		printf("\n\n\tRecord deleted successfully\n");
	}
	else
		printf("\n\t\t\tRecord not found...\n");
	
}
void insertbook(struct library* lib,int* size)		// Book Inserting function
{
	for(i=*size;i<(*size+1);i++)
	{
		printf("Enter Book ID: ");
		scanf("%d",&lib[i].bid);
	//	fflush(stdin);
		printf("Enter Book Name: ");
		gets(lib[i].bname);
		printf("Book Category: ");
		//fflush(stdin);
		gets(lib[i].category);
		printf("Author Name: ");
		gets(lib[i].author);
		printf("Publication Name: ");
		gets(lib[i].publication);
		printf("Enter Book Price: ");
		scanf("%lf",&lib[i].price);
	}
	*size=*size+1;
		printf("\n\t1 Book inserted successfully...\n");
}														
////////////////////////////////////////////////////////////
// 	void end()
// {
// 	int s=10;
// 	char c[s];
// 	strcpy(c,"Thank You");
// 	printf("\n\t\t\t");
// 	for(i=0;i<s-1;i++)
// 	{
// 		printf("%c",c[i]);
// 		sleep(1);		//After one second execution will go again to for loop
// 	}
// }
	
