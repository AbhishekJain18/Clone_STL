#include<iostream>
using namespace std;
///////////////////////////////////
//          STRUCTURE            //
///////////////////////////////////
template <class T>
struct Node
{
   T data;
   struct Node *next;
};
///////////////////////////////////
//             CLASS             //
///////////////////////////////////
template <class T>
class Queue
{
    private:
        struct Node<T> * Head;
        int Count;
    public:
        Queue();
        void Display();
        int CountNode();
        void Enqueue(T);
        void Dequeue();
};
///////////////////////////////////
template <class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}
///////////////////////////////////
template <class T>
void Queue<T>::Display()
{
    struct Node<T> *Temp = Head;
    while(Temp != NULL)
    {
        cout<<"|"<<Temp->data<<"|->";
        Temp = Temp->next;
    }
    cout<<"NULL\n";
}
///////////////////////////////////
template <class T>
int Queue<T>::CountNode()
{
    return Count;
}
///////////////////////////////////
template <class T>
void Queue<T>::Enqueue(T No)
{
    struct Node<T> * newn = NULL;
    newn = new struct Node<T>;
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
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
        Temp->next = newn;
    }
    Count++;
}
///////////////////////////////////
template <class T>
void Queue<T>::Dequeue()
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
        Head = Temp->next;
        delete Temp;
    }
    Count--;
}
///////////////////////////////////
//              MAIN             //
///////////////////////////////////
int main()
{
    Queue <int>obj;
    int iRet = 0;

    obj.Enqueue(11);
    obj.Enqueue(21);
    obj.Enqueue(51);
    obj.Enqueue(101);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;

    obj.Dequeue();
    obj.Dequeue();
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;
    
	return 0;
 }