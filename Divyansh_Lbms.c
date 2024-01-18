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
    int aval;
    struct book *next;
};
struct librarian{
	char fullname[50];
	char email[50];
    char pass[50];
    char username[50];
	char phone[50];
};
struct borrowedBook {
    char bookname[50];
    char studentID[10];
    char borrowDate[50];
    char returnDate[50];
};
struct student{
	char fullname[50];
	char email[50];
    char pass[50];
    char username[50];
    char studentID[10];
	char phone[50];
	struct borrowedBook borrowedBooks[10]; 
    int borrowedCount;
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
void save(const char* filename, struct book* head);
struct book* readff(const char* filename);
struct book* deletebook(struct book* head, const char* deleteId);
struct book* search(const char* filename, const char* searchName);
int borrowBook(struct book* head, const char* bookID, const char* studentID, const char* borrowDate, const char* returnDate);
void displaySttDat(const char* studentID);
void displayBBooks(const char* studentID);

int main(){
	system ("color 0b");
	struct book* head=NULL;
	struct librarian user1;
    struct librarian usr1;
    struct student user2;
    struct student usr2;
	FILE *fl;
	FILE *fs;
	struct book* bookList = NULL;
	struct book* searchr; 
	int opt,usr1found=0,choice;
	int usr2found=0;
	char bookID[10];
    char studentID[10];
    char borrowDate[50];
    char returnDate[50];
	char deleteId[10];
	char searchn[50];
	char username[50],pword[50];
	do{
	printf("\n================================================WELCOME TO LIBRARY=====================================================");
	printf("\n\t\t\t\t\t\t1.Singup as LIBRARIAN");
	printf("\n\t\t\t\t\t\t2.Singup as STUDENT");
	printf("\n\t\t\t\t\t\t3.Login as LIBRARIAN");
	printf("\n\t\t\t\t\t\t4.Login as STUDENT");
	printf("\n\t\t\t\t\t\t5.Exit");
    printf("\n\t\t\t\t\t\tEnter your choice:");
    scanf("%d",&opt);
    fgetc(stdin);
		switch(opt){
    	case 1:
    		printf("\nEnter your fullName :\t");
    		takeinput(user1.fullname);
    		printf("\nEnter your email:\t");
    		takeinput(user1.email);
    		printf("\nEnter your phone numer:\t");
    		takeinput(user1.phone);
    		printf("\nEnter your password:\t");
    		takeinput(user1.pass);
    		genrateusername(user1.email,user1.username);
    		fl=fopen("lib.dat","a+");
    		fwrite(&user1,sizeof(struct librarian),1,fl);
    		if (fwrite(&user1, sizeof(struct librarian), 1, fl) != 0) {
    			printf("\n\n Regstration succesfull....\nUSERNAME:%s",user1.username);
			}
    		else{
    			printf("something went worng....!");	
			}
			fclose(fl);
			break;
			
			
		case 2:
			    printf("\nEnter your fullName :\t");
    		    takeinput(user2.fullname);
    		    printf("\nEnter your email:\t");
    		    takeinput(user2.email);
    		    printf("\nEnter your phone numer:\t");
    		    takeinput(user2.phone);
    		    printf("\nEnter your password:\t");
    		    takeinput(user2.pass);
    		    printf("\nEnter student ID:");
    		    takeinput(user2.studentID);
    		    genrateusername(user2.email,user2.username);
    		    fs=fopen("stu.dat","a+");
    		    fwrite(&user2,sizeof(struct student),1,fs);
    		    if (fwrite(&user2, sizeof(struct student), 1, fs) != 0) {
              	     printf("\n\n Regstration succesfull....\nUSERNAME:%s",user2.username);
			   }
    		    else{
    			printf("something went worng....!");	
			   }
			fclose(fs);
			break;
		case 3:
		        printf("-------------------------------------------");
			    printf("\nEnter your Username :\t");
				 takeinput(username);
				 printf("\nEnter your password :\t");
				 takeinput(pword);
				 system("cls");
				 fl=fopen("lib.dat","r");
				 while(fread(&usr1,sizeof(struct librarian),1,fl)){
				    if(!strcmp(usr1.username,username)){
					    if(!strcmp(usr1.pass,pword)){
						  do{
						      system("cls");
						      printf("Logged in as %s\n", usr1.username);
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
                                    deleteId[strcspn(deleteId, "\n")] = '\0';
                              		bookList = deletebook(bookList, deleteId);
                              		   	printf("\n List after deletion:\n");
                                        display(bookList);
									save("books.dat", bookList);   
									   break;
                              	case 3:
                              		bookList=readff("books.dat");
								    display(bookList);
									 break;	 
								case 4:
                                     printf("Enter Name of the book : ");
                                     fgets(searchn, sizeof(searchn), stdin);
                                     searchr= search("books.dat", searchn);
									 if(search!=NULL){
									 	 printf("\nResult:\n");
										 display(searchr);
									 }
									 else{
									 	printf("Book is not available");
									 }
									 break; 
								case 5:
									printf("Loging out....");
									  
								default:
								    printf("invalid choice");	    	 
							  }
					       }while(choice!=5);
					}
					else{
						printf("\n\ninvalid password");
					      }
					   usr1found=1;
					}
				}
				if(!usr1found){
					printf("\n\nUser is not registered ");
				}
				fclose(fl);
				break;
		case 4:
			    printf("-----------------------------");
			    printf("\nEnter your Username :\t");
				 takeinput(username);
				 printf("\nEnter your password :\t");
				 takeinput(pword);
				 system("cls");
				 fs=fopen("stu.dat","r");
				 while(fread(&usr2,sizeof(struct student),1,fs)){
				    if(!strcmp(usr2.username,username)){
					    if(!strcmp(usr2.pass,pword)){
				           do{
						         system("cls");
						         printf("Logged in as %s\n", usr2.username);
                                 printf("1. Search Book\n");
                                 printf("2. Borrow a Book\n");
                                 printf("3. Display borrowed books\n");
                                 printf("4. Logout\n");
							     printf("enter your choice:\t");
							     scanf("%d", &choice);
                                 fgetc(stdin);
                                 system("cls");
							     switch(choice){
                              	        case 1:
                              	        	  printf("Enter Name of the book : ");
                                              fgets(searchn, sizeof(searchn), stdin);
                                              searchr= search("books.dat", searchn);
									          if(search!=NULL){
									 	         printf("\nResult:\n");
										         display(searchr);
									           }
									         else{
									 	         printf("Book is not available");
									           }
                              		         break;
                              	        case 2:
                              	        	  bookList=readff("books.dat");
                              		          printf("Enter your student ID: ");
                                              fgets(studentID, sizeof(studentID), stdin);
                                              studentID[strcspn(studentID, "\n")] = '\0';  
                                              printf("Enter the book ID you want to borrow: ");
                                              fgets(bookID, sizeof(bookID), stdin);
                                              bookID[strcspn(bookID, "\n")] = '\0';  
                                              printf("Enter borrow date (DD-MM-YYYY): ");
											  fgets(borrowDate, sizeof(borrowDate), stdin);
                                              borrowDate[strcspn(borrowDate, "\n")] = '\0'; 
                                              printf("Enter return date (DD-MM-YYYY): ");
                                              fgets(returnDate, sizeof(returnDate), stdin);
                                              returnDate[strcspn(returnDate, "\n")] = '\0';  
                                              int result = borrowBook(bookList, bookID, studentID, borrowDate, returnDate);
											  if(result){
                                                     printf("Book successfully borrowed.......!\n");
                                                     printf("\n---------------------------\n");
													 displaySttDat(studentID);
													 printf("\n---------------------------\n");
												} 
											  else{
                                                     printf("Borrowing failed....\n");
												}

                              		         break;
                              	        case 3:
								             printf("Enter your student ID to display borrowed books: ");
                                             fgets(studentID, sizeof(studentID), stdin);
                                             studentID[strcspn(studentID, "\n")] = '\0';  
                                             displayBBooks(studentID);
									         break;	  
								        case 4:
									         printf("Loging out....");
									          
								        default:
								            printf("invalid choice");	    	 
							        }
					         }while(choice!=5);
		                }
					else{
						printf("\n\ninvalid password");
					      }
					   usr2found=1;
					}
				}
				if(!usr2found){
					printf("\n\nUser is not registered ");
				}
				fclose(fs);
				break;
		case 5:
					printf("\t\t\t\t THANKYOU");
					return 0;
	 }
	}while(opt!=5);
	return 0;
}
struct book* addbook(struct book* head) {
    struct book* newBook = (struct book*)malloc(sizeof(struct book));
    FILE *fb;
    printf("Enter Book Name: ");
    fgets( newBook->bookname,50,stdin);
    printf("Enter Genre: ");
    fgets( newBook->genre,50,stdin);
    printf("Enter Author: ");
    fgets(newBook->author,50,stdin);
    printf("Enter Publication: ");
    fgets( newBook->publication,50,stdin);
    printf("Enter ID: ");
    fgets( newBook->id,10,stdin);
    printf("Enter Date of Entry: ");
    fgets( newBook->date,50,stdin);
    printf("Enter Number of Books available : ");
    scanf("%d",&newBook->aval);
    
   newBook->next = head;

    FILE* fa = fopen("books.dat", "a+");
    if (fa == NULL) {
        printf("Error opening file for appending.\n");
        
    }

    if (fprintf(fa, "%s %s %s %s %s %s %d\n", newBook->bookname, newBook->genre, newBook->author, newBook->publication, newBook->id, newBook->date,newBook->aval) < 0) {
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
        printf("\n---------------------------------------\n");
		printf("Book Name: %s\n", head->bookname);
        printf("Genre: %s\n", head->genre);
        printf("Author: %s\n", head->author);
        printf("Publication: %s\n", head->publication);
        printf("ID: %s\n", head->id);
        printf("Date: %s\n", head->date);
        printf("No of Books Available: %d\n", head->aval);  
		printf("\n");

        head = head->next;
    }
    getch();
}
struct book* deletebook(struct book* head, const char* deleteId) {
    struct book* current = head;
    struct book* previous = NULL;

    while (current != NULL && strcasecmp(current->id, deleteId) != 0) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (previous != NULL) {
            previous->next = current->next;
        } else {
            head = current->next;
        }
        free(current);
        printf("Book ID '%s' deleted successfully......\n", deleteId);
    } else {
        printf("Deletion failed. Book ID '%s' not found.\n", deleteId);
    }
   getch();
    return head;
}

struct book* search(const char* filename, const char* searchName) {
    struct book* head = NULL;
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    struct book temp;
    while (fscanf(file, "%49s %49s %49s %49s %9s %49s %d", temp.bookname, temp.genre, temp.author, temp.publication, temp.id, temp.date, &temp.aval) == 7) {
        if (strcmp(temp.bookname, searchName) == 0) {
            addbook(&head, &temp);
        }
    }

    fclose(file);
    return head;
}
void displaySttDat(const char* studentID) {
    struct student studentData;
    FILE* file = fopen("stu.dat", "r");
    

    while (fscanf(file, "%9s", studentData.studentID) == 1) {
        if (strcmp(studentData.studentID, studentID) == 0) {
            printf("Student ID: %s\n", studentData.studentID);

            
            for (int i = 0; i < studentData.borrowedCount; i++) {
                printf("Borrowed Book %d: %s\n", i + 1, studentData.borrowedBooks[i].bookname);
                printf("Borrow Date: %s\n", studentData.borrowedBooks[i].borrowDate);
                printf("Return Date: %s\n", studentData.borrowedBooks[i].returnDate);
                printf("-------------\n");
            }

            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Student ID '%s' not found in student data file.\n", studentID);
}


int borrowBook(struct book* head, const char* bookID, const char* studentID, const char* borrowDate, const char* returnDate) {
    struct book* current = head;

    
    while (current != NULL && strcmp(current->id, bookID) != 0) {
        current = current->next;
    }

    
    if (current != NULL) {
        
        if (current->aval > 0) {
            
            current->aval--;

            
            struct borrowedBook borrowed;
            strcpy(borrowed.bookname, current->bookname);
            strcpy(borrowed.studentID, studentID);
            strcpy(borrowed.borrowDate, borrowDate);
            strcpy(borrowed.returnDate, returnDate);

            struct student studentData;
            FILE* file = fopen("stu.dat", "r+");

            int found = 0;
            while (fscanf(file, "%9s", studentData.studentID) == 1) {
                if (strcmp(studentData.studentID, studentID) == 0) {
                   
                    fscanf(file, "%d", &studentData.borrowedCount);
                    if (studentData.borrowedCount < 10) {
                       
                        studentData.borrowedBooks[studentData.borrowedCount++] = borrowed;
                        fseek(file, -10, SEEK_CUR);  
                        fprintf(file, "%09d", studentData.borrowedCount);  
                        fseek(file, 0, SEEK_END);  
                        fprintf(file, " %s %s %s", borrowed.bookname, borrowed.borrowDate, borrowed.returnDate);  
                        printf("Book '%s' borrowed by student ID '%s' on %s. Return by %s.\n",
                            borrowed.bookname, borrowed.studentID, borrowed.borrowDate, borrowed.returnDate);
                        found = 1;
                        break;
                    } 
					else {
                        printf("Student has reached the maximum limit for borrowed books.\n");
                        fclose(file);
                        return 0;  
                    }
                } 
				else {
                    while (fgetc(file) != '\n');
                }
            }

            if (!found) {
                fseek(file, 0, SEEK_END);
                fprintf(file, "\n%9s %02d %s %s %s", studentID, 1, borrowed.bookname, borrowed.borrowDate, borrowed.returnDate);
                printf("Book '%s' borrowed by student ID '%s' on %s. Return by %s.\n",
                    borrowed.bookname, borrowed.studentID, borrowed.borrowDate, borrowed.returnDate);
            }

            fclose(file);

            return 1;  
        } 
		else {
            printf("Book '%s' is not available for borrowing.\n", current->bookname);
            return 0;  
        }
    } 
	else {
        printf("Book not found....");
        return 0; 
    }
}
void displayBBooks(const char* studentID) {
    struct borrowedBook borrowed;
    FILE* file = fopen("stu.dat", "r");
    if (file == NULL) {
        printf("Error opening student data file for reading.\n");
        return;
    }

    while (fscanf(file, "%9s", borrowed.studentID) == 1) {
        if (strcmp(borrowed.studentID, studentID) == 0) {
            printf("Borrowed Books for Student ID '%s':\n", borrowed.studentID);

            
            while (fscanf(file, "%49s %49s %49s %49s", borrowed.bookname, borrowed.borrowDate, borrowed.returnDate) == 3) {
                printf("Book Name: %s, Borrow Date: %s, Return Date: %s\n", borrowed.bookname, borrowed.borrowDate, borrowed.returnDate);
            }

            fclose(file);
            return;
        } else {
            
            while (fgetc(file) != '\n');
        }
    }

    fclose(file);
    printf("Student ID '%s' not found in student data file.\n", studentID);
}

struct book* readff(const char* filename) {
    struct book* head = NULL;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return NULL;
    }

    struct book temp;
    while (fscanf(file, "%49s %49s %49s %49s %9s %49s %d", temp.bookname, temp.genre, temp.author, temp.publication, temp.id, temp.date, &temp.aval) == 7) {
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
        newBook->aval = temp.aval;  
        newBook->next = head;
        head = newBook;
    }

    fclose(file);
    return head;
}


void save(const char* filename, struct book* head){

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    while (head != NULL) {
        fprintf(file, "%s %s %s %s %s %s %d\n", head->bookname, head->genre, head->author, head->publication, head->id, head->date, head->aval);
        head = head->next;
    }

    fclose(file);
}


struct book* search(const char* filename, const char* searchName) {
    struct book* head = NULL;
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    struct book temp;
    while (fscanf(file, "%49s %49s %49s %49s %9s %49s %d",
                  temp.bookname, temp.genre, temp.author, temp.publication, temp.id, temp.date, &temp.aval) == 7) {
        if (strcmp(temp.bookname, searchName) == 0) {
            FILE* fa = fopen("books.dat", "a+");
            if (fa == NULL) {
                printf("Error opening file for appending.\n");
                fclose(file);
                return head;
            }

            head = addBook(head, fa);
            fclose(fa);
            break;  // Assuming you want to add the book once and then stop searching
        }
    }

    fclose(file);
    return head;
}
