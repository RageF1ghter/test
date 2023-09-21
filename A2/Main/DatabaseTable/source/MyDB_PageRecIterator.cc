#ifndef PAGE_REC_ITER_C
#define PAGE_REC_ITER_C

#include "../headers/MyDB_PageRecIterator.h"
#include "../headers/MyDB_PageReaderWriter.h"

void MyDB_PageRecIterator :: getNext () {
    //get the next record from page
    cout<<"pager rec iter get next"<<endl;
    if(hasNext()){
        
        PageOverlay *pageOverlayPtr = (PageOverlay *) parent->getBytes();
        recordPtr->fromBinary(&(pageOverlayPtr->bytes[recOffset]));
        //update the record offset
        recOffset += recordPtr->getBinarySize();
    }
    
}

bool MyDB_PageRecIterator :: hasNext () {
    // access the raw bytes in this page
    cout<<"pager rec iter has next"<<endl;
    PageOverlay *pageOverlayPtr = (PageOverlay *) parent->getBytes();
    
    if(recOffset < pageOverlayPtr->numBytesUsed){
        return true;
    }else{
      return false;  
    }
}

MyDB_PageRecIterator :: MyDB_PageRecIterator (MyDB_PageHandle parent, MyDB_RecordPtr recordPtr)
    :parent(parent), recordPtr(recordPtr) 
    {
        recOffset = 0;
    }




#endif