#include<iostream>
using namespace std;
///////////////////////////////////
//          STRUCTURE            //
///////////////////////////////////
template<class T>
struct Node
{
   int data;
   struct Node *next;
   struct Node *prev;
};
///////////////////////////////////
//             CLASS             //
///////////////////////////////////
template<class T>
class DoublyLirLL
{
    private:
        struct Node<T> * Head;
        int Count;
    public:
        DoublyLirLL();
        void Display();
        int CountNode();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};
///////////////////////////////////
template<class T>
DoublyLirLL<T>::DoublyLirLL()
{
    Head = NULL;
    Count = 0;
}
///////////////////////////////////
template<class T>
void DoublyLirLL<T>::Display()
{
    struct Node<T> * Temp = Head;
    while(Temp != NULL)
    {
        cout<<"|"<<Temp->data<<"|->";
        Temp = Temp->next;
    }
    cout<<"NULL\n";
}
///////////////////////////////////
template<class T>
int DoublyLirLL<T>::CountNode()
{
    return Count;
}
///////////////////////////////////
template<class T>
void DoublyLirLL<T>::InsertFirst(T No)
{
    struct Node<T> * newn = NULL;
    newn = new struct Node<T> ;
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
    if(Count == 0)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Count++;
}
///////////////////////////////////
template<class T>
void DoublyLirLL<T>::InsertLast(T No)
{
    struct Node<T> * newn = NULL;
    newn = new struct Node<T> ;
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
    if(Count == 0)
    {
        Head = newn;
    }
    else
    {
        struct Node<T> * Temp = Head;
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        newn->prev = Temp;
        Temp->next = newn;
    }
    Count++;
}
///////////////////////////////////
template<class T>
void DoublyLirLL<T>::InsertAtPos(T No,int Pos)
{
    struct Node<T> * newn = NULL;
    newn = new struct Node<T> ;
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
    if(Pos < 1 || Pos >(Count + 1))
    {
        return;
    }
    else if(Pos == 1)
    {
        InsertFirst(No);
    }
    else if(Pos == (Count + 1))
    {
        InsertLast(No);
    }
    else
    {
        struct Node<T> * Temp = Head;
        for(int i = 1; i < (Pos-1); i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next->prev = newn;
        newn->prev = Temp;
        Temp->next = newn;
        Count++;
    }

}
///////////////////////////////////
template<class T>
void DoublyLirLL<T>::DeleteFirst()
{
    if(Count == 0)
    {
        return;
    }
    if(Count == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        Head = Head->next;
        delete (Head ->prev);
        Head->prev = NULL;
    }
    Count--;
}
///////////////////////////////////
template<class T>
void DoublyLirLL<T>::DeleteLast()
{
    if(Count == 0)
    {
        return;
    }
    if(Count == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct Node<T> * Temp = Head;
        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        delete Temp->next;
        Temp->next = NULL;
    }
    Count--;
}
///////////////////////////////////
template<class T>
void DoublyLirLL<T>::DeleteAtPos(int Pos)
{
    if(Count == 0)
    {
        return;
    }
    if(Pos < 1 || Pos > Count)
    {
        return;
    }
    else if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct Node<T> * Temp = Head;
        for(int i = 1; i < (Pos-1); i++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        delete (Temp->next->prev);
        Temp->next->prev = NULL;
        Count--;
    }
}
///////////////////////////////////
//              MAIN             //
///////////////////////////////////    
int main()
{
    DoublyLirLL <int>obj;
    int iRet = 0;

    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(51);
    obj.InsertLast(101);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;

    obj.InsertAtPos(1,3);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;

    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;
    
	return 0;
 }