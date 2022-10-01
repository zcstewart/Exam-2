//Exam 2

/* 
 * Filename:        main.cpp
 * Purpose:      
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       April 6, 2017, 1:34 PM
 */

//Preprocessor Directives
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>

#include "linkedListADT.h"
#include "linearLinkedList.h"
#include "circularLinkedList.h"

//Namespace
using namespace std;

//Function Prototypes

void run();
void runLinear();
void runCircular();

//--------------------------------------------------------------------------//
//
//Main Function
//
//Inputs:       int argc, char** argv
//Outputs:      int
//
//Purpose:      Main program file. Other necessary files are included here 
//              in order to be run

int main(int argc, char** argv) 
{
    
    
    runLinear();
    runCircular();
    run();

    //Terminate program upon successful execution
    exit(EXIT_SUCCESS);
}

//--------------------------------------------------------------------------//
//Member Function Definitions

//Function:     run()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to demonstrate the 
//              functionality of the musical chairs game using randomly 
//              generated numbers.
void run()
{
    int numRand1, numRand2, round;
    srand(time(NULL));
    bool table[10] = {false};
    circularLinkedList<int> *chairs;
    chairs = new circularLinkedList<int>;
    linearLinkedList<int> *losers;
    losers = new linearLinkedList<int>;
    
    cout << "Now Implementing Musical Chairs Function!" << endl << endl;
    cout << "This program will simulate a game of musical chairs." << endl;
    cout << "Assume there are ten chairs, numbered one through ten." << endl;
    cout << "Chairs will be randomly removed until there is one chair left!";
    cout << endl << endl;
    
    chairs->insertLast(1);      //Insert to list
    chairs->insertLast(2);
    chairs->insertLast(3);
    chairs->insertLast(4);
    chairs->insertLast(5);
    chairs->insertLast(6);
    chairs->insertLast(7);
    chairs->insertLast(8);
    chairs->insertLast(9);
    chairs->insertLast(10);
    round = 1;
    
    cout << "Initial Seating Chart: ";
    cout << endl;
    chairs->print();            //Print initial list
    cout << endl << endl;
    for(int i = 1; i < 10; i++)
    {
        //Rotate list a random number of times
        numRand2 = ((rand() % 10) + 1);     //Generate random number between
        for(int i = 0; i < numRand2; i++)   //1 and 10 to determine how many
        {                                   //times the list is rotated   
            chairs->rotate();
        }
        
        //Pick random number between 1 and 10 to remove
        numRand1 = ((rand() % 10) + 1);
        while(table[numRand1 - 1] == true) //If picked already, pick another
                                           //number
        {
            numRand1 = ((rand() % 10) + 1);
        }
        
        //Round
        cout << "---------------------------------------------------" << endl;
        cout << "Round " << round << ":" << endl;
        round++;
        
        //Determine loser
        cout << "Player " << numRand1 << " lost." << endl << endl;
        
        //Remove loser
        table[numRand1 - 1] = true;     //Update table
        chairs->deleteNode(numRand1);   //Delete user from chairs list
        losers->insertLast(numRand1);
        
        //Print remaining players
        cout << "Players still in game: " << endl;
        chairs->print();
        cout << endl << endl;
        cout << "Current losers: " << endl;
        losers->print();
        cout << endl << endl;
    }
    //Remaining Player in Circular Linked List is winner!
    cout << "---------------------------------------------------" << endl;
    cout << "Round " << round << ":" << endl;
    cout << "Player " << chairs->front() << " wins!" << endl << endl; 
    cout << "|============================================================|";   
    cout << endl << endl;
}

//--------------------------------------------------------------------------//

//Function:     runLinear()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to demonstrate the 
//              functionality of the linear linked list.
void runLinear()
{
    bool test1, test2;
    linearLinkedList<int> *linearList;
    linearList = new linearLinkedList<int>;
    
    
    //Demonstrate functionality of insertFirst() and insertLast() functions
    //Demonstrate functionality of length function
    
    cout << "|============================================================|";   
    cout << endl << endl;
    cout << "Demonstrate Insertion of LinearLinkedList<Type>: " << endl;
    
    cout << "Length of list: " << linearList->length() << endl;
    linearList->insertFirst(5);
    cout << "List: ";
    linearList->print();
    cout << endl;
    
    cout << "Length of list: " << linearList->length() << endl;
    linearList->insertFirst(4);
    cout << "List: ";
    linearList->print();
    cout << endl;
    
    cout << "Length of list: " << linearList->length() << endl;
    linearList->insertFirst(3);
    cout << "List: ";
    linearList->print();
    cout << endl;
    
    cout << "Length of list: " << linearList->length() << endl;
    linearList->insertFirst(2);
    cout << "List: ";
    linearList->print();
    cout << endl;
    
    cout << "Length of list: " << linearList->length() << endl;
    linearList->insertFirst(1);
    cout << "List: ";
    linearList->print();
    cout << endl;
    
    cout << "Length of list: " << linearList->length() << endl;
    linearList->insertLast(6);
    cout << "List: ";
    linearList->print();
    cout << endl;
    
    cout << "Length of list: " << linearList->length() << endl;
    linearList->insertLast(7);
    cout << "List: ";
    linearList->print();
    cout << endl;
    
    cout << "Length of list: " << linearList->length() << endl;
    linearList->insertLast(8);
    cout << "List: ";
    linearList->print();
    cout << endl;
    
    cout << "Length of list: " << linearList->length() << endl;
    linearList->insertLast(9);
    cout << "List: ";
    linearList->print();
    cout << endl;
    
    cout << "Length of list: " << linearList->length() << endl;
    linearList->insertLast(10);
    cout << "List: ";
    linearList->print();
    cout << endl;
    
    cout << "Length of list: " << linearList->length() << endl;
    cout << endl;
    
    cout << "|============================================================|";   
    cout << endl << endl;
    
    cout << "Demonstrate copy constructor:" << endl << endl;
    
    //Demonstrate functionality of copy constructor, which inherently 
    //demonstrates the functionality of copyLinearList
    linearLinkedList<int> *linearListCopy(linearList);
    cout << "Original List: ";
    linearList->print();
    cout << endl << endl;
    
    cout << "Copied List: ";
    linearListCopy->print();
    cout << endl << endl;
    
    cout << "|============================================================|";   
    cout << endl << endl;

    
    cout << "Demonstrate functionality of rotate():";
    cout << endl << endl;
    
    //Demonstrate functionality of rotate() function
    cout << "After first list rotation: " << endl;
    linearList->rotate();
    linearList->print();
    cout << endl;
    
    cout << "After second list rotation: " << endl;
    linearList->rotate();
    linearList->print();
    cout << endl;
    
    cout << "After third list rotation: " << endl;
    linearList->rotate();
    linearList->print();
    cout << endl;
    
    cout << "After fourth list rotation: " << endl;
    linearList->rotate();
    linearList->print();
    cout << endl;
    
    cout << "After fifth list rotation: " << endl;
    linearList->rotate();
    linearList->print();
    
    cout << endl << endl;
    
    cout << "|============================================================|";   
    cout << endl << endl;
    
    //Demonstrate functionality of search(Type searchItem) function
    
    cout << "Demonstrate valid and invalid searches: ";
    cout << endl << endl;
    
    test1 = linearList->search(5);
    test2 = linearList->search(15);
    if(test1 == true)
    {
        cout << "searchItem (5) is contained in list" << endl;
    }
    else
    {
        cout << "searchItem (5) is not contained in list" << endl;
    }
    if(test2 == true)
    {
        cout << "searchItem (15) is contained in list" << endl;
    }
    else
    {
        cout << "searchItem (15) is not contained in list" << endl;
    }
    
    //Demonstrate functionality of deleteNode() and length() functions
    
    cout << "Demonstrate deleteNode() and length() ";
    cout << "functions.";
    cout << endl << endl;
    
    cout << "|============================================================|";   
    cout << endl << endl;
    
    cout << "Demonstrate delete() function:" << endl << endl;
    
    cout << "Length of list: " << linearList->length() << endl;
    
    cout << "Item to be deleted: 5" << endl;
    
    linearList->deleteNode(5);
    cout << "Length of list: " << linearList->length() << endl;
    cout << "List after deletion: ";
    linearList->print();
    cout << endl;
    
    cout << "Item to be deleted: 4" << endl;
    linearList->deleteNode(4);
    cout << "Length of list: " << linearList->length() << endl;
    cout << "List after deletion: ";
    linearList->print();
    cout << endl;
    
    cout << "Item to be deleted: 3" << endl;
    linearList->deleteNode(3);
    cout << "Length of list: " << linearList->length() << endl;
    cout << "List after deletion: ";
    linearList->print();
    cout << endl;
    
    cout << "Item to be deleted: 2" << endl;
    linearList->deleteNode(2);
    cout << "Length of list: " << linearList->length() << endl;
    cout << "List after deletion: ";
    linearList->print();
    cout << endl;
    
    cout << "Item to be deleted: 1" << endl;
    linearList->deleteNode(1);
    cout << "Length of list: " << linearList->length() << endl;
    cout << "List after deletion: ";
    linearList->print();
    cout << endl;
    
    cout << "Item to be deleted: 6" << endl;
    
    linearList->deleteNode(6);
    cout << "Length of list: " << linearList->length() << endl;
    cout << "List after deletion: ";
    linearList->print();
    cout << endl;
    
    cout << "Item to be deleted: 7" << endl;
    linearList->deleteNode(7);
    cout << "Length of list: " << linearList->length() << endl;
    cout << "List after deletion: ";
    linearList->print();
    cout << endl;
    
    
    cout << "Item to be deleted: 8" << endl;
    linearList->deleteNode(8);
    cout << "Length of list: " << linearList->length() << endl;
    cout << "List after deletion: ";
    linearList->print();
    cout << endl;
    
    cout << "Item to be deleted: 9" << endl;
    linearList->deleteNode(9);
    cout << "Length of list: " << linearList->length() << endl;
    cout << "List after deletion: ";
    linearList->print();
    cout << endl;
    
    cout << "Item to be deleted: 10" << endl;
    linearList->deleteNode(10);
    cout << "Length of list: " << linearList->length() << endl;
    cout << "List after deletion: ";
    linearList->print();
    cout << endl;
    
    cout << endl << endl;
    
    //Restore List
    linearList->insertLast(1);
    linearList->insertLast(2);
    linearList->insertLast(3);
    linearList->insertLast(4);
    linearList->insertLast(5);
    linearList->insertLast(6);
    linearList->insertLast(7);
    linearList->insertLast(8);
    linearList->insertLast(9);
    linearList->insertLast(10);
    
    
    cout << "|============================================================|";   
    cout << endl << endl;
    
    //Demonstrate functionality of destroyList(), which inherently 
    //demonstrates functionality of initializeList()
    
    cout << "Demonstrate destroyList()/initializeList():";
    cout << endl << endl;
    
    cout << "Current List: ";
    linearList->print();
    cout << endl;
    cout << "Current length: " << linearList->length() << endl;
    
    linearList->destroyList();
    cout << endl;
    cout << "List Deleted!" << endl << endl;
    
    cout << "Current List: ";
    linearList->print();
    cout << endl;
    cout << "Current length: " << linearList->length() << endl;
    cout << endl;
    
    //Delete from empty list
    cout << "Attempting to delete from empty list..." << endl;
    linearList->deleteNode(1);
    cout << endl;
        
}

//--------------------------------------------------------------------------//

//Function:     runCircular()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to demonstrate the 
//              functionality of the circular linked list
void runCircular()
{
    bool test1, test2;
    circularLinkedList<int> *circularList;
    circularList = new circularLinkedList<int>;
    
    cout << "|============================================================|";   
    cout << endl << endl;
    
    //Demonstrate functionality of insertFirst() and insertLast() functions
    //Demonstrate functionality of length function
    cout << "Demonstrate Insertion of CircularLinkedList<Type>: ";
    cout << endl << endl;
    
    cout << "Length of list: " << circularList->length() << endl;
    circularList->insertFirst(5);
    cout << "List: ";
    circularList->print();
    cout << endl;
    
    cout << "Length of list: " << circularList->length() << endl;
    circularList->insertFirst(4);
    cout << "List: ";
    circularList->print();
    cout << endl;
    
    cout << "Length of list: " << circularList->length() << endl;
    circularList->insertFirst(3);
    cout << "List: ";
    circularList->print();
    cout << endl;
    
    cout << "Length of list: " << circularList->length() << endl;
    circularList->insertFirst(2);
    cout << "List: ";
    circularList->print();
    cout << endl;
    
    cout << "Length of list: " << circularList->length() << endl;
    circularList->insertFirst(1);
    cout << "List: ";
    circularList->print();
    cout << endl;
    
    cout << "Length of list: " << circularList->length() << endl;
    circularList->insertLast(6);
    cout << "List: ";
    circularList->print();
    cout << endl;
    
    cout << "Length of list: " << circularList->length() << endl;
    circularList->insertLast(7);
    cout << "List: ";
    circularList->print();
    cout << endl;
    
    cout << "Length of list: " << circularList->length() << endl;
    circularList->insertLast(8);
    cout << "List: ";
    circularList->print();
    cout << endl;
    
    cout << "Length of list: " << circularList->length() << endl;
    circularList->insertLast(9);
    cout << "List: ";
    circularList->print();
    cout << endl;
    
    cout << "Length of list: " << circularList->length() << endl;
    circularList->insertLast(10);
    cout << "List: ";
    circularList->print();
    cout << endl;
    cout << "Length of list: " << circularList->length() << endl;
    cout << endl;
 
    //Demonstrate functionality of copy constructor, which inherently 
    //demonstrates the functionality of copyCircularList
    
    
    
    cout << "|============================================================|";   
    cout << endl << endl;
    circularLinkedList<int> *circularListCopy(circularList);
    cout << "Original List: ";
    circularList->print();
    cout << endl << endl;
    
    cout << "Copied List: ";
    circularListCopy->print();
    cout << endl << endl;
    
    cout << "|============================================================|";   
    cout << endl << endl;
    
    cout << "Demonstrate rotate() function";
    cout << endl << endl;
    
    //Demonstrate functionality of rotate() function
    cout << "After first list rotation: " << endl;
    circularList->rotate();
    circularList->print();
    cout << endl;
    
    cout << "After second list rotation: " << endl;
    circularList->rotate();
    circularList->print();
    cout << endl;
    
    cout << "After third list rotation: " << endl;
    circularList->rotate();
    circularList->print();
    cout << endl;
    
    cout << "After fourth list rotation: " << endl;
    circularList->rotate();
    circularList->print();
    cout << endl;
    
    cout << "After fifth list rotation: " << endl;
    circularList->rotate();
    circularList->print();
    
    cout << endl << endl;
    
    cout << "|============================================================|";   
    cout << endl << endl;
    
    //Demonstrate functionality of search(Type searchItem) function
    
    cout << "Demonstrate valid and invalid searches: ";
    cout << endl << endl;
    
    test1 = circularList->search(5);
    test2 = circularList->search(15);
    if(test1 == true)
    {
        cout << "searchItem (5) is contained in list" << endl;
    }
    else
    {
        cout << "searchItem (5) is not contained in list" << endl;
    }
    if(test2 == true)
    {
        cout << "searchItem (15) is contained in list" << endl;
    }
    else
    {
        cout << "searchItem (15) is not contained in list" << endl;
    }
    cout << endl << endl;
    
    cout << "|============================================================|";   
    cout << endl << endl;
    //Demonstrate functionality of deleteNode() and length() functions
    
    cout << "Demonstrate deleteNode() and length() functions:";
    cout << endl << endl;
    
    cout << "List: ";
    circularList->print();
    cout << endl;
    cout << "Length of list: " << circularList->length() << endl << endl;
    
    cout << "Item to be deleted: 5" << endl;
    circularList->deleteNode(5);
    cout << "New length of list: " << circularList->length() << endl;
    cout << "List after deletion: ";
    circularList->print();
    cout << endl << endl;
    
    cout << "Item to be deleted: 4" << endl;
    circularList->deleteNode(4);
    cout << "New length of list: " << circularList->length() << endl;
    cout << "List after deletion: ";
    circularList->print();
    cout << endl << endl;
    
    cout << "Item to be deleted: 3" << endl;
    circularList->deleteNode(3);
    cout << "New length of list: " << circularList->length() << endl;
    cout << "List after deletion: ";
    circularList->print();
    cout << endl << endl;
    
    cout << "Item to be deleted: 2" << endl;
    circularList->deleteNode(2);
    cout << "New length of list: " << circularList->length() << endl;
    cout << "List after deletion: ";
    circularList->print();
    cout << endl << endl;
    
    cout << "Item to be deleted: 1" << endl;
    circularList->deleteNode(1);
    cout << "New length of list: " << circularList->length() << endl;
    cout << "List after deletion: ";
    circularList->print();
    cout << endl << endl;
    
    cout << "Item to be deleted: 6" << endl;
    
    circularList->deleteNode(6);
    cout << "New length of list: " << circularList->length() << endl;
    cout << "List after deletion: ";
    circularList->print();
    cout << endl << endl;
    
    cout << "Item to be deleted: 7" << endl;
    circularList->deleteNode(7);
    cout << "New length of list: " << circularList->length() << endl;
    cout << "List after deletion: ";
    circularList->print();
    cout << endl << endl;
    
    
    cout << "Item to be deleted: 8" << endl;
    circularList->deleteNode(8);
    cout << "New length of list: " << circularList->length() << endl;
    cout << "List after deletion: ";
    circularList->print();
    cout << endl << endl;
    
    cout << "Item to be deleted: 9" << endl;
    circularList->deleteNode(9);
    cout << "New length of list: " << circularList->length() << endl;
    cout << "List after deletion: ";
    circularList->print();
    cout << endl << endl;
    
    cout << "Item to be deleted: 10" << endl;
    circularList->deleteNode(10);
    cout << "New length of list: " << circularList->length() << endl;
    cout << "List after deletion: ";
    circularList->print();
    cout << endl << endl;

    //Initialize List
    circularList->insertLast(1);
    circularList->insertLast(2);
    circularList->insertLast(3);
    circularList->insertLast(4);
    circularList->insertLast(5);
    circularList->insertLast(6);
    circularList->insertLast(7);
    circularList->insertLast(8);
    circularList->insertLast(9);
    circularList->insertLast(10);
    
    
    //Demonstrate functionality of destroyList(), which inherently 
    //demonstrates functionality of initializeList()
    
    cout << "|============================================================|";   
    cout << endl << endl;
    
    cout << "Demonstrate destroyList()/initializeList():";
    cout << endl << endl;
    
    cout << "Current List: ";
    circularList->print();
    cout << endl;
    cout << "Current length: " <<  circularList->length() << endl;
    
    circularList->destroyList();
    cout << endl;
    cout << "List Deleted!" << endl << endl;
    
    cout << "Current List: ";
    circularList->print();
    cout << endl;
    cout << "Current length: " <<  circularList->length() << endl;
    cout << endl;
    
    //Delete from empty list
    cout << "Attempting to delete from empty list..." << endl;
    circularList->deleteNode(1);
    
    cout << endl;
    
    cout << "|============================================================|";   
    cout << endl << endl;  
    
}

//--------------------------------------------------------------------------//