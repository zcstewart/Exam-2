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
        tail->link = nullptr;           //Set link to nullptr
    }
    else                //Other list has multiple objects
    {
        current = (otherList->tail)->link;  //Copy first item in list
        //Note this is (otherList->tail)->link, not otherList->tail
        this->count = otherList->count;     //Copy  count
        
        tail = new nodeType<Type>;      //Create new node, assign to tail
        tail->info = current->info;     //Insert info from current
        tail->link = nullptr;           //Set link to nullptr
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

        tail->link = new nodeType<Type>;
        (tail->link)->info = current->info;
        (tail->link)->link = tail;
        tail = tail->link;
    }
}