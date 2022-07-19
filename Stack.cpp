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
class Stack
{
    private:
        struct Node<T> *Head;
        int Count;
    public:
        Stack();
        void Display();
        int CountNode();
        void Push(T);
        void Pop();
};
///////////////////////////////////
template<class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}
///////////////////////////////////
template<class T>
void Stack<T>::Display()
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
template<class T>
int Stack<T>::CountNode()
{
    return Count;
}
///////////////////////////////////
template<class T>
void Stack<T>::Push(T No)
{
    struct Node<T> *newn = NULL;
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
        struct Node<T> *Temp = Head;
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
    Count++;
}
///////////////////////////////////
template<class T>
void Stack<T>::Pop()
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
        struct Node<T> *Temp = Head;
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
//              MAIN             //
///////////////////////////////////
int main()
{
    Stack <int>obj;
    int iRet = 0;

    obj.Push(11);
    obj.Push(21);
    obj.Push(51);
    obj.Push(101);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;

    obj.Pop();
    obj.Pop();
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<endl;
    
	return 0;
 }