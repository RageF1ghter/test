
#ifndef TABLE_RW_C
#define TABLE_RW_C

#include <fstream>
#include "MyDB_PageReaderWriter.h"
#include "MyDB_TableReaderWriter.h"
#include "MyDB_TableRecIterator.h"

using namespace std;

MyDB_TableReaderWriter :: MyDB_TableReaderWriter (MyDB_TablePtr tablePtr, MyDB_BufferManagerPtr bufferMgr) {
	this->tablePtr = tablePtr;
	this->bufferMgr = bufferMgr;
	//brand new table
	if(this->tablePtr->lastPage() == -1) {
		// cout<<"new table"<<endl;
		tablePtr->setLastPage(0);
		pageReaderWriterPtr = make_shared<MyDB_PageReaderWriter>(*this, 0);
		pageReaderWriterPtr->clear();
	}
}



MyDB_PageReaderWriter MyDB_TableReaderWriter :: operator [] (size_t i) {
	while(i > tablePtr->lastPage()) {
		tablePtr->setLastPage(tablePtr->lastPage() + 1);
		pageReaderWriterPtr = make_shared<MyDB_PageReaderWriter>(*this, tablePtr->lastPage());
		pageReaderWriterPtr->clear();
	}
	MyDB_PageReaderWriter thisPage(*this, i);
	return thisPage;
}

MyDB_RecordPtr MyDB_TableReaderWriter :: getEmptyRecord () {
	return make_shared<MyDB_Record>(tablePtr->getSchema());
}

MyDB_PageReaderWriter MyDB_TableReaderWriter :: last () {
	return (*this)[tablePtr->lastPage()];
}


void MyDB_TableReaderWriter :: append (MyDB_RecordPtr) {
}

void MyDB_TableReaderWriter :: loadFromTextFile (string) {
}

// return iterator over this table records
MyDB_RecordIteratorPtr MyDB_TableReaderWriter :: getIterator (MyDB_RecordPtr iterateIntoMe) {
	return make_shared<MyDB_TableRecIterator>(*this, tablePtr, iterateIntoMe);
}

void MyDB_TableReaderWriter :: writeIntoTextFile (string) {
}

#endif

