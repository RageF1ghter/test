
#ifndef PAGE_RW_C
#define PAGE_RW_C

#include "MyDB_PageReaderWriter.h"

void MyDB_PageReaderWriter :: clear () {
	pageOverlayPtr->numBytesUsed = 0;
	pageOverlayPtr->pageType = MyDB_PageType :: RegularPage;
	pageHandler->wroteBytes();
}

MyDB_PageType MyDB_PageReaderWriter :: getType () {
	return MyDB_PageType :: RegularPage;
}

MyDB_RecordIteratorPtr MyDB_PageReaderWriter :: getIterator (MyDB_RecordPtr) {
	return nullptr;
}

void MyDB_PageReaderWriter :: setType (MyDB_PageType) {
}

bool MyDB_PageReaderWriter :: append (MyDB_RecordPtr) {
	return true;
}

MyDB_PageReaderWriter :: MyDB_PageReaderWriter(MyDB_TableReaderWriter &parent, int pageOffset) {
	bufferMgr = parent.getBufferMgr();
	pageHandler = bufferMgr->getPage(parent.getTablePtr(), pageOffset);
	pageOverlayPtr = (PageOverlay *) pageHandler->getBytes();
}

#endif
