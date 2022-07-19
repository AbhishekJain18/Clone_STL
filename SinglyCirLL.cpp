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
};
///////////////////////////////////
//             CLASS             //
///////////////////////////////////
template<class T>
class SinglyCirLL
{
    private:
        struct Node<T> * Head;
        struct Node<T> * Tail;
        int Count;
    public:
        SinglyCirLL();
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
SinglyCirLL<T>::SinglyCirLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}
///////////////////////////////////
template<class T>
void SinglyCirLL<T>::Display()
{
    struct Node<T> * Temp = Head;
    do
    {
        cout<<"|"<<Temp->data<<"|->";
        Temp = Temp->next;
    }while(Temp != Head);
    cout<<"REP\n";
}
///////////////////////////////////
template<class T>
int SinglyCirLL<T>::CountNode()
{
    return Count;
}
///////////////////////////////////
template<class T>
void SinglyCirLL<T>::InsertFirst(T No)
{
    struct Node<T> * newn = NULL;
    newn = new struct Node<T> ;
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
    if(Count == 0)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;
    Count++;
}
///////////////////////////////////
template<class T>
void SinglyCirLL<T>::InsertLast(T No)
{
    struct Node<T> * newn = NULL;
    newn = new struct Node<T> ;
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
    if(Count == 0)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;
    Count++;
}
///////////////////////////////////
template<class T>
void SinglyCirLL<T>::InsertAtPos(T No,int Pos)
{
    struct Node<T> * newn = NULL;
    newn = new struct Node<T> ;
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
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
        Temp->next = newn;
        Tail->next = Head;
        Count++;
    }
}
///////////////////////////////////
template<class T>
void SinglyCirLL<T>::DeleteFirst()
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
        delete Tail->next;
        Tail->next = Head;
    }
    Tail->next = Head;
    Count--;
}
///////////////////////////////////
template<class T>
void SinglyCirLL<T>::DeleteLast()
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
        struct Node<T> * Temp = Head;
        while(Temp->next->next != Head)
        {
            Temp = Temp->next;
        }
        delete Tail;
        Tail = Temp;
    }
    Tail->next = Head;
    Count--;
}
///////////////////////////////////
template<class T>
void SinglyCirLL<T>::DeleteAtPos(int Pos)
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
        struct Node<T> * DelTemp = Head;
        for(int i = 1; i < (Pos-1); i++)
        {
            Temp = Temp->next;
        }
        DelTemp = Temp->next;
        Temp->next = DelTemp->next;
        delete DelTemp;
        Tail->next = Head;
        Count--;
    }
}
///////////////////////////////////
//              MAIN             //
///////////////////////////////////
int main()
{
    SinglyCirLL <int>obj;
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