#include<iostream>
using namespace std;
///////////////////////////////////
//          STRUCTURE            //
///////////////////////////////////
template<class T>
struct Node
{
   T data;
   struct Node *next;
   struct Node *prev;
};
///////////////////////////////////
//             CLASS             //
///////////////////////////////////
template<class T>
class DoublyCirLL
{
    private:
        struct Node <T> * Head;
        struct Node <T> * Tail;
        int Count;
    public:
        DoublyCirLL();
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
DoublyCirLL<T>::DoublyCirLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}
///////////////////////////////////
template<class T>
void DoublyCirLL<T>::Display()
{
    struct Node <T> * Temp = Head;
    do
    {
        cout<<"|"<<Temp->data<<"|->";
        Temp = Temp->next;
    }while(Temp != Head);
    cout<<"REP\n";
}
///////////////////////////////////
template<class T>
int DoublyCirLL<T>::CountNode()
{
    return Count;
}
///////////////////////////////////
template<class T>
void DoublyCirLL<T>::InsertFirst(T No)
{
    struct Node <T> * newn = NULL;
    newn = new struct Node <T>;
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
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Tail->next = Head;
    Head->prev = Tail;
    Count++;
}
///////////////////////////////////
template<class T>
void DoublyCirLL<T>::InsertLast(T No)
{
    struct Node <T> * newn = NULL;
    newn = new struct Node <T>;
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
        Tail = newn;
    }
    else
    {
        newn->prev = Tail;
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;
    Head->prev = Tail;
    Count++;
}
///////////////////////////////////
template<class T>
void DoublyCirLL<T>::InsertAtPos(T No,int Pos)
{
    struct Node <T> * newn = NULL;
    newn = new struct Node <T>;
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
        struct Node <T> * Temp = Head;
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
    Tail->next = Head;
    Head->prev = Tail;
}
///////////////////////////////////
template<class T>
void DoublyCirLL<T>::DeleteFirst()
{
    if(Count == 0)
    {
        return;
    }
    if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete (Head ->prev);
    }
    Tail->next = Head;
    Head->prev = Tail;
    Count--;
}
///////////////////////////////////
template<class T>
void DoublyCirLL<T>::DeleteLast()
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
        Tail = Tail->prev;
        delete (Tail->next);
    }
    Tail->next = Head;
    Head->prev = Tail;
    Count--;
}
///////////////////////////////////
template<class T>
void DoublyCirLL<T>::DeleteAtPos(int Pos)
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
        struct Node <T> * Temp = Head;
        for(int i = 1; i < (Pos-1); i++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        delete (Temp->next->prev);
        Temp->next->prev = NULL;
        Count--;
    }
    Tail->next = Head;
    Head->prev = Tail;
}
///////////////////////////////////
//              MAIN             //
///////////////////////////////////
int main()
{
    DoublyCirLL <int> obj;
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