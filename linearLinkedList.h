//Exam 2

/* 
 * Filename:        linearLinkedList.h
 * Purpose:      
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       April 6, 2017, 2:14 PM
 */

#ifndef LINEARLINKEDLIST_H
#define LINEARLINKEDLIST_H

//Preprocessor Directives
#include "linkedListADT.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

template <class Type>
class linearLinkedList: public linkedListADT<Type>
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
    
    //Default Constructor
    linearLinkedList();
    
    //Default Destructor
    ~linearLinkedList();
    
    //Copy Constructor
    linearLinkedList(const linearLinkedList<Type> &otherList);
    
    //Overload Assignment Operator = 
    const linearLinkedList<Type>& operator=
    (const linearLinkedList<Type> &otherList);

    
private:
    void copyLinearList(const linearLinkedList<Type> &otherList);
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
void linearLinkedList<Type>::initializeList()
{
    destroyList();
}

//--------------------------------------------------------------------------//

//Function:     destroyList()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to destroy a list by 
//              sequentially deleting all of the nodes.
template <class Type>
void linearLinkedList<Type>::destroyList()
{
    nodeType<Type> *temp;
    
    //While not an empty list
    while(this->first != nullptr)
    {
        //set temp to first, advance first, delete temp
        temp = (this->first);
        this->first = (this->first)->link;
        delete temp;
    }
    //set last pointer to null
    this->last = nullptr;
    this->count = 0;
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
bool linearLinkedList<Type>::isEmptyList()
{
    //check first pointer
    return ((this->first) == nullptr);
}

//--------------------------------------------------------------------------//

//Function:     print()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function to sequentially traverse the 
//              list and print its contents.
template <class Type>
void linearLinkedList<Type>::print() const
{
    //Create node
    nodeType<Type> *current;
    //Set to first
    current = this->first;
    //While list isn't empty
    while(current != nullptr)
    {
        //Print contents, advance list
        cout << current->info << " ";
        current = current->link;
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
int linearLinkedList<Type>::length() const
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
Type linearLinkedList<Type>::front() const
{
    //Assert that list isn't empty
    assert(this->first != nullptr);
    //Return info at first
    
    return ((this->first)->info);
}

//--------------------------------------------------------------------------//

//Function:     back()
//
//Inputs:       None
//Outputs:      Return type Type
//Purpose:      The purpose of this function is to return the data of type
//              Type contained at the last element in the list.
template <class Type>
Type linearLinkedList<Type>::back() const
{
    //Assert that list isn't empty
    assert(this->last != nullptr);
    //Return info at last
    return ((this->last)->info);
}

//--------------------------------------------------------------------------//

//Function:     search(const Type &searchItem)
//
//Inputs:       Type &searchItem
//Outputs:      Return type bool
//Purpose:      The purpose of this function is to sequentially traverse a 
//              list to see if a node contains the value of Type searchItem. 
//              The function returns true if contained in the list, and 
//              returns false otherwise.
template <class Type>
bool linearLinkedList<Type>::search(const Type &searchItem) const
{
    //Create new node, bool variable
    nodeType<Type> *current;
    bool found = false;
    //Set new node to first
    current = this->first;
    
    //While not end of list, and not found
    while(current != nullptr && !found)
    {
        //If info matches
        if(current->info == searchItem)
        {
            found = true;   //Update found
        }
        else
        {
            current = current->link;    //Advance list
        }
    }
    return found;
}

//--------------------------------------------------------------------------//

//Function:     insertFirst(const Type &newItem)
//
//Inputs:       Type &newItem
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to create a new node (newNode)
//              of type nodeType<Type> containing newItem of type Type to
//              insert at the front of a linear linked list.
template <class Type>
void linearLinkedList<Type>::insertFirst(const Type &newItem)
{
    nodeType<Type> *newNode;        //Create node
    newNode = new nodeType<Type>;   
    newNode->info = newItem;        //Insert newItem
    newNode->link = this->first;    //Point node to first
    this->first = newNode;          //Change first pointer to node
    (this->count)++;                //Increment count
    
    if(this->last == nullptr)       //If only item in list
    {
        this->last = newNode;       //Set last to newNode
    }
}

//--------------------------------------------------------------------------//

//Function:     insertLast(const Type &newItem)
//
//Inputs:       Type &newItem
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to create a new node (newNode)
//              of type nodeType<Type> containing newItem of type Type to
//              insert at the end of a linear linked list.
template <class Type>
void linearLinkedList<Type>::insertLast(const Type &newItem)
{
    nodeType<Type> *newNode;                //Create node
    newNode = new nodeType<Type>;
    newNode->info = newItem;                //Insert newItem
    newNode->link = nullptr;                //Point node to null
    
    if(this->first == nullptr)              //If empty list
    {
        this->first = newNode;              //Point first to newNode
        this->last = newNode;               //Point last to newNode
        this->count++;                      //Increment count
    }
    else
    {
        (this->last)->link = newNode;       //Last node points to newNode
        this->last = newNode;               //Last points to newNode
        this->count++;                      //Increment count
    }
}

//--------------------------------------------------------------------------//

//Function:     deleteNode(const Type &deleteItem)
//
//Inputs:       Type &deleteItem
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to delete a node containing
//              an item deleteItem of type Type from a linear linked list.
template <class Type>
void linearLinkedList<Type>::deleteNode(const Type &deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;
    
     if(this->first == nullptr)     //If empty list, output error message
     {
        cout << "Cannot delete from an empty list." << endl;
     }
    else
    {
        if ((this->first)->info == deleteItem)     //If item is first of list
        {
            current = this->first;
            this->first = (this->first)->link;
            this->count--;
            if (this->first == nullptr)
                this->last = nullptr;
            delete current;
        }
        else 
        {
            found = false;
            trailCurrent = this->first;
            
            current = (this->first)->link;
            
            while (current != nullptr && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                {
                    found = true;
                }
            }//end while
            if (found)
            {
                trailCurrent->link = current->link;
                this->count--;
                if (this->last == current)
                {
                    this->last = trailCurrent; 
                }
                delete current;
            }
            else 
            {
                cout << "This item to be deleted is not in the list." << endl; 
            }
        }// end else
    }//end else
}

//--------------------------------------------------------------------------//

//Function:     rotate()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to rotate the list by
//              sending the first item of the list to the back of the list,
//              and adjusting first and last accordingly.
template <class Type>
void linearLinkedList<Type>::rotate()
{
    ((this->last)->link) = this->first;
    (this->first) = (this->first)->link;
    (this->last) = (this->last)->link;
    ((this->last)->link) = nullptr;
}

//--------------------------------------------------------------------------//

//Function:     linearLinkedList()
//
//Inputs:       
//Outputs:      None, constructor implementation
//Purpose:      The purpose of this function is to define the constructor
//              implementation for the linearLinkedList<Type> class.
template <class Type>
linearLinkedList<Type>::linearLinkedList()
{
    this->first = nullptr;
    this->last = nullptr;
    this->count = 0;
}

//--------------------------------------------------------------------------//

//Function:     ~linearLinkedList()
//
//Inputs:       None
//Outputs:      None, destructor implementation
//Purpose:      The purpose of this function is to define the destructor
//              implementation for the linearLinkedList<Type> class.
template <class Type>
linearLinkedList<Type>::~linearLinkedList()
{
    destroyList();
}

//--------------------------------------------------------------------------//

//Function:     linearLinkedList(const linearLinkedList<Type> &otherList)
//
//Inputs:       const linearLinkedList<Type> &otherList
//Outputs:      None, constructor implementation
//Purpose:      The purpose of this function is to define the implementation
//              of the copy constructor for the linearLinkedList<Type> 
//              class.
template <class Type>
linearLinkedList<Type>::linearLinkedList
                        (const linearLinkedList<Type> &otherList)
{
    (this->first) = nullptr;
    copyLinearList(otherList);
}

//--------------------------------------------------------------------------//

//Function:     linearLinkedList<Type>& operator=
//              (const linearLinkedList<Type> &otherList)
//
//Inputs:       const linearLinkedList<Type> &otherList
//Outputs:      linearLinkedList<Type>&
//Purpose:      The purpose of this function is to overload the assignment
//              operator for the linearLinkedList<Type> class.
template <class Type>
const linearLinkedList<Type>& linearLinkedList<Type>::operator=
      (const linearLinkedList<Type> &otherList)
{
    if(this != &otherList)
    {
        copyLinearList(otherList);
    }
    return *this;
}

//--------------------------------------------------------------------------//

//Function:     copyLinearList
//              (const linearLinkedList<Type> &otherList)
//
//Inputs:       const linearLinkedList<Type> &otherList
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to copy otherList, of type
//              linearLinkedList<Type> by creating a new linear linked
//              list.
template <class Type>
void linearLinkedList<Type>::copyLinearList
     (const linearLinkedList<Type> &otherList)
{
    nodeType<Type> *newNode;
    //pointer to create a node
    nodeType<Type> *current;
    //pointer to traverse the list
    
    if (this->first != nullptr) //if the list is not empty, make it empty
        destroyList();
    
    if (otherList->first == nullptr)//otherList is empty
    {
        this->first = nullptr;
        this->last = nullptr;
        this->count = 0;
    }
    else 
    {
        current = otherList->first;
        //current points to the list to be copied
        
        this->count = otherList->count;
        
        //copy the first node and create the node
        this->first = new nodeType<Type>;
        (this->first)->info = current->info;
        //copy the info
        (this->first)->link = nullptr;
        //set the link field of the node to NULL
        this->last = this->first;
        //make last point to the first node
        current = current->link;
        //make current point to the next node
        
        while (current != nullptr)//copy the remaining list
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;
            
            (this->last)->link = newNode;
            //attach newNode after last
            this->last = newNode;
            //make last point to the actual last node
            current = current->link;
            //make current point to the next node
            
        }//end while         
    }//end else
}

//--------------------------------------------------------------------------//

#endif /* LINEARLINKEDLIST_H */

