#include <openssl/des.h>
#include <ctype.h>


#define ENC 1
#define DEC 0

int main(int argc, char **argv)
{
	int k;
	long	in[2];
	static unsigned char cbc_key[8] = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef};
	des_key_schedule key;

//
	//char KEYV[16] = argv [2];
	FILE *inputf;
	FILE *outputf;
	char PrevCypher[9];
	char Plaintext[9];
	//char IV[16] = argv[1];
//


	if ((k = des_set_key_checked(&cbc_key,key)) != 0)
		printf("\nkey error\n");

	in[0] = 3212314;
	in[1] = 1231233;


	printf("DES Clear Text: %ld%ld\n",in[0],in[1]);
	des_encrypt1(in,key,ENC);

	printf("DES Encryption: %u%u\n",in[0],in[1]);
    des_encrypt1(in,key,DEC);

    // xor first plaintext with IV
    if(inputf = fopen(argv[3], "r"))
    	fread(Plaintext, 8, 1, inputf);

    //xor each char
    //Plaintext = Plaintext[0] ^ ;
    // call encrypt on first block
    //PrevCypher = CBC_ENC(Plaintext, key);

    // write first block of cypher to output
    //if (outputf = fopen(argv[4], "w"))
    	//fprintf(outputf, Plaintext);

    // Using the previous block of cypher text
    // and the current plain text. xor the cypher
    // with the plaintext, then send it to be encrypted
    // using the xored text and the key to the encryption function
    // Do this for the rest of the file, reading 8 bytes at a time.

    //while (fread(Plaintext, 8, 1, inputf) != '\0')
    //{
    		//Plaintext = Plaintext ^ PrevCypher;
    		//PrevCypher = CBC_ENC(Plaintext, key);
    	// write block of cypher to output
    		//fprintf(outputf, Plaintext);
    //}





}

//char * CBC_ENC(char input[9], des_key_schedule key)
//{
	//char cypher[9];

	//des_encrypt1(input,key, 1);

	//return cypher;
//}





