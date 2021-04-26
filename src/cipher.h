#ifndef CIPHER_H
#define CIPHER_H

int cipherCheck();

std::string encrypt(std::string plaintext);
std::string decrypt(std::string ciphertext);

int chooseCipher();

#endif 