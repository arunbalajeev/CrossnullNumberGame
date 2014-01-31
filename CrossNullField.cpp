//================================================
// Cross and Null
// Arun Balajee V,2012
//================================================

#include "CrossNullField.h"
#include "resource.h"

HBITMAP CCrossNullField::hBmpE_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpC_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpN_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpONE_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpTWO_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpTHREE_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpFOUR_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpFIVE_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpSIX_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpSEVEN_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpEIGHT_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpNINE_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpZERO_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpONEC_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpTWOC_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpTHREEC_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpFOURC_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpFIVEC_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpSIXC_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpSEVENC_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpEIGHTC_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpNINEC_ = (HBITMAP)0;
HBITMAP CCrossNullField::hBmpZEROC_ = (HBITMAP)0;

CCrossNullField::CCrossNullField(): end_(false) 
{
	setCellsValues();

	// determine coordinates of all cells
	int y = 50, x;
	int q=20,p;
	counter=0;
	resultCPU=0;resultUSER=0;
	//MessageBox(NULL, "NUMBER assigned constructor", "The ehd", MB_OK);
	for(int k=0;k<10;k++)
	{
		keys[k]=0;
	}
	for(int k=0;k<FIELD_SIDE_LEN;k++)
	{
		rowCount[k]=0;
	}
	for(int i = 0; i < 5; i++) 
	{
		p = 30;
		for(int j = 0; j < 1; j++) 
		{
			noLeft[i][j].leftup.x = p;
			noLeft[i][j].leftup.y = q;
			noLeft[i][j].rightlow.x = p + 70;
			noLeft[i][j].rightlow.y = q + 70;

			p += 70;
		}
		q += 70;
	}
	for(int i = 0; i < FIELD_SIDE_LEN; i++) 
	{
		x = 150;
		for(int j = 0; j < FIELD_SIDE_LEN; j++) 
		{
			sq[i][j].leftup.x = x;
			sq[i][j].leftup.y = y;
			sq[i][j].rightlow.x = x + 70;
			sq[i][j].rightlow.y = y + 70;
			uScore[i][j]=0;
			cScore[i][j]=-1;
			x += 70;
		}
		y += 70;
	}
	int n=20,m;
	for(int i = 0; i < 5; i++) 
	{
		m = 450;
		for(int j = 0; j < 1; j++) 
		{
			noRight[i][j].leftup.x = m;
			noRight[i][j].leftup.y = n;
			noRight[i][j].rightlow.x = m + 70;
			noRight[i][j].rightlow.y = n + 70;

			m += 70;
		}
		n += 70;
	}
}

void CCrossNullField::repaint()
{
	int y = 50, x;
	int q=20,p;
	for(int i = 0; i < 5; i++) 
	{
		p = 30;
		for(int j = 0; j < 1; j++) 
		{
			if(i==0)
				drawBitmap(p,q,hBmpONE_);
			else if(i==1)
				drawBitmap(p,q,hBmpTWO_);
			else if(i==2)
				drawBitmap(p,q,hBmpTHREE_);
			else if(i==3)
				drawBitmap(p,q,hBmpFOUR_);
			else if(i==4)
				drawBitmap(p,q,hBmpFIVE_);
			else ;
			p += 70;
		}
		q += 70;
	}
	for(int i = 0; i < FIELD_SIDE_LEN; i++) 
	{
		x = 150;
		for(int j = 0; j < FIELD_SIDE_LEN; j++) 
		{
			switch(sq[i][j].contents)
			{
				case CELL_EMPTY: 
					drawBitmap(x, y, hBmpE_); break;
				case CELL_NULL:   
					drawBitmap(x, y, hBmpN_); break;
				case CELL_CROSS: 
					drawBitmap(x, y, hBmpC_); break;
                case CELL_ONE: 
					drawBitmap(x, y, hBmpONE_); break;
				case CELL_TWO:   
					drawBitmap(x, y, hBmpTWO_); break;
				case CELL_THREE: 
					drawBitmap(x, y, hBmpTHREE_); break;
                case CELL_FOUR: 
					drawBitmap(x, y, hBmpFOUR_); break;
				case CELL_FIVE:   
					drawBitmap(x, y, hBmpFIVE_); break;
				case CELL_SIX: 
					drawBitmap(x, y, hBmpSIX_); break;
                case CELL_SEVEN: 
					drawBitmap(x, y, hBmpSEVEN_); break;
				case CELL_EIGHT:   
					drawBitmap(x, y, hBmpEIGHT_); break;
				case CELL_NINE: 
					drawBitmap(x, y, hBmpNINE_); break;
                case CELL_ZERO: 
					drawBitmap(x, y, hBmpZERO_); break;
 			}	
			x += 70;
		}
		y += 70;
	}
	int n=20,m;
	for(int i = 0; i < 5; i++) 
	{
		m = 450;
		for(int j = 0; j < 1; j++) 
		{
			if(i==0)
				drawBitmap(m,n,hBmpSIX_);
			else if(i==1)
				drawBitmap(m,n,hBmpSEVEN_);
			else if(i==2)
				drawBitmap(m,n,hBmpEIGHT_);
			else if(i==3)
				drawBitmap(m,n,hBmpNINE_);
			else if(i==4)
				drawBitmap(m,n,hBmpZERO_);
			else ;
			m += 70;
		}
		n += 70;
	}
}

// the function determines the "value" of each cell
void CCrossNullField::setCellsValues()
{
	// each cell is positined at the intersection of one horizontal and one vertical line
	// so we can set each "value" to 2 at once
	for(int i = 0; i < FIELD_SIDE_LEN; ++i) 
	{
		for(int j = 0; j < FIELD_SIDE_LEN; ++j) 
		{
			sq[i][j].value = 2;
		}
	}
	// after that we pass through diagonals
	for(int i = 0, j = 0; i < FIELD_SIDE_LEN && j < FIELD_SIDE_LEN; ++i, ++j)
	{
		sq[i][j].value++;
	}
	for(int i = 0, j = FIELD_SIDE_LEN - 1; i < FIELD_SIDE_LEN && j >= 0; ++i, --j)
	{
		sq[i][j].value++;
	}
}
void CCrossNullField::clearField()
{
	int y = 50, x;
	for(int i = 0; i < FIELD_SIDE_LEN; ++i) 
	{
		x = 150;
		for(int j = 0; j < FIELD_SIDE_LEN; ++j) 
		{
			sq[i][j].contents = CELL_EMPTY;
			drawBitmap(x, y, hBmpE_);   //paint an empty cell
			x += 70;
		}
		y += 70;
	}
	end_ = false;
}

bool CCrossNullField::determineWinner(CELL_SIGN type)
{
	//bool res;
	int mul1=1,mul2=1;
	if(counter!=16)
		return false;
	else
	{MessageBox(NULL, "Result SOON!", "The ehd", MB_OK);
		for(int i=0;i<FIELD_SIDE_LEN;i++)
		{
			int sum1=0,sum2=0;
			for(int j=0;j<FIELD_SIDE_LEN;j++)
			{
				sum1=sum1+cScore[i][j];
				sum2=sum2+uScore[i][j];
			}
			if(sum1!=0){mul1=mul1*sum1;}
			if(sum2!=0){mul2=mul2*sum2;}
		}
		int mul3=1,mul4=1;
		for(int i=0;i<FIELD_SIDE_LEN;i++)
		{
			int sum1=0,sum2=0;
			for(int j=0;j<FIELD_SIDE_LEN;j++)
			{
				sum1=sum1+cScore[j][i];
				sum2=sum2+uScore[j][i];
			}
			if(sum1!=0){mul3=mul3*sum1;}
			if(sum2!=0){mul4=mul4*sum2;}
		}
		int sum1=0,sum2=0;
		for(int i = 0, j = 0; i < FIELD_SIDE_LEN && j < FIELD_SIDE_LEN; ++i, ++j)
	    {
		  sum1=sum1+cScore[i][j];
		  sum2=sum2+uScore[i][j];
	    }
		mul1=mul1*sum1;
		mul2=mul2*sum2;
		sum1=0;sum2=0;
		for(int i = 0, j = FIELD_SIDE_LEN - 1; i < FIELD_SIDE_LEN && j >= 0; ++i, --j)
	    {
		   sum1=sum1+cScore[i][j];
		   sum2=sum2+uScore[i][j];
	    }
		mul3=mul3*sum1;
		mul4=mul4*sum2;
	    resultCPU=(mul1/mul3);
		resultUSER=(mul2/mul4);
		return true;
	}
	/*// pass through horizontals
	for(int i = 0; i < FIELD_SIDE_LEN; ++i) 
	{
		res = true;
		for(int j = 0; j < FIELD_SIDE_LEN; ++j) 
		{
			if(sq[i][j].contents != type)
			{
				res = false;
			}
		}
		if(res) return true;
	}

	// pass through vertical lines
	for(int j = 0; j < FIELD_SIDE_LEN; ++j)
	{
		res = true;
		for(int i = 0; i < FIELD_SIDE_LEN; ++i) 
		{
			if(sq[i][j].contents != type)
			{
				res = false;
			}
		}
		if(res) return true;
	}

	// pass through diagonals
	res = true;
	for(int i = 0, j = 0; i < FIELD_SIDE_LEN && j < FIELD_SIDE_LEN; ++i, ++j)
	{
		if(sq[i][j].contents != type)
		{
			res = false;
		}
	}
	if(res) return true;

	res = true;
	for(int i = 0, j = FIELD_SIDE_LEN - 1; i < FIELD_SIDE_LEN && j >= 0; ++i, --j)
	{
		if(sq[i][j].contents != type)
		{
			res = false;
		}
	}
	if(res) return true;

	return false;*/
}
void CCrossNullField::selectNumber(POINT pt)
{
		for(int i = 0; i < 5; i++) 
	    {
		    for(int j = 0; j < 1; j++) 
		    {
				if(pt.x<250 && pt.x > noLeft[i][j].leftup.x && pt.x < noLeft[i][j].rightlow.x 
				&& pt.y > noLeft[i][j].leftup.y && pt.y < noLeft[i][j].rightlow.y)
				{
					switch(i)
					{
					   case 0: {number=IDB_BITMAPONE;break;}
                       case 1: {number=IDB_BITMAPTWO;break;}
					   case 2: {number=IDB_BITMAPTHREE;break;}
					   case 3: {number=IDB_BITMAPFOUR;break;}
					   case 4: {number=IDB_BITMAPFIVE;break;}
					}
				}
				else if(pt.x>250 && pt.x > noRight[i][j].leftup.x && pt.x < noRight[i][j].rightlow.x 
				&& pt.y > noRight[i][j].leftup.y && pt.y < noRight[i][j].rightlow.y)
				{
					switch(i)
					{
					   case 0: {number=IDB_BITMAPSIX;break;}
                       case 1: {number=IDB_BITMAPSEVEN;break;}
					   case 2: {number=IDB_BITMAPEIGHT;break;}
					   case 3: {number=IDB_BITMAPNINE;break;}
					   case 4: {number=IDB_BITMAPZERO;break;}
					}
				}
				//else number=IDB_BITMAPE;
			}
	    }
}
void CCrossNullField::setNull(POINT pt)
{
	if(end_) 
		return;

	// paint null in the proper cell according to the cursor's coordinates
	for(int i = 0; i < FIELD_SIDE_LEN; ++i)
	{
		for(int j = 0; j < FIELD_SIDE_LEN;++j) 
		{
			if(pt.x > sq[i][j].leftup.x && pt.x < sq[i][j].rightlow.x 
				&& pt.y > sq[i][j].leftup.y && pt.y < sq[i][j].rightlow.y && 
				sq[i][j].contents == CELL_EMPTY)
			{
				switch(number)
				{
				case IDB_BITMAPONE:{drawBitmap(sq[i][j].leftup.x, sq[i][j].leftup.y, hBmpONE_);
								   sq[i][j].contents=CELL_ONE;number=IDB_BITMAPE;uScore[i][j]=1;
								   cScore[i][j]=0;lastx=i;lasty=j;counter++;rowCount[i]=rowCount[i]+1;
								   break;}
				case IDB_BITMAPTWO:{drawBitmap(sq[i][j].leftup.x, sq[i][j].leftup.y, hBmpTWO_);
								   sq[i][j].contents=CELL_TWO;number=IDB_BITMAPE;uScore[i][j]=2;
								   cScore[i][j]=0;lastx=i;lasty=j;counter++;rowCount[i]=rowCount[i]+1;
								   break;}
				case IDB_BITMAPTHREE:{drawBitmap(sq[i][j].leftup.x, sq[i][j].leftup.y, hBmpTHREE_);
								   sq[i][j].contents=CELL_THREE;number=IDB_BITMAPE;uScore[i][j]=3;
								   cScore[i][j]=0;lastx=i;lasty=j;counter++;rowCount[i]=rowCount[i]+1;
								   break;}
				case IDB_BITMAPFOUR:{drawBitmap(sq[i][j].leftup.x, sq[i][j].leftup.y, hBmpFOUR_);
								   sq[i][j].contents=CELL_FOUR;number=IDB_BITMAPE;uScore[i][j]=4;
								   cScore[i][j]=0;lastx=i;lasty=j;counter++;rowCount[i]=rowCount[i]+1;
								   break;}
				case IDB_BITMAPFIVE:{drawBitmap(sq[i][j].leftup.x, sq[i][j].leftup.y, hBmpFIVE_);
								   sq[i][j].contents=CELL_FIVE;number=IDB_BITMAPE;uScore[i][j]=5;
								   cScore[i][j]=0;lastx=i;lasty=j;counter++;rowCount[i]=rowCount[i]+1;
								   break;}
				case IDB_BITMAPSIX:{drawBitmap(sq[i][j].leftup.x, sq[i][j].leftup.y, hBmpSIX_);
								   sq[i][j].contents=CELL_SIX;number=IDB_BITMAPE;uScore[i][j]=6;
								   cScore[i][j]=0;lastx=i;lasty=j;counter++;rowCount[i]=rowCount[i]+1;
								   break;}
				case IDB_BITMAPSEVEN:{drawBitmap(sq[i][j].leftup.x, sq[i][j].leftup.y, hBmpSEVEN_);
								   sq[i][j].contents=CELL_SEVEN;number=IDB_BITMAPE;uScore[i][j]=7;
								   cScore[i][j]=0;lastx=i;lasty=j;counter++;rowCount[i]=rowCount[i]+1;
								   break;}
				case IDB_BITMAPEIGHT:{drawBitmap(sq[i][j].leftup.x, sq[i][j].leftup.y, hBmpEIGHT_);
								   sq[i][j].contents=CELL_EIGHT;number=IDB_BITMAPE;uScore[i][j]=8;
								   cScore[i][j]=0;lastx=i;lasty=j;counter++;rowCount[i]=rowCount[i]+1;
								   break;}
				case IDB_BITMAPNINE:{drawBitmap(sq[i][j].leftup.x, sq[i][j].leftup.y, hBmpNINE_);
								   sq[i][j].contents=CELL_NINE;number=IDB_BITMAPE;uScore[i][j]=9;
								   cScore[i][j]=0;lastx=i;lasty=j;counter++;rowCount[i]=rowCount[i]+1;
								   break;}
                case IDB_BITMAPZERO:{drawBitmap(sq[i][j].leftup.x, sq[i][j].leftup.y, hBmpZERO_);
								   sq[i][j].contents=CELL_ZERO;number=IDB_BITMAPE;uScore[i][j]=0;
								   cScore[i][j]=0;lastx=i;lasty=j;counter++;rowCount[i]=rowCount[i]+1;
								   break;}
				default:{MessageBox(NULL, "You Have Not Selected a NUMBER", "The ehd", MB_OK);
					/*drawBitmap(sq[i][j].leftup.x, sq[i][j].leftup.y, hBmpN_);
				               sq[i][j].contents = CELL_NULL;number=IDB_BITMAPE;lastx=i;lasty=j;counter++;
							   rowCount[i]=rowCount[i]+1;cScore[i][j]=0;uScore[i][j]=0;
				               break;*/}
				}
			}
		}
	}

	// determine if null has won
	if(determineWinner(CELL_NULL))
	{
		if(resultUSER>resultCPU){
		MessageBox(NULL, "You have won!", "The ehd", MB_OK);
		end_ = true;
		return;}
		if(resultCPU>resultUSER){
		MessageBox(NULL, "The computer have won!", "The ehd", MB_OK);
		end_ = true;}
	}

	// if hasn't - paint the cross
	setCross();

	if(determineWinner(CELL_CROSS))
	{
		if(resultUSER>resultCPU){
		MessageBox(NULL, "You have won!", "The ehd", MB_OK);
		end_ = true;
		return;}
		if(resultCPU>resultUSER){
		MessageBox(NULL, "The computer have won!", "The ehd", MB_OK);
		end_ = true;}
	}
}

void CCrossNullField::setCross()
{
	int iNew = -1, jNew = -1;
	// testing of crosses' positions:
	// the function determines if there is a place at which we can put our sign to win at once
    getNeedPosition(&iNew, &jNew, CELL_CROSS);

	/*if(iNew == -1) 
	{
		// testing of nulls' positions:
		// the function determines if there is a place at which we HAVE TO put our sign
		// to avoid defeat at the next move
		getNeedPosition(&iNew, &jNew, CELL_NULL);
	}*/

    // placing by default - we put to the cell which has the largest "value"
	if(iNew == -1) 
	{
		short maxValue = 0;
		for(int i = 0; i < FIELD_SIDE_LEN; ++i) 
		{
			for(int j = 0; j < FIELD_SIDE_LEN; ++j) 
			{
				if(sq[i][j].value > maxValue && sq[i][j].contents == CELL_EMPTY)
				{
					maxValue = sq[i][j].value;
					iNew = i;
					jNew = j;
				}
			}
		}
	}

    // paint the cross
    if(iNew != -1 && jNew != -1) 
	{
		switch(check)
		{
		case 1:{drawBitmap(sq[iNew][jNew].leftup.x, sq[iNew][jNew].leftup.y, hBmpONEC_);
		sq[iNew][jNew].contents = CELL_ONE;break;
		}
		case 2:{drawBitmap(sq[iNew][jNew].leftup.x, sq[iNew][jNew].leftup.y, hBmpTWOC_);
		sq[iNew][jNew].contents = CELL_TWO;break;
		}
		case 3:{drawBitmap(sq[iNew][jNew].leftup.x, sq[iNew][jNew].leftup.y, hBmpTHREEC_);
		sq[iNew][jNew].contents = CELL_THREE;break;
		}
		case 4:{drawBitmap(sq[iNew][jNew].leftup.x, sq[iNew][jNew].leftup.y, hBmpFOURC_);
		sq[iNew][jNew].contents = CELL_FOUR;break;
		}
		case 5:{drawBitmap(sq[iNew][jNew].leftup.x, sq[iNew][jNew].leftup.y, hBmpFIVEC_);
		sq[iNew][jNew].contents = CELL_FIVE;break;
		}
		case 6:{drawBitmap(sq[iNew][jNew].leftup.x, sq[iNew][jNew].leftup.y, hBmpSIXC_);
		sq[iNew][jNew].contents = CELL_SIX;break;
		}
		case 7:{drawBitmap(sq[iNew][jNew].leftup.x, sq[iNew][jNew].leftup.y, hBmpSEVENC_);
		sq[iNew][jNew].contents = CELL_SEVEN;break;
		}
		case 8:{drawBitmap(sq[iNew][jNew].leftup.x, sq[iNew][jNew].leftup.y, hBmpEIGHTC_);
		sq[iNew][jNew].contents = CELL_EIGHT;break;
		}
		case 9:{drawBitmap(sq[iNew][jNew].leftup.x, sq[iNew][jNew].leftup.y, hBmpNINEC_);
		sq[iNew][jNew].contents = CELL_NINE;break;
		}
	    case 0:{drawBitmap(sq[iNew][jNew].leftup.x, sq[iNew][jNew].leftup.y, hBmpZEROC_);
		sq[iNew][jNew].contents = CELL_ZERO;break;
		}
		default:{drawBitmap(sq[iNew][jNew].leftup.x, sq[iNew][jNew].leftup.y, hBmpC_);
			sq[iNew][jNew].contents = CELL_CROSS;}
		}
    }
}

// the function determines if there is a place at which we HAVE TO put our sign
// to avoid defeat at the next move
void CCrossNullField::getNeedPosition(int* pi, int* pj, CELL_SIGN type)
{
	*pi = -1;
    *pj = -1;
	// the quantity of cells of specified type, it must be = (FIELD_SIDE_LEN - 1)
	int countCellsOfType = 0;
	// all horizontal lines
	while(counter==1)
	{	
		int t=(rand())%4;
		if(t!=lasty&&counter==1)
		{ cScore[lastx][t]=9;
		  uScore[lastx][t]=0;
		  keys[9]=1;
		  check=9;//MessageBox(NULL, "NUMBER assigned", "The ehd", MB_OK);
		  rowCount[lastx]++;
		  *pi=lastx;
		  *pj=t;
		  lasty=t;
		  counter++;
		  return;}
	}
	int max=0,l,n2=0,p=0,q;
	for(int i=0;i<FIELD_SIDE_LEN;i++)
	{
		if(rowCount[i]>=max&&rowCount[i]!=4)
		{	
			max=rowCount[i];
			p=i;
			if(max==1)
				l=(rand()+number)%3;
			else if(max==2)
				l=(rand()+number)%2;
			else if(max==3)
				l=0;
			else l=(rand()+number)%4;
		}
	}
	for(int j=0;j<FIELD_SIDE_LEN;j++)
	{
		if(cScore[p][j]==-1)
		{
			if(l!=0)l--;
			else
			{q=j;//MessageBox(NULL, "NUMBER assigned", "The ehd", MB_OK);
				for(int k=0;k<FIELD_SIDE_LEN;k++)
				{
					if(cScore[j][k]!=-1)
						n2=n2+cScore[j][k];
				}
				if(n2<=0)
				{//MessageBox(NULL, "NUMBER assigned n2=0", "The ehd", MB_OK);
					for(int m=9;m>=0;m--)
					{if(keys[m]==0){n2=m;/*MessageBox(NULL, "NUMBER assigned n2=m", "The ehd", MB_OK);*/break;}}
				}
				else
				{
					n2=(n2<9)?(9-n2):0;
					if(n2==0)
					{
					  for(int m=0;m<9;m++)
					  {
						  if(keys[m]==0){n2=m;break;}
					  }
					}
				}
			}
		}
	}	//else ;
	    cScore[p][q]=n2;
		uScore[p][q]=0;
		check=n2;
		counter++;
		keys[n2]=1;
		rowCount[p]=rowCount[p]+1;
		lastx=p;
		lasty=q;
		*pi=p;
		*pj=q;
		return;
	
	/*for(int i = 0; i < FIELD_SIDE_LEN; ++i) 
	{
		countCellsOfType = 0;
		*pi = -1;
		*pj = -1;

		for(int j = 0; j < FIELD_SIDE_LEN; ++j) 
		{
			if(sq[i][j].contents == CELL_EMPTY)
			{
				*pi = i;
				*pj = j;
			}
			else 
			if(sq[i][j].contents == type)
			{
				++countCellsOfType;
			}
		}

		if(*pi != -1 && *pj != -1 && countCellsOfType == (FIELD_SIDE_LEN - 1) &&
				sq[*pi][*pj].contents == CELL_EMPTY)
		{
			return;
		}
	}*/

	// all vertical lines/*
	/*for(int j = 0; j < FIELD_SIDE_LEN; ++j) 
	{
		countCellsOfType = 0;
		*pi = -1;
		*pj = -1;

		for(int i = 0; i < FIELD_SIDE_LEN; ++i) 
		{
			if(sq[i][j].contents == CELL_EMPTY)
			{
				*pi = i;
				*pj = j;
			}
			else 
			if(sq[i][j].contents == type)
			{
				++countCellsOfType;
			}
		}

		if(*pi != -1 && *pj != -1 && countCellsOfType == (FIELD_SIDE_LEN - 1) &&
				sq[*pi][*pj].contents == CELL_EMPTY)
		{
			return;
		}
	}*/

	// the first diagonal
	/*countCellsOfType = 0;
	*pi = -1;
	*pj = -1;
	for(int j = 0, i = 0; j < FIELD_SIDE_LEN, i < FIELD_SIDE_LEN; ++j, ++i) 
	{
		if(sq[i][j].contents == CELL_EMPTY)
		{
			*pi = i;
			*pj = j;
		}
		else 
		if(sq[i][j].contents == type)
		{
			++countCellsOfType;
		}
	}
	if(*pi != -1 && *pj != -1 && countCellsOfType == (FIELD_SIDE_LEN - 1) &&
		sq[*pi][*pj].contents == CELL_EMPTY)
	{
		return;
	}*/

	// the second diagonal
	/*countCellsOfType = 0;
	*pi = -1;
	*pj = -1;
	for(int j = 0, i = FIELD_SIDE_LEN - 1; j < FIELD_SIDE_LEN, i >= 0; ++j, --i) 
	{
		if(sq[i][j].contents == CELL_EMPTY)
		{
			*pi = i;
			*pj = j;
		}
		else 
		if(sq[i][j].contents == type)
		{
			++countCellsOfType;
		}
	}
	if(*pi != -1 && *pj != -1 && countCellsOfType == (FIELD_SIDE_LEN - 1) &&
			sq[*pi][*pj].contents == CELL_EMPTY)
	{
		return;
	}

	*pi = -1;
	*pj = -1;*/
}

// paint the bitmap picture
void CCrossNullField::drawBitmap(int x, int y, HBITMAP hBitmap) 
{
	HDC hDCMemory;
	HBITMAP hOldBitmap;
	BITMAP bitmap;
	GetObject(hBitmap, sizeof(BITMAP), &bitmap);
	hDCMemory = CreateCompatibleDC(hdc_);
	hOldBitmap = (HBITMAP)SelectObject(hDCMemory,hBitmap);
	BitBlt(hdc_, x, y, bitmap.bmWidth, bitmap.bmHeight,
                                  hDCMemory, 0, 0, SRCCOPY);
	SelectObject(hDCMemory, hOldBitmap);
	DeleteDC(hDCMemory);
}
