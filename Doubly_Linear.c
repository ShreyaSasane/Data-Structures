#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        (*first )-> prev = newn;
        *first = newn;
    }
}
void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        newn -> prev = temp;
    }
}
void DeleteFirst(PPNODE first)
{
    if(*first == NULL)      //LL IS EMPTY
    {
        return;
    }
    else if((*first) -> next == NULL)           //LL CONTAINS ATLEAST ONE NODE
    {
        free(*first);
        *first = NULL;
    }
    else        // LL CONTAINS MORE THAN ONE NODE
    {
        *first = (*first) -> next;
        free((*first) -> prev);
        (*first) -> prev = NULL;
    }
}
void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        free(temp -> next);
        temp -> next = NULL;
    }
    
}
void InsertAtPos(PPNODE first, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCount = 0, i = 0;

    if((pos < 1) && (pos > iCount+1))
    {
        printf("Invalid Input\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = *first;

        for(i = 1; i < pos - 1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        newn -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;
    }
}
void DeleteAtPos(PPNODE first, int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int iCount = 0, i = 0;

    if((pos < 1) && (pos > iCount+1))
    {
        printf("Invalid Input\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iCount+1)
    {
        DeleteLast(first);
    }
    else
    {
    
        temp = *first;

        for(i = 1; i < pos - 1; i++)
        {
            temp = temp -> next;
        }

        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;      // $

        free(target);
    }
}

int Count(PPNODE first)
{
    int iCount = 0;

    while((*first) != NULL)
    {
        iCount++;
        (*first) = (*first) -> next;
    }
    return iCount;
}

void Display(PNODE first)
    {
        printf(" NULL <=> ");

        while(first != NULL)
        {
            printf("| %d | <=> ",first->data);
            first = first -> next;
        }
    
        printf(" NULL\n");
}

int main()
{

   PNODE head = NULL;
    
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    printf("-------------------------------------------------------------\n");
    printf("---------------- Doubly Linear LinkedList -------------------\n");
    printf("-------------------------------------------------------------\n\n");
    
    while(1)
    {
        printf("-------------------------------------------------------------\n");
        printf("------------------ Please select the option -----------------\n");
        printf("-------------------------------------------------------------\n");
        printf("1 : Insert new node at first position\n");
        printf("2 : Insert new node at last position\n");
        printf("3 : Insert new node at given position\n");
        printf("4 : Delete the node from first position\n");
        printf("5 : Delete the node from last position\n");
        printf("6 : Delete the node from given position\n");
        printf("7 : Display all elements of LinkedList\n");
        printf("8 : Count number of nodes of LinkedList\n");
        printf("0 : Terminate the application\n");
        
        printf("-------------------------------------------------------------\n");

        scanf("%d",&iChoice);

        if(iChoice == 1)
        {
            printf("Enter the data that you want to insert : \n");
            scanf("%d",&iValue);

            InsertFirst(&head,iValue);
        }
        else if(iChoice == 2)
        {
            printf("Enter the data that you want to insert : \n");
            scanf("%d",&iValue);

            InsertLast(&head,iValue);
        }
        else if(iChoice == 3)
        {
            printf("Enter the data that you want to insert : \n");
            scanf("%d",&iValue);

            printf("Enter the position at which you want to insert new node : \n");
            scanf("%d",&iPos);

            InsertAtPos(&head,iValue,iPos);
        }
        else if(iChoice == 4)
        {
            printf("Deleting the first element from LinkedList\n");

            DeleteFirst(&head);
        }
        else if(iChoice == 5)
        {
            printf("Deleting the last element from LinkedList\n");

            DeleteLast(&head);
        }
        else if(iChoice == 6)
        {
            printf("Deleting the element from given position from LinkedList\n");

            printf("Enter the position from which you want to delete the node : \n");
            scanf("%d",&iPos);

            DeleteAtPos(&head,iPos);
        }
        else if(iChoice == 7)
        {
            printf("Elements of the LinkedList are : \n");
            Display(head);
        }
        else if(iChoice == 8)
        {
            iRet = Count(&head);
            printf("Number of elements in the LinkedList are : %d\n",iRet);
        }
        else if(iChoice == 0)
        {
            printf("Thank you for using our application\n");
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
        printf("-------------------------------------------------------------\n");
    }

    return 0;

}