//Exam 2

/* 
 * Filename:        circularLinkedList.h
 * Purpose:      
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       April 6, 2017, 2:14 PM
 */

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

//Preprocessor Directives
#include <cstdlib>
#include "linkedListADT.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

template <class Type>
class circularLinkedList: public linkedListADT<Type>
{
public:
    void initializeList();
    void destroyList();
    bool isEmptyList();
    void print() const;
    int length() const;
    Type front() const;
    Type back() const;
    bool search(const Type &searchItem) const;
    void insertFirst(const Type &newItem);
    void insertLast(const Type &newItem);
    void deleteNode(const Type &deleteItem);
    void rotate();
    circularLinkedList();
    ~circularLinkedList();
    circularLinkedList(const circularLinkedList<Type> &otherList);
    
    //Overload Assignment Operator = 
    const circularLinkedList<Type>& operator=
    (const circularLinkedList<Type> &otherList);

protected:
    nodeType<Type>* &tail = (this->last);
    
private:
    //Function to make a copy of otherList
    void copyCircularList(const circularLinkedList<Type> &otherList);
    int count;
    nodeType<Type> *first;
    nodeType<Type> *last; 
};

//--------------------------------------------------------------------------//

//Function:     initializeList()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to initialize a list to
//              its default state.
template <class Type>
void circularLinkedList<Type>::initializeList()
{
    circularLinkedList<Type>::destroyList();
}

//--------------------------------------------------------------------------//

//Function:     destroyList()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to destroy a list by 
//              sequentially deleting all of the nodes.
template <class Type>
void circularLinkedList<Type>::destroyList()
{
    nodeType<Type> *temp;
    assert(tail != nullptr);
    while(tail->link != tail) //Until there is one node remaining
    {
        temp = tail->link;       //Assign temp to first node in list
        tail->link = temp->link; //Have tail point to node after temp
        delete temp;             //Delete temp
    }
    //Delete remaining node
    temp = tail;
    temp->link = nullptr;
    this->count = 0;
    delete temp;
}

//--------------------------------------------------------------------------//

//Function:     isEmptyList()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to determine whether the list
//              is empty. The function returns true if tail == nullptr, and
//              false if tail != nullptr.
template <class Type>
bool circularLinkedList<Type>::isEmptyList()
{
    return (tail == nullptr);
}

//--------------------------------------------------------------------------//

//Function:     print()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function to sequentially traverse the 
//              list and print its contents.
template <class Type>
void circularLinkedList<Type>::print() const
{
    nodeType<Type> *current;
    if(length() == 0){}//Nothing to print
    else if(length() == 1)//One item in list, print sole item
    {
        current = tail;
        cout << current->info;
    }
    else
    {   //Start current at first node, print, and continue
        current = tail->link;
        cout << current->info << " ";
        current = current->link;
        //Sequentially print remaining nodes
        while(current != tail->link)
        {
            cout << current->info << " ";
            current = current->link;
        }
    }
    
}

//--------------------------------------------------------------------------//

//Function:     length()
//
//Inputs:       None
//Outputs:      Return type int
//Purpose:      The purpose of this function is to return the length of the
//              current list.
template <class Type>
int circularLinkedList<Type>::length() const
{
    return (this->count);
}

//--------------------------------------------------------------------------//

//Function:     front()
//
//Inputs:       None
//Outputs:      Return type Type
//Purpose:      The purpose of this function is to return the data of type
//              Type contained at the first element in the list.
template <class Type>
Type circularLinkedList<Type>::front() const
{
    assert(tail != nullptr);
    if(tail->link == nullptr)//One item in list, tail is first and last item
    {
        return (tail->info);
    }
    else
    {
        return ((tail->link)->info);//First item to list is pointed to by 
                                    //Tail  
    }
}

//--------------------------------------------------------------------------//

//Function:     back()
//
//Inputs:       None
//Outputs:      Return type Type
//Purpose:      The purpose of this function is to return the data of type
//              Type contained at the last element in the list.
template <class Type>
Type circularLinkedList<Type>::back() const
{
    assert(tail != nullptr);
    return (tail->info);
}

//--------------------------------------------------------------------------//

//Function:     search(const Type &searchItem)
//
//Inputs:       const Type &searchItem
//Outputs:      Return type bool
//Purpose:      The purpose of this function is to sequentially traverse a 
//              list to see if a node contains the value of Type searchItem. 
//              The function returns true if contained in the list, and 
//              returns false otherwise.
template <class Type>
bool circularLinkedList<Type>::search(const Type &searchItem) const
{
    nodeType<Type> *current;
    bool found = false;
    if(tail == nullptr)     //No list exists
    {
        cout << "Cannot search an empty list" << endl;
        return found;
    }
    
    else if(tail->link == nullptr) //One item in list, compare one item
    {
        if(tail->info == searchItem)
        {
            found = true;
        }
        return found;
    }
    
    else
    {
        current = tail->link;       //Current starts at first item
    }
    
    while(current != tail && !found)
    {
        if(current->info == searchItem)//If found, return true
        {
            found = true;
        }
        else
        {
            current = current->link;//Else, advance current
        }
    }
    if(current->info == searchItem)
    {
        found = true;
    }
    return found;
}

//--------------------------------------------------------------------------//

//Function:     insertFirst(const Type &newItem)
//
//Inputs:       const Type &newItem
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to create a new node (newNode)
//              of type nodeType<Type> containing newItem of type Type to
//              insert at the front of a circular linked list.
template <class Type>
void circularLinkedList<Type>::insertFirst(const Type &newItem)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    if(tail == nullptr)     //No list exists, 
    {
        tail = newNode;
        newNode->link = tail;
    }
    else if((tail->link) == tail) //List contains one item
    {
        newNode->link = tail;
        tail->link = newNode;        
    }
    else
    {
        newNode->link = tail->link; //List with multiple items
        tail->link = newNode;
    }
    (this->count)++;
}

//--------------------------------------------------------------------------//

//Function:     insertLast(const Type &newItem)
//
//Inputs:       Type &newItem
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to create a new node (newNode)
//              of type nodeType<Type> containing newItem of type Type to
//              insert at the end of a circular linked list.
template <class Type>
void circularLinkedList<Type>::insertLast(const Type &newItem)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    if(tail == nullptr)
    {//no list
        tail = newNode;
        newNode->link = tail;
    }
    else if((tail->link) == tail)
    {//list has one item
        (newNode->link) = tail;
        (tail->link) = newNode;
        tail = (tail->link);
    }
    else
    {//list has multiple items
        (newNode->link) = (tail->link); 
        (tail->link) = newNode;
        tail = (tail->link);
    }
    (this->count)++;
    
}

//--------------------------------------------------------------------------//

//Function:     deleteNode(const Type &deleteItem)
//
//Inputs:       Type &deleteItem
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to delete a node containing
//              an item deleteItem of type Type from a circular linked list.
template <class Type>
void circularLinkedList<Type>::deleteNode(const Type &deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found = false;
    
    if(tail == nullptr)     //If empty list, output error message
    {
        cout << "Cannot delete from an empty list." << endl;
    }
    else if(length() == 1)   //List with one element
    {
        if ((tail->info) == deleteItem)//Check tail, delete if match
        {
            current = tail;
            current->link = nullptr;
            (this->count) = 0;
            delete current;
            tail = nullptr;
        }
        else
        {
            cout << "This item to be deleted is not in the list." << endl;
        }
    }
    else
    {//Sequentially traverse list, delete if item is found
        int counter = length();
        trailCurrent = tail;
        current = tail->link;
        while(!found && (counter > 0))
        {
            if(current->info == deleteItem)
            {
                found = true;
            }
            else
            {
                counter--;
                trailCurrent = current; //advance
                current = current->link;//advance
            }    
        }
        if (found)
        {
            
            trailCurrent->link = current->link;//trail points to current
            this->count--;                      //decrement count
            if (this->last == current)
            {
                this->last = trailCurrent;     //assign last to trail
            }
            delete current;                    //delete current
               
        }
        else 
        {
            cout << "This item to be deleted is not in the list." << endl; 
        }
        
    }
}

//Function:     rotate()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to rotate the list by
//              sending the first item to the back of the circular linked list
template <class Type>
void circularLinkedList<Type>::rotate()
{
    //Advance tail by one
    tail = (tail->link);
}

//--------------------------------------------------------------------------//

//Function:     circularLinkedList()
//
//Inputs:       None
//Outputs:      None, constructor implementation
//Purpose:      The purpose of this function is to define the constructor
//              implementation of the circular linked list
template <class Type>
circularLinkedList<Type>::circularLinkedList()
{
    (this->count) = 0;
    tail = nullptr;
}

//--------------------------------------------------------------------------//

//Function:     ~circularLinkedList()
//
//Inputs:       None
//Outputs:      None, destructor implementation
//Purpose:      The purpose of this function is to define the destructor
//              implementation for the circularLinkedList<Type> class
template <class Type>
circularLinkedList<Type>::~circularLinkedList()//Call destructor
{
    destroyList();
}

//--------------------------------------------------------------------------//

//Function:     circularLinkedList(const circularLinkedList<Type> &otherList)
//
//Inputs:       circularLinkedList<Type> &otherList
//Outputs:      None, constructor implementation
//Purpose:      The purpose of this function is to define the implementation
//              of the copy constructor for the circularLinkedList<Type> 
//              class.
template <class Type>
circularLinkedList<Type>::circularLinkedList
(const circularLinkedList<Type> &otherList)
{   //Initialize pointers
    this->first = nullptr;
    this->last = nullptr;
    tail = nullptr;
    copyCircularList(otherList);//Copy other list
}

//--------------------------------------------------------------------------//

//Function:     circularLinkedList<Type>& operator=
//              (const circularLinkedList<Type> &otherList)
//
//Inputs:       circularLinkedList<Type> &otherList
//Outputs:      circularLinkedList<Type>&
//Purpose:      The purpose of this function is to overload the assignment
//              operator for the circularLinkedList<Type> class.
template <class Type>
const circularLinkedList<Type>& circularLinkedList<Type>::operator=
(const circularLinkedList<Type> &otherList)
{
    if(this != &otherList)
    {
        copyCircularList(otherList); //Call copyCircularList function
    }
    return *this;
}

//--------------------------------------------------------------------------//

//Function:     copyCircularList(const circularLinkedList<Type> &otherList)
//
//Inputs:       circularLinkedList<Type> &otherList
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to copy otherList, of type
//              circularLinkedList<Type> by creating a new circular linked
//              list.
template <class Type>
void circularLinkedList<Type>::copyCircularList
    (const circularLinkedList<Type> &otherList)
{
    nodeType<Type> *newNode;
    nodeType<Type> *current;
    
    if(tail != nullptr)         //If list isn't empty
    {
        destroyList();          //Initialize list
    }
    if((otherList->tail) == nullptr)    //If other list empty
    {
        tail = nullptr;                 //Create empty list
        (this->count) = 0;
    }
    if(otherList->length() == 1)        //If other list has one object
    {
        current = otherList->tail;      //Set current to other list
        this->count = otherList->count; //Copy count
        
        tail = new nodeType<Type>;      //Create new node, assign to tail
        tail->info = current->info;     //Copy info from current
        tail->link = tail;           //Set link to nullptr
    }
    else                //Other list has multiple objects
    {
        current = (otherList->tail)->link;  //Copy first item in list
        //Note this is (otherList->tail)->link, not otherList->tail
        this->count = otherList->count;     //Copy  count
        tail->link = new nodeType<Type>;
        (tail->link)->info = current->info;
        tail = tail->link;
        current = current->link;
        
        while(current != otherList->tail)   //While not end of middle list
        {
            //Create new node pointed to by tail
            tail->link = new nodeType<Type>; 
            //Insert info into node pointed to by tail
            (tail->link)->info = current->info;
            //Have new node point to tail
            (tail->link)->link = tail;
            tail = tail->link;
            current = current->link;
        }

        //Create new node pointed to by tail
        tail->link = new nodeType<Type>; 
        //Insert info into node pointed to by tail
        (tail->link)->info = current->info;
        //Have new node point to tail
        (tail->link)->link = tail;
        tail = tail->link;
    }
}

//--------------------------------------------------------------------------//

#endif /* CIRCULARLINKEDLIST_H */

