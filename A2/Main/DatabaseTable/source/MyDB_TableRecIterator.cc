#ifndef TABLE_REC_ITER_C
#define TABLE_REC_ITER_C

#include "../headers/MyDB_TableRecIterator.h"
#include "../headers/MyDB_PageReaderWriter.h"
#include "../headers/MyDB_PageRecIterator.h"


void MyDB_TableRecIterator :: getNext () {
    pageRecIter->getNext();
}

bool MyDB_TableRecIterator :: hasNext () {
    //current page has next record
    // if(pageRecIter == nullptr) cout<<"pageRecIter is null"<<endl;
    if(parent[pageOffset].getType () == MyDB_PageType :: RegularPage && pageRecIter->hasNext()){     
        return true;
    }
    if(pageOffset == tablePtr->lastPage()){
        return false;
    }
    
    //find the next page that has record
    while(pageOffset < tablePtr->lastPage()){
        pageOffset++;
        pageRecIter = parent[pageOffset].getIterator(recordPtr);
        if(pageRecIter->hasNext()){
            return true;
        }
    }
    return false;
}


MyDB_TableRecIterator :: MyDB_TableRecIterator (MyDB_TableReaderWriter &parent, MyDB_TablePtr tablePtr, MyDB_RecordPtr recordPtr)
    :parent(parent), tablePtr(tablePtr), recordPtr(recordPtr) 
    {
        pageOffset = 0;
        pageRecIter = parent[pageOffset].getIterator(recordPtr);
        
    }




#endif