//Exam 2

/* 
 * Filename:        linkedListADT.h
 * Purpose:      
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       April 6, 2017, 2:06 PM
 */

#ifndef LINKEDLISTADT_H
#define LINKEDLISTADT_H

//Preprocessor Directives
#include <cstdlib>
#include <iostream>
#include <cassert>
#include "linkedNode.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

template <class Type>
class linkedListADT
{
    public:
        virtual void initializeList() = 0;
        virtual void destroyList() = 0;
        virtual bool isEmptyList() = 0;
        virtual void print() const = 0;
        virtual int length() const = 0;
        virtual Type front() const = 0;
        virtual Type back() const = 0;
        virtual bool search(const Type &searchItem) const = 0;
        virtual void insertFirst(const Type &newItem) = 0;
        virtual void insertLast(const Type &newItem) = 0;
        virtual void deleteNode(const Type &deleteItem) = 0;
        virtual void rotate() = 0;

    private:
        int count;
        nodeType<Type> *first;
        nodeType<Type> *last;            
};


//--------------------------------------------------------------------------//


#endif /* LINKEDLISTADT_H */

