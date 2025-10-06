//
//  Dynamic_List.cpp
//  Data Structures
//
//  Created by Omar Nouh on 10/4/25.
//

#include "Dynamic_List.hpp"


 const List & List :: operator=(const List & originalList) {
     if (this != originalList) {
         if (this->myCapacity != originalList.myCapacity) {
                 //        delete [] myArray;
             List :: this->~List();
                 //        List = new List();
             this -> mySize = originalList.mySize;
             this -> myCapacity = originalList.myCapacity;
             myArray = new(nothrow) ElementType[myCapacity];
                 //        assert(myArray != 0);
             if (!(this -> myArray)) {
                 cerr << "no memory available, terminating \n";
                 exit(1);
             }
         }
         for (int i = 0; i <  originalList.mySize; i++) {
             this -> myArray[i] = originalList.myArray[i];
         }
     }
     return *this;
 }


// circle obj = new Circle();
~List() {
    delete [] myArray;
    myArray = NULL;
}
