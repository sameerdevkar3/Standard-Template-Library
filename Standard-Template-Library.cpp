////////////////////////  Header files //////////////////////////////////////////

#include<iostream>
using namespace std;

// Structure of " Singly Linked List "

template <typename T>
struct NodeS
{
    T Data;
    NodeS *Next;
};

// Structure of " Doubly Linked List "

template <typename T>
struct NodeD
{
    T Data;
    NodeD *Next;
    NodeD *Prev;
};

// Structure of " Stack "

template <typename T>
struct NodeST
{
    T Data;
    NodeST *Next;
};

// Structure of " Queue "

template <typename T>
struct NodeQ
{
    T Data;
    NodeQ *Next;
};

//////////////////////////////  Class    /////////////////////////////////////////

// Class of Singly Linear Linked List

template <class T>
class SinglyLL
{
    private:
        NodeS <T>* First;
        int Size;

    public:
        SinglyLL();
        ~SinglyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

// Class of Singly Circular Linked List

template <class T>
class SinglyCL
{
private:
    NodeS<T> * First;
    NodeS<T> * Last;
    int Size;
public:
    SinglyCL();
    ~SinglyCL();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

// Class of Doubly Linear Linked List

template <class T>
class DoublyLL
{
private:
    NodeD <T>* First;
    int Size;
public:
    DoublyLL();
    ~DoublyLL();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

// Class of Doubly Circular Linked List 

template <class T>
class DoublyCL
{
private:
    NodeD <T>* First;
    NodeD <T>* Last;
    int Size;
public:
    DoublyCL();
    ~DoublyCL();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

// Class of Stack 

template <class T>
class Stack
{
private:
    NodeST <T>* First;
    int Size;
public:
    Stack();
    ~Stack();
    void Display();
    int Count();
    void Push(T);
    T Pop();
};

// Class of Queue

template <class T>
class Queue
{
private:
    NodeQ <T> * First;
    int Size;
public:
    Queue();
    ~Queue();
    void Display();
    int Count();
    void Enqueue(T);
    T Dequeue();
};

///////////////////////// Defination of Function ////////////////////////////////


//////////////////////////////////////////////////////////
//
//  Function Name : SinglyLL
//  Description   : It is used to initialise characteristcs
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
    Size = 0;
}

//////////////////////////////////////////////////////////
//
//  Function Name : ~SinglyLL
//  Description   : It is used to deallocate memory
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
SinglyLL<T>::~SinglyLL()
{
    delete First;
}

//////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : It is used to insert node at First
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    NodeS <T>* NewNodeS = new NodeS<T>;

    NewNodeS->Data = No;
    NewNodeS->Next = NULL;

    if(First == NULL)
    {
        First = NewNodeS;
    }
    else
    {
        NewNodeS->Next = First;
        First = NewNodeS;
    }
    Size++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : It is used to insert node at last
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    NodeS<T> * NewNodeS = new NodeS<T>;

    NewNodeS->Data = No;
    NewNodeS->Next = NULL;

    if(First == NULL)
    {
        First = NewNodeS;
    }
    else
    {
        NodeS<T> * Temp = First;

        while(Temp->Next != NULL)
        {
            Temp = Temp->Next;
        }
        Temp->Next = NewNodeS;
    }
    Size++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Input         : Integer
//  Description   : It is used to insert node at any position
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertAtPos(T No,int iPos)
{
    if((iPos < 1) || (iPos > Size))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == Size+1)
    {
        InsertLast(No);
    }
    else
    {
        int i = 0;
        NodeS<T> * Temp = First;
        NodeS<T> * NewNodeS = NULL;
        NewNodeS = new NodeS<T>;

        NewNodeS->Data = No;
        NewNodeS->Next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            Temp = Temp->Next;
        }

        NewNodeS->Next = Temp->Next;
        Temp->Next = NewNodeS;
        Size++;
    }
}

//////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : It is used to delete node from First
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }

    if(First->Next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeS <T>* Temp = First;
        First = First->Next;
        delete Temp;
    }
    Size--;
}

//////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : It is used to delete node from last
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteLast()
{
    NodeS<T> *Temp = First;

    if(First == NULL)
    {
        return;
    }
    
    if(First->Next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(Temp->Next->Next != NULL)
        {
            Temp = Temp->Next;
        }
        delete Temp->Next;
        Temp->Next = NULL;
    }
    Size--;
}

//////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : It is used to delete node desired position
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > Size))
    {
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Size)
    {
        DeleteLast();
    }
    else
    {
        int iCnt = 0;
        NodeS<T> * Targeted = NULL;
        NodeS<T> * Temp = First;

        for(iCnt = 1;iCnt < iPos-1;iCnt++)
        {
            Temp = Temp->Next;
        }
        Targeted = Temp->Next;
        Temp->Next = Targeted->Next;
        delete Targeted;
        Size--;
    }
}

//////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : It is used to display nodes 
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::Display()
{
    NodeS<T> * Temp = First;

    while(Temp != NULL)
    {
        cout<<Temp->Data<<"\t";
        Temp = Temp->Next;
    }
    cout<<"\n";
}

//////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : It is used to count nodes
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::Count(){return Size;}

//////////////////////////////////////////////////////////
//
//  Function Name : SinglyCL
//  Description   : It is used to initialise characteristcs
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    Size = 0;
}

//////////////////////////////////////////////////////////
//
//  Function Name : ~SinglyCL
//  Description   : It is used to deallocate memory
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
SinglyCL<T>::~SinglyCL()
{
    delete First;
    delete Last;
}

//////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : It is used to insert node at First
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    NodeS<T> * NewNodeS = new NodeS<T>;
    NewNodeS->Data = No;
    NewNodeS->Next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = NewNodeS;
        Last = NewNodeS;
    }
    else
    {
        NewNodeS->Next = First;
        First = NewNodeS;
    }
    Last->Next = First;
    Size++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : It is used to insert node at last
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    NodeS<T> * NewNodeS = new NodeS<T>;
    NewNodeS->Data = No;
    NewNodeS->Next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = NewNodeS;
        Last = NewNodeS;
    }
    else
    {
        Last->Next = NewNodeS;
        Last = NewNodeS;
    }
    Last->Next = First;
    Size++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Input         : Integer
//  Description   : It is used to insert node at any position
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertAtPos(T No,int iPos)
{
    if((iPos < 1) || (iPos > Size+1))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == Size+1)
    {
        InsertLast(No);
    }
    else
    {
        NodeS<T> * NewNodeS = new NodeS<T>;
        NodeS<T> * Temp = First;
        NewNodeS->Data = No;
        NewNodeS->Next = NULL;

        for(int i = 1; i < iPos - 1; i++)
        {
            Temp = Temp->Next;
        }

        NewNodeS->Next = Temp->Next;
        Temp->Next = NewNodeS;
        Size++;
    }
}

//////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : It is used to delete node from First
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((First == NULL) || (Last == NULL))
    {
        return;
    }

    if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        NodeS<T> * Temp = First;
        First = First->Next;
        delete Temp;
        Last->Next = First;
    }
    Size--;
}

//////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : It is used to delete node from last
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if((First == NULL) || (Last == NULL))
    {
        return;
    }

    if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        NodeS<T> * Temp = First;
        while(Temp->Next != Last)
        {
            Temp = Temp->Next;
        }
        delete Temp->Next;
        Last = Temp;
        Last->Next = First;
    }
    Size--;
}

//////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : It is used to delete node desired position
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > Size))
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Size)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * Temp = First;
        NodeS<T> * Targeted = NULL;
        for(int i = 1; i < iPos - 1; i++)
        {
            Temp = Temp->Next;
        }
        Targeted = Temp->Next;
        Temp->Next = Targeted->Next;
        delete Targeted;
        Size--;
    }
}

//////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : It is used to display nodes 
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::Display()
{
    if((First == NULL) || (Last == NULL))
    {
        return;
    }
    NodeS<T> * Temp = First;
    do
    {
        cout<<"| "<<Temp->Data<<" | -> ";
        Temp = Temp->Next;
    }while(Temp != Last->Next);
    cout<<endl;
}

//////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : It is used to count nodes
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::Count(){return Size;}

//////////////////////////////////////////////////////////
//
//  Function Name : DoublyLL
//  Description   : It is used to initialise characteristcs
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    Size = 0;
}

//////////////////////////////////////////////////////////
//
//  Function Name : ~DoublyLL
//  Description   : It is used to deallocate memory
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
DoublyLL<T>::~DoublyLL()
{
    delete First;
}

//////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : It is used to insert node at First
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    NodeD <T>* NewNodeD = new NodeD<T>;
    NewNodeD->Data = No;
    NewNodeD->Next = NULL;
    NewNodeD->Prev = NULL;

    if(First == NULL)
    {
        First = NewNodeD;
    }
    else
    {
        NewNodeD->Next = First;
        First->Prev = NewNodeD;
        First = NewNodeD;
    }
    Size++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : It is used to insert node at last
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    NodeD <T>* NewNodeD = new NodeD<T>;
    NewNodeD->Data = No;
    NewNodeD->Next = NULL;
    NewNodeD->Prev = NULL;

    if(First == NULL)
    {
        First = NewNodeD;
    }
    else
    {
        NodeD <T>* Temp = First;
        while(Temp->Next != NULL)
        {
            Temp = Temp->Next;
        }
        NewNodeD->Prev = Temp;
        Temp->Next = NewNodeD;
    }
    Size++; 
}

//////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Input         : Integer
//  Description   : It is used to insert node at any position
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertAtPos(T No,int iPos)
{
    if((iPos < 1) || (iPos > Size+1))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == Size+1)
    {
        InsertLast(No);
    }
    else
    {
        NodeD <T>* NewNodeD = new NodeD<T>;
        NodeD <T>* Temp = First;
        NewNodeD->Data = No;
        NewNodeD->Next = NULL;
        NewNodeD->Prev = NULL;

        for(int i = 1;i < iPos - 1; i++)
        {
            Temp = Temp->Next;
        }
        NewNodeD->Next = Temp->Next;
        NewNodeD->Prev = Temp;
        Temp->Next = NewNodeD;
        Size++;
    }
}

//////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : It is used to delete node from First
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }

    if(First->Next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->Next;
        delete First->Prev;
        First->Prev = NULL;
    }
    Size--;
}

//////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : It is used to delete node from last
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(First == NULL)
    {
        return;
    }

    if(First->Next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeD <T>* Temp = First;
        while(Temp->Next->Next != NULL)
        {
            Temp = Temp->Next;
        }
        delete Temp->Next;
        Temp->Next = NULL;
    }
    Size--;
}

//////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : It is used to delete node desired position
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > Size))
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Size)
    {
        DeleteLast();
    }
    else
    {
        NodeD <T>* Temp = First;
        for(int i = 1;i < iPos - 1; i++)
        {
            Temp = Temp->Next;
        }
        Temp->Next = Temp->Next->Next;
        delete Temp->Next->Prev;
        Temp->Next->Prev = Temp;
        Size--;
    }
}

//////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : It is used to display nodes 
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::Display()
{
    NodeD <T>* Temp = First;
    while(Temp != NULL)
    {
        cout<<"| "<<Temp->Data<<" | -> ";
        Temp = Temp->Next;
    }
    cout<<endl;
}

//////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : It is used to count nodes
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::Count(){return Size;}

//////////////////////////////////////////////////////////
//
//  Function Name : DoublyCL
//  Description   : It is used to initialise characteristcs
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    Size = 0;
}

//////////////////////////////////////////////////////////
//
//  Function Name : ~DoublyCL
//  Description   : It is used to deallocate memory
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
DoublyCL<T>::~DoublyCL()
{
    First = NULL;
    Last = NULL;
    Size = 0;
}

//////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : It is used to insert node at First
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    NodeD <T>* NewNodeD = new NodeD <T>;

    NewNodeD->Data = No;
    NewNodeD->Next = NULL;
    NewNodeD->Prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = NewNodeD;
        Last = NewNodeD;
    }
    else
    {
        NewNodeD->Next = First;
        First->Prev = NewNodeD;
        First = NewNodeD;
    }
    Last->Next = First;
    First->Prev = Last;
    Size++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : It is used to insert node at last
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    NodeD <T>* NewNodeD = new NodeD<T>;

    NewNodeD->Data = No;
    NewNodeD->Next = NULL;
    NewNodeD->Prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = NewNodeD;
        Last = NewNodeD;
    }
    else
    {
        Last->Next = NewNodeD;
        NewNodeD->Prev = Last;
        Last = NewNodeD;
    }

    Last->Next = First;
    First->Prev = Last;
    Size++;    
}

//////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Input         : Integer
//  Description   : It is used to insert node at any position
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertAtPos(T No,int iPos)
{
    if((iPos < 1) || (iPos > (Size+1)))
    {
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == Size+1)
    {
        InsertLast(No);
    }
    else
    {
        NodeD <T>* NewNodeD = new NodeD <T>;
        NodeD <T>* Temp = First;

        NewNodeD->Data = No;
        NewNodeD->Next = NULL;
        NewNodeD->Prev = NULL;

        for(int i = 1;i < iPos -1; i++)
        {
            Temp = Temp->Next;
        }
        
        NewNodeD->Next = Temp->Next;
        NewNodeD->Next->Prev = NewNodeD;
        Temp->Next = NewNodeD;
        NewNodeD->Prev = Temp;
        Size++;
    }
}

//////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : It is used to delete node from First
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->Next;
        delete First->Prev;
        First->Prev = Last;
        Last->Next = First;
    }
    Size--;
}

//////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : It is used to delete node from last
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->Prev;
        delete First->Prev;
        First->Prev = Last;
        Last->Next = First;
    }
    Size--;    
}

//////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : It is used to delete node desired position
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > Size))
    {
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Size)
    {
        DeleteLast();
    }
    else
    {
        NodeD <T>* Temp = First;

        for(int i = 1; i < iPos-1; i++)
        {
            Temp = Temp->Next;
        }

        Temp->Next = Temp->Next->Next;
        delete Temp->Next->Prev;
        Temp->Next->Prev = Temp;

        Size--;
    }
}

//////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : It is used to display nodes 
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::Display()
{
    if((First == NULL) || (Last == NULL))
    {
        return;
    }

    NodeD <T>* Temp = First;
    do
    {
        cout<<"| "<<Temp->Data<<" |->";
        Temp = Temp->Next;
    }while(Temp != Last->Next);
    cout<<"\n";
}

//////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : It is used to count nodes
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::Count(){return Size;}

//////////////////////////////////////////////////////////
//
//  Function Name : Stack
//  Description   : It is used to allocate memory
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    Size = 0;
}

//////////////////////////////////////////////////////////
//
//  Function Name : ~Stack
//  Description   : It is used to deallocate memory
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
Stack<T>::~Stack()
{
    delete First;
}

//////////////////////////////////////////////////////////
//
//  Function Name : Push
//  Description   : It is used to push value into stack
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Push(T No)
{
    NodeST <T>* NewNodeST = new NodeST <T>;
    NewNodeST->Data = No;
    NewNodeST->Next = NULL;

    if(First == NULL)
    {
        First = NewNodeST;
    }
    else
    {
        NewNodeST->Next = First;
        First = NewNodeST;
    }
    Size++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : Pop
//  Description   : It is used to pop value from stack
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
T Stack<T>::Pop()
{
    if(First == NULL)
        return -1;

    T No = First->Data;
    
    if(First->Next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeST <T>* Temp = First;
        First = First->Next;
        delete Temp;
    }
    Size--;
    return No;
}

//////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : It is used to display stack
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Display()
{
    NodeST <T>* Temp = First;
    while(Temp != NULL)
    {
        cout<<"| "<<Temp->Data<<" |"<<endl;
        Temp = Temp->Next;
    }
    cout<<endl;
}

//////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : It is used to count value in stack
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
int Stack<T>::Count(){return Size;}

//////////////////////////////////////////////////////////
//
//  Function Name : Queue
//  Description   : It is used to allocate memory
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
Queue<T>::Queue()
{
    First = NULL;
    Size = 0;
}

//////////////////////////////////////////////////////////
//
//  Function Name : ~Queue
//  Description   : It is used to deallocate memory
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
Queue<T>::~Queue()
{
    delete First;
}

//////////////////////////////////////////////////////////
//
//  Function Name : Enqueue
//  Description   : It is used to insert value into queue
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Enqueue(T No)
{
    NodeQ <T> * NewNodeQ = new NodeQ <T>;
    NewNodeQ->Data = No;
    NewNodeQ->Next = NULL;

    if(First == NULL)
    {
        First = NewNodeQ;
    }
    else
    {
        NodeQ <T> * Temp = First;
        while(Temp->Next != NULL)
        {
            Temp = Temp->Next;
        }
        Temp->Next = NewNodeQ;
    }
    Size++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : Deueue
//  Description   : It is used to pop value from stack
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
T Queue<T>::Dequeue()
{
    if(First == NULL)
    {
        return -1;
    }

    T No = First->Data;
    
    if(First->Next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeQ <T> * Temp = First;
        First = First->Next;
        delete Temp;
    }
    Size--;
    return No;
}

//////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : It is used to display queue
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Display()
{
    NodeQ <T> * Temp = First;
    while(Temp != NULL)
    {
        cout<<"| "<<Temp->Data<<" |"<<endl;
        Temp = Temp->Next;
    }
    cout<<endl;
}

//////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : It is used to count value in stack
//  Author        : Devkar Sameer Ganesh
//  Date          : 20/11/2021
//
//////////////////////////////////////////////////////////

template <class T>
int Queue<T>::Count(){return Size;}
