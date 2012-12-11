/***********************************************************
 Header			: bizfunc.h
 Function		: Biz Header
 Create Date	: 2011. 03. 02
 Last Edited	: 2011. 03. 02 
 Finish Date	: Not Yet 
 Creator		: by DongHan Kim 
***********************************************************/
#ifndef _BIZ_FUNC_H_
#define _BIZ_FUNC_H_

/***********************************************************
	Include Header
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* 주가생성 정보 기본 생성 */
typedef struct stock_base {
	long 	StrtPrice;
	float 	ChngRatio;
	int 	CalcType;
	float 	PrblDist;
	float 	LevyAlpha;
	float 	LevyFactor;
	long 	Days;
} STOCK_BASE;

/* 종목정보 조회 결과 */
typedef struct stock_info_rslt {
	char	STOCK_NO[  6+1];
	char	STOCK_NM[200+1];
	char	OPEN_DT	[  8+1];
	char	AREA_NM	[  6+1];
} STOCK_INFO_RSLT;

extern int StockCreateRunner( char *StockNo );
extern int CalculateStockData();
extern int CreateVirtualStockData( STOCK_INFO_RSLT *stock_info_rslt );
extern int GenerateStockData( STOCK_BASE *st_stock_base, int Day, long *StockPrice );
extern void PrintStockInfoData(STOCK_INFO_RSLT *stock_info_rslt);
extern void PrintStockBaseData(STOCK_BASE *st_stock_base);

#endif
/* EOF */
