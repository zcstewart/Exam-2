//Exam 2

/* 
 * Filename:        linkedNode.h
 * Purpose:      
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       April 6, 2017, 2:04 PM
 */

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

//Preprocessor Directives
#include <cstdlib>

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

//--------------------------------------------------------------------------//

#endif /* LINKEDNODE_H */



