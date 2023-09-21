#ifndef TABLE_REC_ITER_H
#define TABLE_REC_ITER_H

#include <memory>
#include "MyDB_RecordIterator.h"
#include "MyDB_TableReaderWriter.h"

class MyDB_TableRecIterator;

typedef shared_ptr <MyDB_TableRecIterator> MyDB_TableRecIteratorPtr;

//derived from MyDB_RecordIterator
//This class is used to iterate through the records in the table
class MyDB_TableRecIterator : public MyDB_RecordIterator {

public:
    void getNext ();
    bool hasNext ();

    //constructor and destructor
    MyDB_TableRecIterator (MyDB_TableReaderWriter &parent,MyDB_TablePtr tablePtr, MyDB_RecordPtr recordPtr);

    ~MyDB_TableRecIterator () {};

private:
    MyDB_TableReaderWriter &parent;
    MyDB_TablePtr tablePtr;
    MyDB_RecordPtr recordPtr;
    MyDB_RecordIteratorPtr pageRecIter;
    
    int pageOffset;

};

#endif