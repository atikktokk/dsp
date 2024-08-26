#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>


// define struct

struct BirthDate
{
    int day;
    int month;
    int year;
};

struct details
{
	char name[150];
	int age;
	char phoneNum[20];
    char address[200];
    char budget[30];
    char layout[50];
    struct BirthDate * dob;

};

struct Theme
{
    char personName[150];
    char themeName[150];
    int size;
    struct Theme* next;
};

struct Decoration
{
    char personName[150];
    char decoration[50];
    int quantitydecoration;
    int sizedecoration;
};

struct DecorationStack
{
    struct Decoration data;
    struct DecorationStack* next;
};

struct person
{
	struct details data;
	struct person *ptrnext;
	struct DecorationStack* decorationStack;
};

struct person *headptr,*newptr,*curptr,*prevptr;

struct Theme* front = NULL;
struct Theme* rear = NULL;

struct person *merge(struct person *left, struct person *right);
struct person *mergeSort(struct person *head);


//Declaration function
void insertDataFromUser();
void displayData(struct person *start);
void updatePersonDetail(char name[]);
void searchByName(const char *targetName);
void searchByLayout(const char *targetlayout);
void deletePerson(char name[]);
void addDecoration(struct person* personPtr);
void displayDecorationByName(struct person* personPtr);
void markDecorationTaken(struct person* personPtr);
void chooseTheme(char name[]);
void dequeueTheme();
void displayTheme();
void bubbleSort() ;


//main menu
int main()
{
    headptr = NULL;

    int choice, optionsearch, optionsort;
    char addMore;

    printf("\t\tWELCOME TO OUR DREAM DESIGN CO  \n");
    printf("----------------------------------------------------\n");

	do
	{
		printf("\n");
		printf("\t\t[MAIN MENU]");
		printf("\n");
		printf("\n1. Add Person Details ");
		printf("\n2. Update Person Details ");
		printf("\n3. Display Person Details ");
		printf("\n4. Delete Person Details ");
		printf("\n5. Add Decoration for Person ");
		printf("\n6. Display current Decoration  ");
		printf("\n7. Arrive Decoration ");
		printf("\n8. Choose Theme ");
		printf("\n9. Display Theme ");
		printf("\n10. Remove Theme ");
		printf("\n11. Search  ");
		printf("\n12. Sort ");
		printf("\n13. Exit ");

		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);

		switch (choice) {
            case 1:
               	printf("\n\n\n");
                printf("\nPLEASE FILL UP THE PERSON DETAILS BELOW: \n");
                insertDataFromUser();
                break;
            case 2:
               	printf("\n\n\n");
               if (headptr != NULL)
			   {
                char nameToUpdate[150];
                printf("\nEnter the name of the person to update: ");
                getchar();
                fgets(nameToUpdate, sizeof(nameToUpdate), stdin);
                strtok(nameToUpdate, "\n");
                updatePersonDetail(nameToUpdate);
				}
				else
				{
                printf("\nNo data to update. Please insert data first.\n");
                }
                break;
            case 3:
               	printf("\n\n\n");
                if (headptr != NULL) {
                    displayData(headptr);
                } else {
                    printf("\nNo data to display. Please insert data first.\n");
                }
                break;
            case 4:
               	printf("\n\n\n");
                if (headptr != NULL) {
                    char nameToDelete[150];
                    printf("\nEnter the name of the person to delete: ");
                    getchar();
                    fgets(nameToDelete, sizeof(nameToDelete), stdin);
                    strtok(nameToDelete, "\n");
                    deletePerson(nameToDelete);
                } else {
                    printf("\nNo data to delete. Please insert data first.\n");
                }
                break;
            case 5:
                printf("\n\n\n");
                if (headptr != NULL) {
                    char nameToAddDecoration[150];
                    printf("\nEnter the name of the person to add decoration: ");
                    getchar();
                    fgets(nameToAddDecoration, sizeof(nameToAddDecoration), stdin);
                    strtok(nameToAddDecoration, "\n");
                    curptr = headptr;
                    while (curptr != NULL && strcmp(curptr->data.name, nameToAddDecoration) != 0) {
                        curptr = curptr->ptrnext;
                    }

                    if (curptr != NULL) {
                        addDecoration(curptr);
                    } else {
                        printf("\nPerson with name %s not found.\n", nameToAddDecoration);
                    }
                } else {
                    printf("\nNo data to add decoration. Please insert data first.\n");
                }
            	break;
            case 6:
                printf("\n\n\n");
                if (headptr != NULL)
				{
                    char nameToDisplayDecoration[150];
                    printf("\nEnter the name of the person to display decoration: ");
                    getchar();
                    fgets(nameToDisplayDecoration, sizeof(nameToDisplayDecoration), stdin);
                    strtok(nameToDisplayDecoration, "\n");

                    curptr = headptr;
                    while (curptr != NULL && strcmp(curptr->data.name, nameToDisplayDecoration) != 0) {
                        curptr = curptr->ptrnext;
                    }

                    if (curptr != NULL) {
                        displayDecorationByName(curptr);
                    } else {
                        printf("\nPerson with name %s not found.\n", nameToDisplayDecoration);
                    }
                } else {
                    printf("\nNo data to display decoration. Please insert data first.\n");
                }
            	break;
            case 7:
                printf("\n\n\n");
                if (headptr != NULL) {
                    char nameToMarkDecoration[150];
                    printf("\nEnter the name of the person to mark decoration arrive: ");
                    getchar();
                    fgets(nameToMarkDecoration, sizeof(nameToMarkDecoration), stdin);
                    strtok(nameToMarkDecoration, "\n");
                    curptr = headptr;
                    while (curptr != NULL && strcmp(curptr->data.name, nameToMarkDecoration) != 0) {
                        curptr = curptr->ptrnext;
                    }

                    if (curptr != NULL) {
                        markDecorationTaken(curptr);
                    } else {
                        printf("\nPerson with name %s not found.\n", nameToMarkDecoration);
                    }
                } else {
                    printf("\nNo data to mark decoration arrive. Please insert data first.\n");
                }
            	break;
            case 8:
               	printf("\n\n\n");
            	if (headptr != NULL)
            	{
            		char nametoTheme[150];
            		printf("\nEnter person's name: ");
            		getchar();
                    fgets(nametoTheme, sizeof(nametoTheme), stdin);
                    strtok(nametoTheme, "\n");
                    chooseTheme(nametoTheme);
                }
            	else
				{
                    printf("\nNo data to choose Theme. Please insert data first.\n");
                }
                break;
            case 9:
               	printf("\n\n\n");
            	displayTheme();
                break;
            case 10:
               	printf("\n\n\n");
            	dequeueTheme();
                break;
            case 11:
               	printf("\n\n\n");
               	printf("1. Search by Person \n2. Search by Layout");
               	printf("\n Please enter your choice for searching: ");
               	scanf("%d", &optionsearch);
               	if (optionsearch==1)
               	{
               		printf("\n");
	            	printf("\nEnter the person's name to search: ");
	                char searchName[150];
	                getchar();
	                fgets(searchName, sizeof(searchName), stdin);
	                strtok(searchName, "\n");
	                searchByName(searchName);
				   }
				else
				{
					printf("\nEnter the Layout to search (Bedroom, Studio, Kitchen, Living Room): ");
	                char searchLayout[50];
	                getchar();
	                fgets(searchLayout, sizeof(searchLayout), stdin);
	                strtok(searchLayout, "\n");
	                searchByLayout(searchLayout);
				}
               	break;


            case 12:
            	printf("\n1. Sort Person by Budget 2. Sort Person by Alphabet ");
            	printf("\n Please enter your choice for sorting: ");
            	scanf("%d", &optionsort);
            	if (optionsort==1)
            	{
            		bubbleSort();
				}
				else
				{
					 if (headptr != NULL)
					{
	                    headptr = mergeSort(headptr);
	                    displayData(headptr);
	                }
					else {
	                    printf("\nNo data to sort. Please insert data first.\n");
	                }
				}
            	break;
            case 13:
               	printf("\n\n\n");
			    printf("Thank You For using our system !! ");
			    printf("\n\n\n");
			    exit(0);
                break;
            default:
                printf("\n\t\t               Invalid choice\n");
                break;
        }

        // Ask the user if they want to continue
        if (choice != 15) {
            printf("\nDo you want to continue? (y/n): ");
            scanf(" %c", &addMore);
            getchar();
        }

    } while (choice != 15 && (addMore == 'y' || addMore == 'Y'));


		if(addMore=='N'||addMore=='n')
		{
			system("cls");
            printf("\n\n\n");
		    printf("\t\t\t\t             		Dream Design Co \n");
		    printf("\t\t\t\t          -----------------------------------------\n");
			printf("\n\n\t\t\t\t             Thank You For using our system !! ");
			printf("\n\n\n");
			exit(0);
		}

    curptr = headptr;
    while (curptr != NULL) {
        prevptr = curptr;
        curptr = curptr->ptrnext;
        free(prevptr);
    }

return 0;
}

// Function to add person at the begining//Stack (last-in,first-out) (LIFO)//push
void insertDataFromUser()
{


    newptr = (struct person *)malloc(sizeof(struct person));
    if (newptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newptr->data.dob = (struct BirthDate*)malloc(sizeof(struct BirthDate));
	if (newptr->data.dob == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }


    printf("\nEnter name: ");
    getchar();
    fgets(newptr->data.name, sizeof(newptr->data.name), stdin);
    strtok(newptr->data.name, "\n");

    printf("\nEnter age: ");
    scanf("%d", &newptr->data.age);

    printf("-----------------\n");
    printf("|Layout          |\n");
    printf("-----------------\n");
    printf("|1. Bedroom      |\n");
    printf("|2. Studio       |\n");
    printf("|3. Kitchen      |\n");
    printf("|4. Living Room  |\n");
    printf("-----------------\n");
	printf("\nEnter Layout Name: ");
    getchar();
    fgets(newptr->data.layout, sizeof(newptr->data.layout), stdin);
    strtok(newptr->data.layout, "\n");

    printf("\nEnter phone number: ");
    fgets(newptr->data.phoneNum, sizeof(newptr->data.phoneNum), stdin);
    strtok(newptr->data.phoneNum, "\n");

    printf("\nCustomer Birth Date\n");
    printf("\nDay: ");
	scanf("%d", &newptr->data.dob->day);

	printf("\nMonth: ");
	scanf("%d", &newptr->data.dob->month);

	printf("\nYear: ");
	scanf("%d", &newptr->data.dob->year);

	fflush (stdin);
    printf("\nEnter address: ");
    fgets(newptr->data.address, sizeof(newptr->data.address), stdin);
    strtok(newptr->data.address, "\n");


    printf("\nEnter budget expenses: ");
    fgets(newptr->data.budget, sizeof(newptr->data.budget), stdin);
    strtok(newptr->data.budget, "\n");

    newptr->decorationStack = NULL;

    newptr->ptrnext = headptr;
    headptr = newptr;
}


// Function to display data of each person in the linked list
void displayData(struct person *start)
{
    curptr = start;

    // Traverse the linked list and print each person's data
    while (curptr != NULL) {
        printf("\nName: %s\n", curptr->data.name);
        printf("\nAge: %d\n", curptr->data.age);
        printf("\nCustomer birthdate: %d/%d/%d\n", curptr->data.dob->day, curptr->data.dob->month, curptr->data.dob->year );
        printf("\nAddress: %s\n", curptr->data.address);
        printf("\nLayout: %s\n", curptr->data.layout);
        printf("\nPhone Number: %s\n", curptr->data.phoneNum);
        printf("\nBudget Expenses: %s\n", curptr->data.budget);
        printf("\n");

        curptr = curptr->ptrnext;
    }
}

// Function to update a specific detail of a person based on their name
void updatePersonDetail(char name[])
{
    curptr = headptr;

    while (curptr != NULL && strcmp(curptr->data.name, name) != 0) {
        prevptr = curptr;
        curptr = curptr->ptrnext;
    }

    if (curptr != NULL) {
        printf("\n1. Layout 2. Address");
        printf("\nPlease enter your choice for update : ");

        int detailChoice;
        scanf("%d", &detailChoice);

        getchar();

        switch (detailChoice) {
            case 1:
                printf("-----------------\n");
                printf("|Layout          |\n");
                printf("-----------------\n");
                printf("|1. Bedroom      |\n");
                printf("|2. Studio       |\n");
                printf("|3. Kitchen      |\n");
                printf("|4. Living Room  |\n");
                printf("-----------------\n");
                printf("\nEnter new layout: ");
                fgets(curptr->data.layout, sizeof(curptr->data.layout), stdin);
                strtok(curptr->data.layout, "\n");
                break;
            case 2:
                // Update address
                printf("\nEnter new Address: ");
                fgets(curptr->data.address, sizeof(curptr->data.address), stdin);
                strtok(curptr->data.address, "\n");
                break;
            default:
                printf("\nInvalid choice. No details updated.\n");
                return;
        }

        printf("\nPerson details updated successfully!\n");
    } else {
        printf("\nPerson not found.\n");
    }
}

//Implement searching person using linear sequential searching by name
void searchByName(const char *targetName)
{
    curptr = headptr;
    int found = 0;

    while (curptr != NULL) {
        if (strcmp(curptr->data.name, targetName) == 0) {
            found = 1;
            break;
        }
        curptr = curptr->ptrnext;
    }

    if (found) {
        printf("\nPerson found!\n");
        printf("\nName: %s\n", curptr->data.name);
        printf("\nAge: %d\n", curptr->data.age);
        printf("\nLayout: %s\n", curptr->data.layout);
        printf("\nPhone Number: %s\n", curptr->data.phoneNum);
    } else {
        printf("\nPerson not found.\n");
    }
}

//Implement searching using linear sequential searching by layout
void searchByLayout(const char *targetLayout)
{
    curptr = headptr;
    int found = 0;

    while (curptr != NULL) {
        if (strcmp(curptr->data.layout, targetLayout) == 0) {
            found = 1;
            break;
        }
        curptr = curptr->ptrnext;
    }

    if (found) {
        printf("\n\Person found!\n");
        printf("\nName: %s\n", curptr->data.name);
        printf("\nAge: %d\n", curptr->data.age);
        printf("\n Layout: %s\n", curptr->data.layout);
        printf("\n\Phone Number: %s\n", curptr->data.phoneNum);
    } else {
        printf("\nPerson not found.\n");
    }
}


//implement linked list for delete by person name from the list
void deletePerson(char name[])
{
    curptr = headptr;
    struct person *temp;

    if (curptr != NULL && strcmp(curptr->data.name, name) == 0) {
        headptr = curptr->ptrnext;
        free(curptr);
        printf("\nPerson details deleted successfully!\n");
        return;
    }

    // Search for the person to delete
    while (curptr != NULL && strcmp(curptr->data.name, name) != 0) {
        prevptr = curptr;
        curptr = curptr->ptrnext;
    }

    // If the person is found, delete them
    if (curptr != NULL) {
        prevptr->ptrnext = curptr->ptrnext;
        free(curptr);
        printf("\nPerson details deleted successfully!\n");
    } else {
        printf("\n\Person not found.\n");
    }
}

//implement linked list for display detail from the list
void displaydetails()
{
    printf("\nDisplaying data of all persons:\n");
    displayData(headptr);
}

// Modify the function definition for the addDecoration function
void addDecoration(struct person* personPtr)
{
    struct Decoration newDecoration;
    printf("-----------------\n");
    printf("|Decoration      |\n");
    printf("-----------------\n");
    printf("|1. Sofa         |\n");
    printf("|2. Chair        |\n");
    printf("|3. Table        |\n");
    printf("|4. Bed          |\n");
    printf("|5. Wardrobe     |\n");
    printf("-----------------\n");
    printf("\nEnter decoration name: ");
    getchar();
    fgets(newDecoration.decoration, sizeof(newDecoration.decoration), stdin);
    strtok(newDecoration.decoration, "\n");

    printf("\nQuantity: ");
    scanf("%d", &newDecoration.quantitydecoration);

    if (newDecoration.quantitydecoration > 1)
	 {
        for (int i = 0; i < newDecoration.quantitydecoration; ++i) {
            printf("\nEnter size for decoration %d (1:Small, 2:Medium, 3:Large): ", i + 1);
            scanf("%d", &newDecoration.sizedecoration);

            // Create a new node for the Decoration
            struct DecorationStack* newNode = (struct DecorationStack*)malloc(sizeof(struct DecorationStack));

            if (newNode == NULL) {
                printf("\nMemory allocation failed!\n");
                exit(1);
            }

            newNode->data = newDecoration;
            newNode->next = personPtr->decorationStack;
            personPtr->decorationStack = newNode;
        }
    } else {
        printf("\nEnter size of the decoration (1:Small, 2:Medium, 3:Large): ");
        scanf("%d", &newDecoration.sizedecoration);

        struct DecorationStack* newNode = (struct DecorationStack*)malloc(sizeof(struct DecorationStack));

        if (newNode == NULL) {
            printf("\n\nMemory allocation failed!\n");
            exit(1);
        }

        newNode->data = newDecoration;
        newNode->next = personPtr->decorationStack;
        personPtr->decorationStack = newNode;
    }

    printf("\nDecoration information added successfully for %s!\n", personPtr->data.name);
}


//display function for decoration by name
void displayDecorationByName(struct person* personPtr)
{
    if (personPtr->decorationStack == NULL)
    {
        printf("\nNo decoration for %s.\n", personPtr->data.name);
        return;
    }

    printf("\n Decoration for %s:\n", personPtr->data.name);

    struct DecorationStack* currentDecoration = personPtr->decorationStack;
    int count = 1;

    while (currentDecoration != NULL) {
        printf("\n%d. Decoration: %s\n", count, currentDecoration->data.decoration);

        if (currentDecoration->data.sizedecoration == 1)
        {
            printf("Size: Small\n");
        }
        else if (currentDecoration->data.sizedecoration == 2)
        {
            printf("Size: Medium\n");
        }
        else
        {
            printf("Size: Large\n");
        }

        currentDecoration = currentDecoration->next;
        count++;
    }
}


//Display status of decoration arrival using stack//pop
void markDecorationTaken(struct person* personPtr)
{
    if (personPtr->decorationStack == NULL) {
        printf("\n No decoration marks to arrive for %s.\n", personPtr->data.name);
        return;
    }

    printf("\ndecoration for %s:\n", personPtr->data.name);

    struct DecorationStack* currentDecoration = personPtr->decorationStack;
    int count = 1;

    // Display decoration and let the user choose which one to mark as arived
    while (currentDecoration != NULL) {
        printf("\n%d. Decoration: %s\n", count, currentDecoration->data.decoration);
        printf("Quantity Decoration: %d\n", currentDecoration->data.quantitydecoration);
        printf("Size of Decoration: %d\n", currentDecoration->data.sizedecoration);

        currentDecoration = currentDecoration->next;
        count++;
    }

    int choice;
    printf("\nEnter the number of the decoration to mark as taken: ");
    scanf("%d", &choice);

    // Remove the chosen decoration node from the stack
    if (choice == 1) {
        // Special case if the first node is chosen
        struct DecorationStack* temp = personPtr->decorationStack;
        personPtr->decorationStack = temp->next;
        free(temp);
    } else {
        currentDecoration = personPtr->decorationStack;
        for (int i = 1; i < choice - 1 && currentDecoration->next != NULL; i++) {
            currentDecoration = currentDecoration->next;
        }

        if (currentDecoration->next != NULL) {
            struct  DecorationStack* temp = currentDecoration->next;
            currentDecoration->next = temp->next;
            free(temp);
        } else {
            printf("\nInvalid choice. No decoration removed.\n");
            return;
        }
    }

    printf("\nDecoration marked as arrive for %s!\n", personPtr->data.name);
}

//choose a new theme for person to choose colour scheme
void chooseTheme(char name[])
{
	curptr = headptr;
    int personFound = 0;

    while (curptr != NULL) {
        if (strcmp(curptr->data.name, name) == 0) {
            personFound = 1;
            break;
        }
        curptr = curptr->ptrnext;
    }

    if (!personFound) {
        printf("\nPerson with name %s not found in the system.\n", name);
        return;
    }

    struct Theme newTheme;
    strcpy(newTheme.personName, name);

    // Choose colour scheme
    printf("-----------------\n");
    printf("|Colour Scheme   |\n");
    printf("-----------------\n");
    printf("|1. Grey         |\n");
    printf("|2. Blue         |\n");
    printf("|3. White        |\n");
    printf("|4. Brown        |\n");
    printf("|5. Green        |\n");
    printf("-----------------\n");
    printf("\nChoose colour: ");
    int themeOption;
    scanf("%d", &themeOption);

    switch (themeOption) {
        case 1:
            strcpy(newTheme.themeName, "Grey");
            break;
        case 2:
            strcpy(newTheme.themeName, "Blue");
            break;
        case 3:
            strcpy(newTheme.themeName, "White");
            break;
        case 4:
            strcpy(newTheme.themeName, "Brown");
            break;
        case 5:
            strcpy(newTheme.themeName, "Green");
            break;
        default:
            printf("\nInvalid colour. Please select 1 to 5.\n");
            return;
    }

    // Choose style
    printf("-----------------\n");
    printf("|Style           |\n");
    printf("-----------------\n");
    printf("|1. Modern       |\n");
    printf("|2. Minimalist   |\n");
    printf("|3. Contemporary |\n");
    printf("-----------------\n");
    printf("\nChoose style for the theme: ");
    scanf("%d", &newTheme.size);

    if (newTheme.size < 1 || newTheme.size > 3) {
        printf("\nInvalid theme. Please select 1, 2, or 3.\n");
        return;
    }

    printf("\nColour choosen successfully for ");

    switch (newTheme.size) {
        case 1:
            printf("Modern");
            break;
        case 2:
            printf("Minimalist");
            break;
        case 3:
            printf("Contemporary");
            break;
    }

    printf("!\n");

    struct Theme* newNode = (struct Theme*)malloc(sizeof(struct Theme));

    if (newNode == NULL) {
        printf("\n\nMemory allocation failed!\n");
        return;
    }

    strcpy(newNode->personName, newTheme.personName);
    strcpy(newNode->themeName, newTheme.themeName);
    newNode->size= newTheme.size;
    newNode->next = NULL;

    //enque
    //check if queue is empty

    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode; //rear point to new node
        rear = newNode; //assign new node as rear
    }

    // Display the updated list of theme
    displayTheme();
}

//implement deque operation using linked list
void dequeueTheme()
{
    if (front == NULL) {
        printf("\n\n!!! Theme Queue is EMPTY - Cannot dequeue !!!\n");
    } else {
        struct Theme* temp = front;
        front = front->next;
        free(temp);
        printf("\n\nFront theme dequeued successfully!\n");
    }

    displayTheme();
}

//display theme using linked list
void displayTheme()
{
    if (front == NULL) {
        printf("\n\nThe theme queue is empty\n");
    } else {
        struct Theme* current = front;

        printf("\n\nTheme display:\n");
        printf("\nStyle (1.Modern, 2.Minimalist, 3.Contemporary)\n");
        while (current != NULL) {
            printf("\nPerson: %s, \nColour: %s, \nStyle: %d\n", current->personName, current->themeName, current->size);
            current = current->next;
        }
    }
}

//implement sorting using bubble sort by budget
void bubbleSort()
{
	 if (headptr == NULL || headptr->ptrnext == NULL) {
        // No need to sort if the list is empty or has only one element
        return;
    }

    int swapped;
    struct person *last = NULL;

    do {
        swapped = 0;
        curptr = headptr;

        while (curptr->ptrnext != last) {
            if (curptr->data.age > curptr->ptrnext->data.age) {
                // Swap nodes
                struct person *temp = curptr->ptrnext;
                curptr->ptrnext = temp->ptrnext;
                temp->ptrnext = curptr;
                if (curptr == headptr) {
                    headptr = temp;
                } else {
                    prevptr->ptrnext = temp;
                }
                swapped = 1;
            } else {
                prevptr = curptr;
                curptr = curptr->ptrnext;
            }
        }

        last = curptr;

    } while (swapped);

    displaydetails();

}

// implement sorting using merge sort by name alphabatical
struct person *merge(struct person *left, struct person *right)
{
	struct person *result = NULL;

    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }

    if (strcmp(left->data.name, right->data.name) <= 0) {
        result = left;
        result->ptrnext = merge(left->ptrnext, right);
    } else {
        result = right;
        result->ptrnext = merge(left, right->ptrnext);
    }

    return result;
}

struct person *mergeSort(struct person *head)
{
	if (head == NULL || head->ptrnext == NULL) {
        return head;
    }

    struct person *slow = head;
    struct person *fast = head->ptrnext;

    while (fast != NULL && fast->ptrnext != NULL) {
        slow = slow->ptrnext;
        fast = fast->ptrnext->ptrnext;
    }

    struct person *left = head;
    struct person *right = slow->ptrnext;
    slow->ptrnext = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);

    displaydetails();
}
