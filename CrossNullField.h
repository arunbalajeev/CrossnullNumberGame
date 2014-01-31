//================================================
// Cross and Null
//
//================================================

#ifndef CROSS_NULL_FIELD
#define CROSS_NULL_FIELD

// the length of one side (the field is square)
// some code regions are bound hard to 3 number so it's impossible to change it blindly
#define FIELD_SIDE_LEN			4

#include <windows.h>

// enum describes what the cell contains
enum CELL_SIGN
{
	CELL_EMPTY = 0,
	CELL_NULL = 1,
	CELL_CROSS = 2,
	CELL_ONE=3,
	CELL_TWO = 4,
	CELL_THREE = 5,
	CELL_FOUR=6,
	CELL_FIVE = 7,
	CELL_SIX = 8,
	CELL_SEVEN=9,
	CELL_EIGHT= 10,
	CELL_NINE = 11,
	CELL_ZERO=12
};

struct CCell
{
	CELL_SIGN contents;
	int value;		// the "value" of the cell. the most valuable cells are the cells
					// which are positioned at the intersection of the largest number of lines
					// (so the central cell is the most valuable cell)

	// the cell's coordinates are determined by the left up corner and the right lower corner
	POINT leftup;
	POINT rightlow;

	CCell() : contents(CELL_EMPTY), value(0) {}
};

class CCrossNullField
{
	CCell sq[FIELD_SIDE_LEN][FIELD_SIDE_LEN];         //the field
	CCell noLeft[5][1];
	CCell noRight[5][1];
	HDC hdc_;

	static HBITMAP hBmpE_;
	static HBITMAP hBmpC_;
	static HBITMAP hBmpN_;
	static HBITMAP hBmpONE_;
	static HBITMAP hBmpTWO_;
	static HBITMAP hBmpTHREE_;
	static HBITMAP hBmpFOUR_;
	static HBITMAP hBmpFIVE_;
	static HBITMAP hBmpSIX_;
	static HBITMAP hBmpSEVEN_;
	static HBITMAP hBmpEIGHT_;
	static HBITMAP hBmpNINE_;
    static HBITMAP hBmpZERO_;
	static HBITMAP hBmpONEC_;
	static HBITMAP hBmpTWOC_;
	static HBITMAP hBmpTHREEC_;
	static HBITMAP hBmpFOURC_;
	static HBITMAP hBmpFIVEC_;
	static HBITMAP hBmpSIXC_;
	static HBITMAP hBmpSEVENC_;
	static HBITMAP hBmpEIGHTC_;
	static HBITMAP hBmpNINEC_;
    static HBITMAP hBmpZEROC_;
	bool end_;

	void setCellsValues();
	bool determineWinner(CELL_SIGN type);

	void setCross();
	void drawBitmap(int x, int y, HBITMAP hBitmap);
	void getNeedPosition(int* pi, int* pj, CELL_SIGN type);

public:
	CCrossNullField();
	int number;
	int lastx;
	float resultCPU;
	float resultUSER;
	int lasty;
	int check;
	int keys[10];
	int counter;
	int rowCount[FIELD_SIDE_LEN];
	int cScore[FIELD_SIDE_LEN][FIELD_SIDE_LEN];
	int uScore[FIELD_SIDE_LEN][FIELD_SIDE_LEN];
	void setHdc(HDC h) { hdc_ = h; }
	void repaint();
	void clearField();
	void setNull(POINT pos);
	void selectNumber(POINT pos);
	void releaseHdc(HWND hwnd) { ReleaseDC(hwnd, hdc_); }
	
	static void setBmpE(HBITMAP h) { hBmpE_ = h; }
	static void setBmpC(HBITMAP h) { hBmpC_ = h; }
	static void setBmpN(HBITMAP h) { hBmpN_ = h; }
	static void setBmpONE(HBITMAP h) { hBmpONE_ = h; }
	static void setBmpTWO(HBITMAP h) { hBmpTWO_ = h; }
	static void setBmpTHREE(HBITMAP h) { hBmpTHREE_ = h; }
	static void setBmpFOUR(HBITMAP h) { hBmpFOUR_ = h; }
	static void setBmpFIVE(HBITMAP h) { hBmpFIVE_ = h; }
	static void setBmpSIX(HBITMAP h) { hBmpSIX_ = h; }
	static void setBmpSEVEN(HBITMAP h) { hBmpSEVEN_ = h; }
	static void setBmpEIGHT(HBITMAP h) { hBmpEIGHT_ = h; }
	static void setBmpNINE(HBITMAP h) { hBmpNINE_ = h; }
	static void setBmpZERO(HBITMAP h) { hBmpZERO_ = h; }
	static void setBmpONEC(HBITMAP h) { hBmpONEC_ = h; }
	static void setBmpTWOC(HBITMAP h) { hBmpTWOC_ = h; }
	static void setBmpTHREEC(HBITMAP h) { hBmpTHREEC_ = h; }
	static void setBmpFOURC(HBITMAP h) { hBmpFOURC_ = h; }
	static void setBmpFIVEC(HBITMAP h) { hBmpFIVEC_ = h; }
	static void setBmpSIXC(HBITMAP h) { hBmpSIXC_ = h; }
	static void setBmpSEVENC(HBITMAP h) { hBmpSEVENC_ = h; }
	static void setBmpEIGHTC(HBITMAP h) { hBmpEIGHTC_ = h; }
	static void setBmpNINEC(HBITMAP h) { hBmpNINEC_ = h; }
	static void setBmpZEROC(HBITMAP h) { hBmpZEROC_ = h; }
	
	static void deleteBmpC() { DeleteObject(hBmpC_); } 
	static void deleteBmpN() { DeleteObject(hBmpN_); } 
	static void deleteBmpE() { DeleteObject(hBmpE_); } 
    static void deleteBmpONE() { DeleteObject(hBmpONE_); } 
	static void deleteBmpTWO() { DeleteObject(hBmpTWO_); } 
	static void deleteBmpTHREE() { DeleteObject(hBmpTHREE_); } 
    static void deleteBmpFOUR() { DeleteObject(hBmpFOUR_); } 
	static void deleteBmpFIVE() { DeleteObject(hBmpFIVE_); } 
	static void deleteBmpSIX() { DeleteObject(hBmpSIX_); } 
    static void deleteBmpSEVEN() { DeleteObject(hBmpSEVEN_); } 
	static void deleteBmpEIGHT() { DeleteObject(hBmpEIGHT_); } 
	static void deleteBmpNINE() { DeleteObject(hBmpNINE_); } 
	static void deleteBmpZERO() { DeleteObject(hBmpZERO_); } 
	static void deleteBmpONEC() { DeleteObject(hBmpONEC_); } 
	static void deleteBmpTWOC() { DeleteObject(hBmpTWOC_); } 
	static void deleteBmpTHREEC() { DeleteObject(hBmpTHREEC_); } 
    static void deleteBmpFOURC() { DeleteObject(hBmpFOURC_); } 
	static void deleteBmpFIVEC() { DeleteObject(hBmpFIVEC_); } 
	static void deleteBmpSIXC() { DeleteObject(hBmpSIXC_); } 
    static void deleteBmpSEVENC() { DeleteObject(hBmpSEVENC_); } 
	static void deleteBmpEIGHTC() { DeleteObject(hBmpEIGHTC_); } 
	static void deleteBmpNINEC() { DeleteObject(hBmpNINEC_); } 
	static void deleteBmpZEROC() { DeleteObject(hBmpZEROC_); } 
};

#endif
