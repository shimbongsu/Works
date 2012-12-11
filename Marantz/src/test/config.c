/***********************************************************
 SRC Name		: log.c 
 INC Header		: log.h
 Function		: Log Generator
 Create Date	: 2011. 03. 02
 Last Edited	: 2011. 03. 02 
 Finish Date	: Not Yet 
 Creator		: by DongHan Kim 
***********************************************************/
/***********************************************************
	Include Header
***********************************************************/
#include "main.h"
#include "config.h"

/***********************************************************
	Global Variable
***********************************************************/
char gc_filename[256];
FILE *gp_file;

/***********************************************************
	Function
***********************************************************/
int InitConfig()
{
	gp_file = NULL;
	memset(gc_filename,0x00,sizeof(gc_filename));
	
	/* CONFIG_FILE : [%s/work/cfg/config.cfg] */
	sprintf(gc_filename,CONFIG_FILE,getenv("HOME"));
	
	gp_file = open(gc_filename, O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
	if( gp_file == NULL ) {
		return FALSE;
	}
		
	return TRUE;
}

int ConfigGetInt(char *SectionName, char *OptionName, int *Value)
{
	int li_rtn = InitConfig();
	if( li_rtn != TRUE) {
		return FALSE;
	}
	
	(*Value) = 0x01;
	
	if( gp_file != NULL ) {
		fclose( gp_file );
	}
	return TRUE;
}

int ConfigGetString(char *SectionName, char *OptionName, char *Value)
{
	int li_rtn = InitConfig();
	if( li_rtn != TRUE) {
		return FALSE;
	}
	
	char lc_temp[256];
	memset(gc_filename,0x00,sizeof(gc_filename));
	
	strcpy(Value,lc_temp);
	
	if( gp_file != NULL ) {
		fclose( gp_file );
	}
	return TRUE;
}
/* EOF */
