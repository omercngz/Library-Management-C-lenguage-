#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_FILE_NAME 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
	char ISBN[50];
	char name[50];
	char language[50];
	char firstAuthor[50];
	char secondAuthor[50];
	char publisherCompany[50];
	char yearPublication[50];
	char scientificArea[50];
	char price[10];
	
}Node;
typedef struct Book{
	Node date;
	struct Book*next;
}book;
int findLine(){
 	FILE *fp2;
    int count = 0; 
    char filename[MAX_FILE_NAME];
    char c;      
    if ((fp2 = fopen("program.txt", "r")) == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }
    for (c = getc(fp2); c != EOF; c = getc(fp2))
        if (c == '\n') 
            count = count + 1;
    fclose(fp2);
    printf("The file %s has %d lines\n ", filename, count);
  
    return count;
  
}
book*getData(){
		FILE *fp2;
		book*h, *tail, *p;
		h=tail=(book*)malloc(sizeof(book));
		h->next = NULL;
		int n = findLine();
	    if ( (fp2 = fopen("program.txt","r"))==NULL) {
	        printf("The file could not be opened!!!");
	        exit(1);
	    }
		for (int i = 0; i < n; i++)
		{
			p = (book*)malloc(sizeof(book));
		    char line_data[1024];
		    fgets(line_data, 1024, fp2);
		    char* token = strtok(line_data, ";");
		    char* token1 = strtok(NULL, ";");
		    char* token2 = strtok(NULL, ";");
		    char* token3 = strtok(NULL, ";");
		    char* token4 = strtok(NULL, ";");
		    char* token5 = strtok(NULL, ";");
		    char* token6 = strtok(NULL, ";");
		    char* token7 = strtok(NULL, ";");
		    char* token8 = strtok(NULL, ";");
		    strcpy(&p->date.ISBN, token);
			strcpy(&p->date.name, token1);
			strcpy(&p->date.language, token2);
			strcpy(&p->date.firstAuthor, token3);
			strcpy(&p->date.secondAuthor, token4);
			strcpy(&p->date.publisherCompany, token5);
			strcpy(&p->date.yearPublication, token6);
			strcpy(&p->date.scientificArea, token7);
			strcpy(&p->date.price, token8);
			p->next = NULL;
			tail->next = p; 
			tail = p;
	}
		printf("\n*********************Book information moved from file to list**********************\n");
		fclose(fp2);
	return h;
}
book*newFile(){
	book*h, *tail, *p;
	h=tail=(book*)malloc(sizeof(book));
	h->next = NULL;int n = 0;
	unsigned int count=1;
	printf("Enter the number of books to be entered:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		p = (book*)malloc(sizeof(book));
		printf("\n\t\t\tBook Count = %d\n\n",count);
		printf("Book ISBN = ");
		fgets(&p->date.ISBN, 256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.ISBN);
        printf("Book name =  ");
		fgets(&p->date.name, 256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.name);
        printf("Book language = ");
        fgets(&p->date.language,256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.language);
        printf("Book first author name = ");
		fgets(&p->date.firstAuthor,256, stdin);		
		scanf("%10[0-9a-zA-Z ]",&p->date.firstAuthor);
		printf("Book second author name = ");
    	fgets(&p->date.secondAuthor, 256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.secondAuthor);
		printf("Book pulisher company = ");
    	fgets(&p->date.publisherCompany,256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.publisherCompany);
		printf("Book year of publication ");
		fgets(&p->date.yearPublication, 256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.yearPublication);
		printf("Book scientific area = ");
    	fgets(&p->date.scientificArea, 256, stdin);
    	scanf("%10[0-9a-zA-Z ]",&p->date.scientificArea);
		printf("Book price (EURO) = ");
		fgets(&p->date.price, 256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.price);
		count++;
		p->next = NULL;
		tail->next = p; 
		tail = p;	}
	return h;
}
void insertBook(book*h) 
{		

	book*p;
		p = (book*)malloc(sizeof(book));
		printf("******************************INSERT****************************\n");
		printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
		fgets(&p->date.ISBN, 256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.ISBN);
        printf("\t\t\tBook name = %s\n",p->date.name);
		fgets(&p->date.name, 256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.name);
        printf("\t\t\tBook language = %s\n",p->date.language);
        fgets(&p->date.language,256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.language);
        printf("\t\t\tBook first author name = %s\n",p->date.firstAuthor);
		fgets(&p->date.firstAuthor,256, stdin);		
		scanf("%10[0-9a-zA-Z ]",&p->date.firstAuthor);
		printf("\t\t\tBook second author name = %s\n",p->date.secondAuthor);
    	fgets(&p->date.secondAuthor, 256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.secondAuthor);
		printf("\t\t\tBook pulisher company = %s\n",p->date.publisherCompany);
    	fgets(&p->date.publisherCompany,256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.publisherCompany);
		printf("\t\t\tBook year of publication = %s\n",p->date.yearPublication);
		fgets(&p->date.yearPublication, 256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.yearPublication);
		printf("\t\t\tBook scientific area = %s\n",p->date.scientificArea);
    	fgets(&p->date.scientificArea, 256, stdin);
    	scanf("%10[0-9a-zA-Z ]",&p->date.scientificArea);
		printf("\t\t\tBook price (EURO) = %s\n\n",p->date.price);
		fgets(&p->date.price, 256, stdin);
		scanf("%10[0-9a-zA-Z ]",&p->date.price);
	
		p->next = h->next;
		h->next = p;
	
}
void search1(book*h)// Book title search
{
	char name[50];
	int control=0;
	unsigned int count=1;
	book*p = h->next;
	printf("Enter the title you want to find:");
	scanf("%s",&name);
	while (p!=NULL)
	{
		if (strcmp(p->date.name,name)==0)
		{
			printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
	        printf("\t\t\tBook name = %s\n",p->date.name);
	        printf("\t\t\tBook language = %s\n",p->date.language);
	        printf("\t\t\tBook first author name = %s\n",p->date.firstAuthor);
			printf("\t\t\tBook second author name = %s\n",p->date.secondAuthor);
			printf("\t\t\tBook pulisher company = %s\n",p->date.publisherCompany);
			printf("\t\t\tBook year of publication = %s\n",p->date.yearPublication);
			printf("\t\t\tBook scientific area = %s\n",p->date.scientificArea);
			printf("\t\t\tBook price (EURO)= %s\n\n",p->date.price);
			count++;control++;
			
		}
		p = p->next;
		
	}
	
	if (p == NULL&&control==0)
	{
		printf("Not found! \n");
	}
}
void updateBook(book*h)
{
	char ISBN[20];
	book*p = h->next;
	printf("For update, Enter the ISBN to find:");
	scanf("%s", &ISBN);
	while (p != NULL)
	{
		if (strcmp(p->date.ISBN, ISBN)!=0)
		{
			p = p->next;
		}
		else
		{
			
	        printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
	        printf("\t\t\tBook name = %s\n",p->date.name);
	        printf("\t\t\tBook language = %s\n",p->date.language);
	        printf("\t\t\tBook first author name = %s\n",p->date.firstAuthor);
			printf("\t\t\tBook second author name = %s\n",p->date.secondAuthor);
			printf("\t\t\tBook pulisher company = %s\n",p->date.publisherCompany);
			printf("\t\t\tBook year of publication = %s\n",p->date.yearPublication);
			printf("\t\t\tBook scientific area = %s\n",p->date.scientificArea);
			printf("\t\t\tBook price (EURO) = %s\n\n",p->date.price);
			printf("******************************updateBook****************************\n");
			printf("\t\t\t(UPDATE)Book ISBN = %s\n",p->date.ISBN);
			fgets(&p->date.ISBN, 256, stdin);
			scanf("%10[0-9a-zA-Z ]",&p->date.ISBN);
	        printf("\t\t\t(UPDATE)Book name = %s\n",p->date.name);
			fgets(&p->date.name, 256, stdin);
			scanf("%10[0-9a-zA-Z ]",&p->date.name);
	        printf("\t\t\t(updateBook)Book language = %s\n",p->date.language);
	        fgets(&p->date.language,256, stdin);
			scanf("%10[0-9a-zA-Z ]",&p->date.language);
	        printf("\t\t\t(UPDATE)Book first author name = %s\n",p->date.firstAuthor);
			fgets(&p->date.firstAuthor,256, stdin);		
			scanf("%10[0-9a-zA-Z ]",&p->date.firstAuthor);
			printf("\t\t\t(UPDATE)Book second author name = %s\n",p->date.secondAuthor);
	    	fgets(&p->date.secondAuthor, 256, stdin);
			scanf("%10[0-9a-zA-Z ]",&p->date.secondAuthor);
			printf("\t\t\t(UPDATE)Book pulisher company = %s\n",p->date.publisherCompany);
	    	fgets(&p->date.publisherCompany,256, stdin);
			scanf("%10[0-9a-zA-Z ]",&p->date.publisherCompany);
			printf("\t\t\t(UPDATE)Book year of publication = %s\n",p->date.yearPublication);
			fgets(&p->date.yearPublication, 256, stdin);
			scanf("%10[0-9a-zA-Z ]",&p->date.yearPublication);
			printf("\t\t\t(UPDATE)Book scientific area = %s\n",p->date.scientificArea);
	    	fgets(&p->date.scientificArea, 256, stdin);
	    	scanf("%10[0-9a-zA-Z ]",&p->date.scientificArea);
			printf("\t\t\t(UPDATE)Book price (EURO) = %s\n\n",p->date.price);
			fgets(&p->date.price, 256, stdin);
			scanf("%10[0-9a-zA-Z ]",&p->date.price);
				return;
		}
	}
	if (p == NULL)
	{
		printf("Not found! \n");
	}
}
void search2(book*h)// ISBN search
{
	char ISBN[50];
	int control =0;
	unsigned int count=1;
	book*p = h->next;
	printf("Enter the ISBN to find:");
	fgets(&ISBN,256, stdin);		
	scanf("%10[0-9a-zA-Z ]",&ISBN);
	while (p != NULL)
	{
		if (strcmp(p->date.ISBN, ISBN)==0)
		{
			printf("\n\t\t\tBook Count = %d\n\n",count);
	        printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
	        printf("\t\t\tBook name = %s\n",p->date.name);
	        printf("\t\t\tBook language = %s\n",p->date.language);
	        printf("\t\t\tBook first author name = %s\n",p->date.firstAuthor);
			printf("\t\t\tBook second author name = %s\n",p->date.secondAuthor);
			printf("\t\t\tBook pulisher company = %s\n",p->date.publisherCompany);
			printf("\t\t\tBook year of publication = %s\n",p->date.yearPublication);
			printf("\t\t\tBook scientific area = %s\n",p->date.scientificArea);
			printf("\t\t\tBook price (EURO) = %s\n\n",p->date.price);count++;control++;
			
		}
		p = p->next;
		
	}
	if (p == NULL&&control==0)
	{
		printf("Not found! \n");
	}
}
void languageOfAllBook(book*h)
{
	char language[50];
	int control =0;
	unsigned int count=1;
	book*p = h->next;
	printf("Enter the language to find:");
	fgets(&language,256, stdin);		
	scanf("%10[0-9a-zA-Z ]",&language);
	while (p != NULL)
	{
		if (strcmp(p->date.language, language)==0)
		{
			printf("\n\t\t\tBook Count = %d\n\n",count);
	        printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
	        printf("\t\t\tBook name = %s\n",p->date.name);
	        printf("\t\t\tBook language = %s\n",p->date.language);
	        printf("\t\t\tBook first author name = %s\n",p->date.firstAuthor);
			printf("\t\t\tBook second author name = %s\n",p->date.secondAuthor);
			printf("\t\t\tBook pulisher company = %s\n",p->date.publisherCompany);
			printf("\t\t\tBook year of publication = %s\n",p->date.yearPublication);
			printf("\t\t\tBook scientific area = %s\n",p->date.scientificArea);
			printf("\t\t\tBook price (EURO) = %s\n\n",p->date.price);
			count++;control++;	
		}
			p = p->next;
		
	}
	if (p == NULL&&control==0)
	{
		printf("Not found! \n");
	}
} 
void scientificAreaAndFirstAuthorOfAllBook(book*h)
{
	char scientificArea[50];
	char firstAuthor[50];
	int control =0;
	unsigned int count=1;
	book*p = h->next;
	printf("Enter the scientific area to find:");
	fgets(&scientificArea,256, stdin);		
	scanf("%10[0-9a-zA-Z ]",&scientificArea);
	printf("Enter the first author name to find:");
	scanf("%s", &firstAuthor);
	while (p != NULL)
	{
		if (strcmp(p->date.scientificArea, scientificArea)==0  && strcmp(p->date.firstAuthor, firstAuthor)==0 )  
		{
			printf("\n\t\t\tBook Count = %d\n\n",count);
	        printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
	        printf("\t\t\tBook name = %s\n",p->date.name);
	        printf("\t\t\tBook language = %s\n",p->date.language);
	        printf("\t\t\tBook first author name = %s\n",p->date.firstAuthor);
			printf("\t\t\tBook second author name = %s\n",p->date.secondAuthor);
			printf("\t\t\tBook pulisher company = %s\n",p->date.publisherCompany);
			printf("\t\t\tBook year of publication = %s\n",p->date.yearPublication);
			printf("\t\t\tBook scientific area = %s\n",p->date.scientificArea);
			printf("\t\t\tBook price (EURO) = %s\n\n",p->date.price);
			count++;
			control++;
		}
			p = p->next;
	}
	if (p == NULL&&control==0)
	{
		printf("Not found! \n");
	}
}
void firstAndSecondAuthorOfLastBook(book*h)
{
	char firstAuthor[50];
	char secondAuthor[50];
	unsigned int count=1;
	book*p = h->next;
	printf("Enter the first author to find:");
	fgets(&firstAuthor,256, stdin);		
	scanf("%10[0-9a-zA-Z ]",&firstAuthor);
	printf("Enter the second author to find:");
	fgets(&secondAuthor,256, stdin);		
	scanf("%10[0-9a-zA-Z ]",&secondAuthor);
	while (p != NULL)
	{
		if (strcmp(p->date.firstAuthor, firstAuthor)!=0 && strcmp(p->date.secondAuthor, secondAuthor)!=0)
		{
			p = p->next;
		}
		else{
			printf("\n\t\t\tBook Count = %d\n\n",count);
	        printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
	        printf("\t\t\tBook name = %s\n",p->date.name);
	        printf("\t\t\tBook language = %s\n",p->date.language);
	        printf("\t\t\tBook first author name = %s\n",p->date.firstAuthor);
			printf("\t\t\tBook second author name = %s\n",p->date.secondAuthor);
			printf("\t\t\tBook pulisher company = %s\n",p->date.publisherCompany);
			printf("\t\t\tBook year of publication = %s\n",p->date.yearPublication);
			printf("\t\t\tBook scientific area = %s\n",p->date.scientificArea);
			printf("\t\t\tBook price (EURO) = %s\n\n",p->date.price);
			count++;
			return;
		}
		
	}
	if (p == NULL )
	{
		printf("Not found! \n");
	}
} 
void scientificAreaOfAllBook(book*h)
{
	char scientificArea[50];
	int control =0;
	unsigned int count=1;
	book*p = h->next;
	printf("Enter the scientific area to find:");
	fgets(&scientificArea,256, stdin);		
	scanf("%10[0-9a-zA-Z ]",&scientificArea);
	while (p != NULL)
	{
		if (strcmp(p->date.scientificArea, scientificArea)==0)
		{
			printf("\n\t\t\tBook Count = %d\n\n",count);
	        printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
	        printf("\t\t\tBook name = %s\n",p->date.name);
	        printf("\t\t\tBook language = %s\n",p->date.language);
	        printf("\t\t\tBook first author name = %s\n",p->date.firstAuthor);
			printf("\t\t\tBook second author name = %s\n",p->date.secondAuthor);
			printf("\t\t\tBook pulisher company = %s\n",p->date.publisherCompany);
			printf("\t\t\tBook year of publication = %s\n",p->date.yearPublication);
			printf("\t\t\tBook scientific area = %s\n",p->date.scientificArea);
			printf("\t\t\tBook price (EURO)= %s\n\n",p->date.price);
			count++;
			control++;
		}
			p = p->next;
	}
	if (p == NULL&&control==0)
	{
		printf("Not found! \n");
	}
} 
void firstAndSecondAuthorOfAllBook(book*h)
{
	char firstAuthor[50];
	char secondAuthor[50];
	int control =0;
	unsigned int count=1;
	book*p = h->next;
	printf("Enter the first author to find:");
	fgets(&firstAuthor,256, stdin);		
	scanf("%10[0-9a-zA-Z ]",&firstAuthor);
	printf("Enter the second author to find:");
	fgets(&secondAuthor,256, stdin);		
	scanf("%10[0-9a-zA-Z ]",&secondAuthor);
	while (p != NULL)
	{
		if (strcmp(p->date.firstAuthor, firstAuthor)==0 && strcmp(p->date.secondAuthor, secondAuthor)==0)
		{
			printf("\n\t\t\tBook Count = %d\n\n",count);
	        printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
	        printf("\t\t\tBook name = %s\n",p->date.name);
	        printf("\t\t\tBook language = %s\n",p->date.language);
	        printf("\t\t\tBook first author name = %s\n",p->date.firstAuthor);
			printf("\t\t\tBook second author name = %s\n",p->date.secondAuthor);
			printf("\t\t\tBook pulisher company = %s\n",p->date.publisherCompany);
			printf("\t\t\tBook year of publication = %s\n",p->date.yearPublication);
			printf("\t\t\tBook scientific area = %s\n",p->date.scientificArea);
			printf("\t\t\tBook price (EURO) = %s\n\n",p->date.price);
			count++;
			control++;
		}
		p = p->next;
	}
	if (p == NULL&&control==0)
	{
		printf("Not found! \n");
	}
} 
 void scientificAreaLatestBook(book*h)
{
	char scientificArea[50];
	int control =0;
	unsigned int count=1;
	book*p = h->next;
	printf("Enter the scientific area to find:");
	fgets(&scientificArea,256, stdin);		
	scanf("%10[0-9a-zA-Z ]",&scientificArea);
	while (p != NULL)
	{
		if (strcmp(p->date.scientificArea, scientificArea)!=0)
		{
			p = p->next;
			
		}
		else{
			printf("\n\t\t\tBook Count = %d\n\n",count);
	        printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
	        printf("\t\t\tBook name = %s\n",p->date.name);
	        printf("\t\t\tBook language = %s\n",p->date.language);
	        printf("\t\t\tBook first author name = %s\n",p->date.firstAuthor);
			printf("\t\t\tBook second author name = %s\n",p->date.secondAuthor);
			printf("\t\t\tBook pulisher company = %s\n",p->date.publisherCompany);
			printf("\t\t\tBook year of publication = %s\n",p->date.yearPublication);
			printf("\t\t\tBook scientific area = %s\n",p->date.scientificArea);
			printf("\t\t\tBook price (EURO)= %s\n\n",p->date.price);
			count++;
			return;
		}
	}
	if (p == NULL)
	{
		printf("Not found! \n");
	}
} 
 void yearOfPublicationOfAllBook(book*h)
{
	char yearPublication[50];
	int control =0;
	unsigned int count=1;
	book*p = h->next;
	printf("Enter the year of publication to find:");
	fgets(&yearPublication,256, stdin);		
	scanf("%10[0-9a-zA-Z ]",&yearPublication);

	while (p != NULL)
	{
		if (strcmp(p->date.yearPublication, yearPublication)==0)
		{
		printf("\n\t\t\tBook Count = %d\n\n",count);
        printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
        printf("\t\t\tBook name = %s\n",p->date.name);
        printf("\t\t\tBook language = %s\n",p->date.language);
        printf("\t\t\tBook first author name = %s\n",p->date.firstAuthor);
		printf("\t\t\tBook second author name = %s\n",p->date.secondAuthor);
		printf("\t\t\tBook pulisher company = %s\n",p->date.publisherCompany);
		printf("\t\t\tBook year of publication = %s\n",p->date.yearPublication);
		printf("\t\t\tBook scientific area = %s\n",p->date.scientificArea);
		printf("\t\t\tBook price (EURO)= %s\n\n",p->date.price);
		count++;
		control++;
		}
		p = p->next;
		
	}
	if (p == NULL&&control==0)
	{
		printf("Not found! \n");
	}
} 
void titleOfPrice(book*h)// price search
{
	char name[50];
	int control =0;
	unsigned int count=1;
	book*p = h->next;
	printf("Enter the title to find:");
	fgets(&name,256, stdin);		
	scanf("%10[0-9a-zA-Z ]",&name);

	while (p != NULL)
	{
		if (strcmp(p->date.name, name)==0)
		{
			printf("\n\t\t\tBook Count = %d\n\n",count);
        	printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
			printf("\t\t\tBook price (EURO) = %s\n\n",p->date.price);
        count++;
		control++;
			
		}
		p = p->next;
		
	}
	if (p == NULL&&control==0)
	{
		printf("Not found! \n");
		return;
	}
} 
void saveFile(book*h)
{
	book*p;
	FILE *fp2;
	unsigned int count=1;

    if ( (fp2=fopen("program.txt","a"))==NULL) {
        printf("Dosya açilamadi");
        exit(1);
    }
	for (p = h->next; p != NULL; p = p->next)
	{	
		printf("\n\t\t\tBook Count = %d\n\n",count);
        printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
        fprintf(fp2,"%s;",p->date.ISBN);
        printf("\t\t\tBook name = %s\n",p->date.name);
		fprintf(fp2,"%s;",p->date.name);
        printf("\t\t\tBook language = %s\n",p->date.language);
        fprintf(fp2,"%s;",p->date.language);
        printf("\t\t\tBook first author name = %s\n",p->date.firstAuthor);
        fprintf(fp2,"%s;",p->date.firstAuthor);
		printf("\t\t\tBook second author name = %s\n",p->date.secondAuthor);
		fprintf(fp2,"%s;",p->date.secondAuthor);
		printf("\t\t\tBook pulisher company = %s\n",p->date.publisherCompany);
		fprintf(fp2,"%s;",p->date.publisherCompany);
		printf("\t\t\tBook year of publication = %s\n",p->date.yearPublication);
		fprintf(fp2,"%s;",p->date.yearPublication);
		printf("\t\t\tBook scientific area = %s\n",p->date.scientificArea);
		fprintf(fp2,"%s;",p->date.scientificArea);
		printf("\t\t\tBook price (EURO)) = %s\n\n",p->date.price);
		fprintf(fp2,"%s;\n",p->date.price);
		count++;
	}
		printf("\n***********************************************DATA HAS BEEN EXPORTED TO THE FILE***********************************************\n");
		fclose(fp2);
}
void printOutput(book*h)// output
{
	book*p;
	FILE *fp2;
	unsigned int count=1;
   	p = h->next;
    if ( (fp2=fopen("program.txt","a"))==NULL) {
        printf("The file is not opened!!!");
        exit(1);
    }
	for (p = h->next; p != NULL; p = p->next)
	{	
		printf("\n\t\t\tBook Count = %d\n\n",count);
        printf("\t\t\tBook ISBN = %s\n",p->date.ISBN);
        printf("\t\t\tBook name = %s\n",p->date.name);
        printf("\t\t\tBook language = %s\n",p->date.language);
        printf("\t\t\tBook first author name = %s\n",p->date.firstAuthor);
		printf("\t\t\tBook second author name = %s\n",p->date.secondAuthor);
		printf("\t\t\tBook pulisher company = %s\n",p->date.publisherCompany);
		printf("\t\t\tBook year of publication = %s\n",p->date.yearPublication);
		printf("\t\t\tBook scientific area = %s\n",p->date.scientificArea);
		printf("\t\t\tBook price (EURO) = %s\n\n",p->date.price);
		count++;
	}
		fclose(fp2);

}
void removeBook(book*h)
{
	char ISBN[50];
	book*p = h->next;
	book*tail = h;
	printf("Enter the ISBN of the book to be delete :");
	fgets(&ISBN,256, stdin);		
	scanf("%10[0-9a-zA-Z ]",&ISBN);

	while (p != NULL)
	{
		if (strcmp(p->date.ISBN, ISBN)!=0)
		{
			p = p->next;
			tail = tail->next;
		}
		else
		{
			tail->next = p->next;
			free(p);
			return;
		}
	}
}
void menu()
{
	printf("--------- Library Management System ------------------------------------- \n");
	printf("--------- OMER CENGIZ 47124 UBI ----------------------------------------- \n");

	printf("************ 1. Enter (New List) **************************************** \n");
	printf("************ 2. INSERT ************************************************** \n");
	printf("************ 3. Query by title ****************************************** \n");
	printf("************ 4. Query by ISBN ******************************************* \n");
	printf("************ 5. Delete ************************************************** \n");
	printf("************ 6. Output ************************************************** \n");
	printf("************ 7. Extract data from file ********************************** \n");
	printf("************ 8. UPDATE ************************************************** \n");
	printf("************ 9. Operations ********************************************** \n");
	printf("************ 10.Save to File ******************************************** \n");
	printf("Note: Only enter once, otherwise it will overwrite \n");
}void menu2()
{
	printf("--------- Library Management System ------------------------------------- \n");
	printf("************* 1. ------------FILTER-------------------------QUERY-------- \n");
	printf("************* 1. Title ----------------------------> Price ************** \n");
	printf("************* 2. Year Of Publication --------------> All Book *********** \n");
	printf("************* 3. Scientific Area ------------------> Recent Book ******** \n");
	printf("************* 4. First And Second Author ----------> All Book *********** \n");
	printf("************* 5. ScientificArea -------------------> AllBook ************ \n");
	printf("************* 6. First And Second Author ----------> Recent Book ******** \n");
	printf("************* 7. Scientific Area And First Author -> All Book *********** \n");
	printf("************* 8. Language -------------------------> All Book *********** \n");
	printf("************* 9. BACK *************************************************** \n");
	printf("Note: Only enter once, otherwise it will overwrite \n");
}

void Operations(book*h)
{
	int i;	int a = 1;
	while (a>0)
	{
		menu2();
		printf("please choose:");
		scanf("%d",&i);
		switch (i)
		{
		case 1:
			titleOfPrice(h);
			break;
		case 2:
			yearOfPublicationOfAllBook(h);
			break;
		case 3:
			scientificAreaLatestBook(h);
			break;
		case 4:
			firstAndSecondAuthorOfAllBook(h);
			break;
		case 5:
			scientificAreaOfAllBook(h);
			break;
		case 6:
			firstAndSecondAuthorOfLastBook(h);
			break;
		case 7:
			scientificAreaAndFirstAuthorOfAllBook(h);
			break;
		case 8:
			languageOfAllBook(h);
			break;
		case 9:
			choose(h);
			break;
		default:
			printf("Invalid command! \n");
				a = -1; 
				break;
			}
		}
}
void choose(book*h)
{
	int i;
	int a = 1;

	while (a>0)
	{
		menu();
		printf("please choose:");
		scanf("%d",&i);
		switch (i)
		{
		case 1:
				h=newFile();
				break;
		case 2:
				insertBook(h);
				break;
		case 3:
				search1(h);
				break;
		case 4:
				search2(h);
				break;
		case 5:
				removeBook(h);
				break;
		case 6:
				printOutput(h);
				break;
		case 7:
				h=getData();
				break;
		case 8:
				updateBook(h);
				break;
		case 9:
				Operations(h);
				break;
		case 10:
				saveFile(h);
				break;
		default:
			printf("Invalid command! \n");
				a = -1;// jump out of the loop condition 
				break;
			}
		}
}

int main()
{
	book*head = NULL;
	choose(head);
	return 0;
}
