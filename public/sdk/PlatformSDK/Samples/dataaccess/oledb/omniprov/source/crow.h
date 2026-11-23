// File: CRow.h
//
//
//	This file contains the definition for the CRow class
//
//	The CRow class does the following:
//
//
//		- Contains the conversion functions for getting the 
//		  data from the string of data for the row into each
//		  CColumn class
//		- Contains the CColumn array which has an element
//		  for each column
//      - Contains the HROW associate with that column
//      - Contains bookmark information
//      - Contains pointer to the starting location of the row
//		  in the file and ending offset
//

#ifndef __CRow_H_
#define __CRow_H_

#define MAX_COLUMNSIZE 255
#define BAD_RECORD_FORMAT -1

struct ATLCOLUMNINFO;

class CRow
{
public:
	char * m_pbStartLoc;
	long m_bmk;
	int m_cbRowSize;
	BYTE * m_pbProxyData;
//	BYTE * m_pbUpdateProxy;  // TODO: pending updates 
	bool m_bRetrieved;

	CRow()
	{
		m_pbStartLoc = NULL;
		m_bmk = 0;   
		m_cbRowSize = 0;
		m_pbProxyData = NULL;
//		m_pbUpdateProxy = NULL;  
		m_bRetrieved = false;
	}

// Methods
	void AllocProxyBuffer(ATLCOLUMNINFO * prgColInfo, int cNumCols);
	void GetProxyData(ATLCOLUMNINFO * pColInfo, ULONG cCols);
	int FetchColumnString(char * pszColData, char * &pPos);
	void StoreInProxy(unsigned int iCol, char * szColumnString, ATLCOLUMNINFO * pColInfo);
	int  Update(ATLCOLUMNINFO * prgColInfo, ULONG cCols);
	int CalculateRowData(ATLCOLUMNINFO * prgColInfo, ULONG cNumCols, bool bAddEOL = false);
    int CreateDefaultRow(ATLCOLUMNINFO *prgColInfo, ULONG cNumCols, bool bAddEOL = false); 
	int CalculateRowDataToDelete(ATLCOLUMNINFO * prgColInfo, ULONG cNumCols, bool bAddEOL=false);
	bool HasEOL(BYTE * pbEOF);
	void AddEOL();
	void AdjustStartLocationForEOL() { m_pbStartLoc +=2; }  // previous line had EOL added 
	                                                       // we need to move this rows starting
	                                                       // location
};

#endif __CROW_H_
