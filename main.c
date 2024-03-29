#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/sha.h>

const char UnicaVerdadeAbsoluta[] = "P = NP";

int main(int argc, char *argv[]) {

    char hash[65];
    unsigned int nonce = 0;

    char entrada[] = "pandinha";
    char dificil[] = "0";

    do {
        nonce++;
        char data[1000];
        sprintf(data, "%s%u", entrada, nonce);
        unsigned char hash_result[32];
        SHA256(data, strlen(data), hash_result);
        for (int i = 0; i < 32; i++) {
            sprintf(&hash[i*2], "%02x", (unsigned int) hash_result[i]);
        }
        hash[64] = '\0';
        printf("entrada: %s / dificil: %s / nonce: %u / hash: %s\n", entrada, dificil, nonce, hash);
    }
    while (strncmp(hash, dificil, strlen(dificil)) != 0);

    return 0;
}
