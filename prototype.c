#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct book {
    char bookname[50];
    char genre[50];
    char author[50];
	char publication[50];
    char id[10];
    char date[50];
    struct book *next;
};

struct user{
	char fullname[50];
	char email[50];
    char pass[50];
    char username[50];
    int role;
	char phone[50];
	char lend[50]; 

};



void takeinput(char ch[50]){
	fgets(ch,50,stdin);
	ch[strlen(ch)-1]=0;
	
}

char genrateusername(char email[50],char username[50]){
	int i;
	for(i=0;i<strlen(email);i++){
		if(email[i]=='@'){
		    break;
		} 
		else {
		   username[i]=email[i];
		}
	}
}

struct book* addbook(struct book* head);
void display(struct book* head);
void save(struct book* head);
struct book* readff(const char* filename);
struct book* deletebook(struct book* head);
struct book* search(const char* filename, const char* searchName)

int main(){
	system ("color 0b");
	struct book* head=NULL;
	struct user user;
    struct user usr;
	FILE *fp;
	struct book* bookList = NULL;
	struct book* searchr; 
	
	int opt,usrfound=0,choice;
	char deleteId[10];
	char searchn[50];
	char username[50],pword[50];
	do{
	printf("\n================================================WELCOME TO LIBRARY=====================================================");
	printf("\n\t\t\t\t\t\t1.Singup");
	printf("\n\t\t\t\t\t\t2.Login");
	printf("\n\t\t\t\t\t\t3.Exit");
    printf("\n\t\t\t\t\t\tEnter your choice:");
    scanf("%d",&opt);
    fgetc(stdin);
		switch(opt){
    	case 1:
    		printf("\nEnter your fullName :\t");
    		takeinput(user.fullname);
    		printf("\nEnter your email:\t");
    		takeinput(user.email);
    		printf("\nEnter your phone numer:\t");
    		takeinput(user.phone);
    		printf("\nEnter your password:\t");
    		takeinput(user.pass);
    		printf("\nSignup as:(1.for librarian 2.Students):\t");
    		scanf("%d",&user.role);
    		genrateusername(user.email,user.username);
    		fp=fopen("user.dat","a+");
    		fwrite(&user,sizeof(struct user),1,fp);
    		if (fwrite(&user, sizeof(struct user), 1, fp) != 0) {

    			printf("\n\n Regstration succesfull....\nUSERNAME:%s",user.username);
			}
    		else{
    			printf("something went worng....!");
    			
			}
			fclose(fp);
			break;
			
			
			case 2:
				   
				 
				 printf("\nEnter your Username :\t");
				 takeinput(username);
				 printf("\nEnter your password :\t");
				 takeinput(pword);
				 system("cls");
				 fp=fopen("user.dat","r");
				 while(fread(&usr,sizeof(struct user),1,fp)){
				    if(!strcmp(usr.username,username)){
					    if(!strcmp(usr.pass,pword)){
						 if(usr.role==1){
						  do{
						      system("cls");
						      printf("Logged in as %s(Role:%d)\n", usr.username,usr.role);
                              printf("1. Add Book\n");
                              printf("2. Delete Book\n");
                              printf("3. Display Books List\n");
                              printf("4. Search Books List\n");
                              printf("5. Logout\n");
							  printf("enter your choice:\t");
							  scanf("%d", &choice);
                              fgetc(stdin);
                              system("cls");
							  switch(choice){
                              	case 1:
                              		head=addbook(head);
									break;
                              	case 2:
                              		bookList=readff("books.dat");
									printf("Enter the book ID to delete: ");
                                    fgets(deleteId, sizeof(deleteId), stdin);
                              		  bookList = deleteBookById(bookList, deleteId);
									   break;
                              	case 3:
                              		bookList=readff("books.dat");
								    display(bookList);
									 break;	 
								case 4:
                                     printf("Enter Name of the book : ");
                                     fgets(searchn, sizeof(searchn), stdin);
                                     searchr= search("books.dat", searchName);
									 if(search!=NULL){
									 	 printf("\nResult:\n")
										 display(searchr);
									 }
									 else{
									 	printf("Book is not available");
									 }
									 break; 
								case 5:
									printf("Loging out....");
									  return;
								default:
								    printf("invalid choice");	    	 
							  }
					       }while(choice!=5);
					      }
					      else{
					      	 do{
						         system("cls");
						         printf("Logged in as %s(Role:%d)\n", usr.username,usr.role);
                                 printf("1. Display Books List\n");
                                 printf("2. Display borrowed books\n");
                                 printf("3. Search Book\n");
                                 printf("4. Logout\n");
							     printf("enter your choice:\t");
							     scanf("%d", &choice);
                                 fgetc(stdin);
                                 system("cls");
							     switch(choice){
                              	        case 1:
                              		          head=addbook(head);
									         break;
                              	        case 2:
                              		          head = deletebook(head);
                              		         break;
                              	        case 3:
								             //display();
									         break;	  
								        case 4:
									         printf("Loging out....");
									          return;
								        default:
								            printf("invalid choice");	    	 
							        }
					         }while(choice!=5);
						   }
					   }
						else{
						printf("\n\ninvalid password");
					      }
					   usrfound=1;
					}
				}
				if(!usrfound){
					printf("\n\nUser is not registered ");
				}
				fclose(fp);
				break;
				case 3:
					printf("\t\t\t\t THANKYOU");
					return 0;
	 }
	}while(opt!=3);
	return 0;
}
struct book* addbook(struct book* head) {
    struct book* newBook = (struct book*)malloc(sizeof(struct book));
    FILE *fb;
    printf("Enter Book Name: ");
    fgets( newBook->bookname,50,stdin);
    fgetc(stdin);
    printf("Enter Genre: ");
    fgets( newBook->genre,50,stdin);
    fgetc(stdin);
    printf("Enter Author: ");
    fgets(newBook->author,50,stdin);
    fgetc(stdin);
    printf("Enter Publication: ");
    fgets( newBook->publication,50,stdin);
    fgetc(stdin);
    printf("Enter ID: ");
    fgets( newBook->id,10,stdin);
    fgetc(stdin);
    printf("Enter Date: ");
    fgets( newBook->date,50,stdin);
    fgetc(stdin);
   newBook->next = head;

    FILE* fa = fopen("books.dat", "a+");
    if (fa == NULL) {
        printf("Error opening file for appending.\n");
        
    }

    if (fprintf(fa, "%s %s %s %s %s %s\n", newBook->bookname, newBook->genre, newBook->author, newBook->publication, newBook->id, newBook->date) < 0) {
        printf("Error writing to the file. Book not added.\n");
    } 
	else{
        printf("Book successfully added to the file.\n");
    }

    fclose(fa);
getch();
    return newBook;
}

void display(struct book* head) {
    while (head != NULL) {
        printf("Book Name: %s\n", head->bookname);
        printf("Genre: %s\n", head->genre);
        printf("Author: %s\n", head->author);
        printf("Publication: %s\n", head->publication);
        printf("ID: %s\n", head->id);
        printf("Date: %s\n", head->date);
        printf("\n");

        head = head->next;
    }
    getch();
}
struct book* deletebook(struct book* head, const char* deleteId) {
    struct book* current = head;
    struct book* previous = NULL;

    
    while((current!= NULL)&&strcmp(current->id, deleteId)!= 0){
        previous = current;
        current = current->next;
    }
    if (current!=NULL){
        if (previous!=NULL){
            previous->next = current->next;
        } 
		else{
            head = current->next;
        }
        free(current);
        printf("Book ID '%s' deleted successfully......\n", deleteId);
    } 
	else{
        printf("Deletion failed.....\n", deleteId);
    }

    return head;
}
struct book* search(const char* filename, const char* searchName) {
    struct book* head = NULL;
    FILE* file = fopen(filename, "r+");
    

    struct book temp;
    while (fscanf(file, "%49s %49s %49s %49s %9s %49s", temp.bookname, temp.genre, temp.author, temp.publication, temp.id, temp.date) == 6) {
        if (strcmp(temp.bookname, searchName) == 0) {
            struct book* newBook = (struct book*)malloc(sizeof(struct book));
            

            snprintf(newBook->bookname, sizeof(newBook->bookname), "%s", temp.bookname);
            snprintf(newBook->genre, sizeof(newBook->genre), "%s", temp.genre);
            snprintf(newBook->author, sizeof(newBook->author), "%s", temp.author);
            snprintf(newBook->publication, sizeof(newBook->publication), "%s", temp.publication);
            snprintf(newBook->id, sizeof(newBook->id), "%s", temp.id);
            snprintf(newBook->date, sizeof(newBook->date), "%s", temp.date);

            newBook->next = head;
            head = newBook;
        }
    }

    fclose(file);
    return head;
}

/*void lend(){
	char searchName[50];

    printf("\nEnter Book Name :\t");
    fgets(searchName,50, stdin);
    fgetc(stdin);

    size_t len = strlen(searchName);
    if (len > 0 && searchName[len - 1] == '\n') {
        searchName[len - 1] = '\0';  
    }

    FILE *fb 
	fb = fopen("books.dat", "rb");
    if(fb == NULL){
        printf("Error opening file!\n");
        return;
    }

    struct book searchBook;
    struct user student;

    int found = 0;

    while (fread(&searchBook, sizeof(struct book), 1, fb) == 1) {
        if (strcmp(searchBook.bookname, searchName) == 0) {
            found = 1;
            if(){//kuch aisa condition daalu jo availability he according ho uske liye struct book mai kuch add karna padega
               strcpy(student.lend,searchName)
			}
			
            
        }
    }

    fclose(fb);

    if (!found) {
        printf("Currently %s is not available!\n",searchName);
    }
	
}*/
struct book* readff(const char* filename) {
    struct book* head = NULL;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return NULL;
    }

    struct book temp;
    while (fscanf(file, "%49s %49s %49s %49s %9s %49s", temp.bookname, temp.genre, temp.author, temp.publication, temp.id, temp.date) == 6) {
        struct book* newBook = (struct book*)malloc(sizeof(struct book));
        if (newBook == NULL) {
            printf("Memory allocation failed.\n");
            fclose(file);
            return NULL;
        }

        snprintf(newBook->bookname, sizeof(newBook->bookname), "%s", temp.bookname);
        snprintf(newBook->genre, sizeof(newBook->genre), "%s", temp.genre);
        snprintf(newBook->author, sizeof(newBook->author), "%s", temp.author);
        snprintf(newBook->publication, sizeof(newBook->publication), "%s", temp.publication);
        snprintf(newBook->id, sizeof(newBook->id), "%s", temp.id);
        snprintf(newBook->date, sizeof(newBook->date), "%s", temp.date);

        newBook->next = head;
        head = newBook;
    }

    fclose(file);
    return head;
}
void save(struct book* head) {
    FILE* fb;
    fb = fopen("books.dat", "a+");

    if(fb == NULL){
        printf("Error opening file for writing.\n");
        return;
    }

    struct book* current = head;

    while(current != NULL){
        fprintf(fb, "%s %s %s %s %s %s\n",
                current->bookname, current->genre, current->author,
                current->publication, current->id, current->date);
        current = current->next;
    }

    fclose(fb);
}
