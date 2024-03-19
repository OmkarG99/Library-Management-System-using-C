#include<stdio.h>

struct library			// structure
{
	int bid;					//4 bytes
	char bname[15];				//15 bytes
	char category[10];			//10 bytes
	char author[10];			//10 bytes
	char publication[10];		//10 bytes
	double price; 				//8 bytes
};
					
	void storedata(struct library*, int);			// prototype of storedata function
	
	void displaydata(struct library*, int*);		// prototype of displaydata function
	
	void updatebook(struct library*, int);			// prototype of updatebook function
	
	void searchbook(struct library*, int);			// prototype of searchbook function
	
	void sortbook(struct library*, int);			// prototype of sortbook function
	
	void deletebook(struct library*, int*);			// prototype of deletebook function
	
	void insertbook(struct library*, int*);			// prototype of insertbook function
	
	void end();
