import java.util.Scanner;

class node
{
    public int data;
    public node next;
}

class SinglyCLL
{
    private node first;
    private node last;
    private int iCount;

    public SinglyCLL()
    {
        first = null;
        last = null;
        iCount = 0;
    }
    
    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(); 
        
        newn.data = no;
        newn.next = null;

        if((first == null) || (last == null))
        {
            first = newn;
            last  = newn;
        }
        else 
        {
            newn.next = first;
            first = newn;
            last.next = newn; 
        }
        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;

        newn = new node();

        newn.data = no;
        newn.next = null;

        if((first == null) || (last == null))
        {
            first = newn;
            last = newn;
        }
        else 
        {
            last.next = newn;
            last = newn;
            last.next = first;
        }
        iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null || last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            last.next = first;
        }

        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if(first == null || last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            temp = first;

            while (temp.next != last) 
            {   
                temp = temp.next;
            }
            last = temp;
            last.next = first;
        }

        iCount--;
    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;
        int iCnt = 0;

        if(first == null || last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            temp = first;

            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;

            iCount--;
        }
    }

    public void InsertAtPos(int no, int pos)
    {
        node newn = null;
        node temp = null;
        int iCnt = 0;

        newn = new node();

        newn.data = no;
        newn.next = null;

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount+1)
        {
            InsertLast(no);
        }
        else
        {
            temp = first;

            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;
        }

         iCount++;
        
    }

    public void Display()
    {
        node temp = null;

        temp = first;

        do
        {
            System.out.print("| "+temp.data+" | -> ");
            temp = temp.next;

        }while(temp != first);

        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

class Singly_Circular
{
    public static void main(String A[])
    {
        Scanner sobj =  new Scanner(System.in);

        DoublyCLL dobj = new DoublyCLL();
        int iRet = 0, iChoice = 0, iValue = 0, iPos = 0;

        System.out.println("-------------------------------------------");
        System.out.println("--------Singly Circular Linked List--------");
        System.out.println("-------------------------------------------");

        while (true) 
        {
            System.out.println("-------------------------------------------");
            System.out.println("--------Please Select The Option-----------");
            System.out.println("-------------------------------------------");

            System.out.println("1 : Insert new node at first position\n");
            System.out.println("2 : Insert new node at last position\n");
            System.out.println("3 : Insert new node at given position\n");
            System.out.println("4 : Delete the node from first position\n");
            System.out.println("5 : Delete the node from last position\n");
            System.out.println("6 : Delete the node from given position\n");
            System.out.println("7 : Display all elements of LinkedList\n");
            System.out.println("8 : Count number of nodes of LinkedList\n");
            System.out.println("0 : Terminate the application\n");

            iChoice  = sobj.nextInt();

            if(iChoice == 1)
            {
                System.out.println("Enter the data that you want to insert \n");
                iValue = sobj.nextInt();
                dobj.InsertFirst(iValue);
            }
            else if(iChoice == 2)
            {
                System.out.println("Enter the data that you want to insert \n");
                iValue = sobj.nextInt();
                dobj.InsertLast(iValue);
            }
            else if(iChoice == 3)
            {
                System.out.println("Enter the data that you want to insert \n");
                iValue = sobj.nextInt();

                System.out.println("Enter the data that you want to insert \n");
                iPos = sobj.nextInt();

                dobj.InsertAtPos(iValue, iPos);
            }
            else if(iChoice == 4)
            {
                System.out.println("Deleting the first node \n");
                
                dobj.DeleteFirst();
            }
            else if(iChoice == 5)
            {
                System.out.println("Deleting the last node \n");
            
                dobj.DeleteLast();
            }
            else if(iChoice == 6)
            {
                System.out.println("Deleting the element from the given position \n");
                iPos = sobj.nextInt();
                dobj.DeleteAtPos(iPos);
            }
            else if(iChoice == 7)
            {
                System.out.println("Displaying the elements of the linked list\n");
                dobj.Display();
            }
            else if(iChoice == 8)
            {
                dobj.Display();
                iRet = dobj.Count();
                System.out.println("Number of elements in the linked list \n"+iRet);
            }
            else if(iChoice == 0)
            {
                System.out.println("Thank you for using our application \n");
                break;
            }
            else
            {
                System.out.println("Invalid Choice \n");
            }
            System.out.println("\n-----------------------------------------------\n");
        }
    }
}