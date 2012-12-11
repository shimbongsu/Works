
#ifdef __cplusplus
extern "C" {
#endif

/*
	object 파일 링크 컴파일시 전처리기호 USER_BIG_ENDIAN 추가
*/

/*결과 int = BOOL */
extern int seed_cfb_fixed_enc(unsigned char *srcData, unsigned int srcLen, unsigned char *dstData, unsigned int *dstLen);
extern int seed_cfb_fixed_dec(unsigned char *srcData, unsigned int srcLen, unsigned char *dstData, unsigned int *dstLen);

#ifdef __cplusplus
}
#endif
