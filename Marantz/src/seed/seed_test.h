
#ifdef __cplusplus
extern "C" {
#endif

/*
	object ���� ��ũ �����Ͻ� ��ó����ȣ USER_BIG_ENDIAN �߰�
*/

/*��� int = BOOL */
extern int seed_cfb_fixed_enc(unsigned char *srcData, unsigned int srcLen, unsigned char *dstData, unsigned int *dstLen);
extern int seed_cfb_fixed_dec(unsigned char *srcData, unsigned int srcLen, unsigned char *dstData, unsigned int *dstLen);

#ifdef __cplusplus
}
#endif
