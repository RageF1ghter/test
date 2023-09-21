#ifndef PAGE_REC_ITER_H
#define PAGE_REC_ITER_H

#include <memory>
#include "MyDB_RecordIterator.h"
#include "MyDB_PageReaderWriter.h"
#include "../../BufferMgr/headers/MyDB_PageHandle.h"
using namespace std;

class MyDB_PageRecIterator;

typedef shared_ptr <MyDB_PageRecIterator> MyDB_PageRecIteratorPtr;

//derived from MyDB_RecordIterator
class MyDB_PageRecIterator : public MyDB_RecordIterator {

public:
    void getNext ();
    bool hasNext ();

    //constructor and destructor
    MyDB_PageRecIterator (MyDB_PageHandle parent,MyDB_RecordPtr recordPtr);

    ~MyDB_PageRecIterator () {};
private:
    MyDB_PageHandle parent;
    MyDB_RecordPtr recordPtr;
    int recOffset;   //the offset of the next record
};
#endif