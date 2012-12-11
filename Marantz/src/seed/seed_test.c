/*************** Header files *********************************************/
#include <stdio.h>
#include "seed_test.h"
#include "log.h"

#define NO_ENC_LEN 68
/**************************************************************************/
int isBigEndian() 
{
	int no = 1;
	char *chk = (char *)&no;

	if (chk[0] == 1)
		return 0;
	else
		return 1;
	
}

int main(int argc, char **argv)
{

	/*
	log_printf(LOG_ARG,"================================================================================");
	log_printf(LOG_ARG,"BIG ENDIAN CHECK ENC:[%s]", isBigEndian() == 1 ? "BIG ENDIAN" : "LITTLE ENDIAN");
	log_printf(LOG_ARG,"================================================================================");
	*/
	
	gi_LogLevel = 2;
	
	int ret = 0;
	unsigned int srcLen;
	unsigned int dstLen;
	
	char orgBuf[512] = {0x00, };
	char encBuf[512] = {0x00, };
	char decBuf[512] = {0x00, };
	
	/* "한글 16자 테스트" */
	char testKor[16] = {	0xC7,	// 01 
							0xD1,	// 02
							0xB1,	// 03
							0xDB,	// 04
							0x20,	// 05
							0x31,	// 06
							0x36,	// 07
							0xC0,	// 08
							0xDA,	// 09
							0x20,	// 10
							0xC5,	// 11
							0xD7,	// 12
							0xBD,	// 13
							0xBA,	// 14
							0xC6,	// 15
							0xAE}; 	// 16
	
	memset(orgBuf,0x00,sizeof(orgBuf));
	memset(decBuf,0x00,sizeof(orgBuf));
	//               1234567890123456789012345678901234567890
	strncpy(orgBuf, testKor, 16);
		
	srcLen = 16; dstLen = 16;
	ret = seed_cfb_fixed_enc( (unsigned char*)(orgBuf), srcLen, (unsigned char*)(encBuf), &dstLen );
	srcLen = 16; dstLen = 16;
	ret = seed_cfb_fixed_dec( (unsigned char*)(encBuf), srcLen, (unsigned char*)(decBuf), &dstLen );
	
	//printf("BEFORE ENC:[%s]\n",orgBuf);
	//printf("AFTER  ENC:[%s]\n",encBuf);
	//printf("AFTER  DEC:[%s]\n",decBuf);
	
	log_printf(LOG_ARG,"================================================================================");
	log_printf(LOG_ARG,"BEFORE ENC:[%s]",orgBuf);
	dump_printf(orgBuf,16);
	log_printf(LOG_ARG,"================================================================================");
	//log_printf(LOG_ARG,"AFTER  ENC:[%s]",encBuf);
	log_printf(LOG_ARG,"AFTER  ENC DUMP");
	dump_printf(encBuf,16);
	log_printf(LOG_ARG,"================================================================================");
	log_printf(LOG_ARG,"AFTER  DEC:[%s]",decBuf);
	log_printf(LOG_ARG,"================================================================================");
	
	log_printf(LOG_ARG,"================================================================================");
	log_printf(LOG_ARG,"AFTER  DEC");
	dump_printf(decBuf,16);
	log_printf(LOG_ARG,"================================================================================");

	
	return ret;

}

/*************** END OF FILE **********************************************/
