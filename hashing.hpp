#ifndef HASHING_H_
#define HASHING_H_

#include <iostream>
#include <openssl/sha.h>
#include <string>

std::string calculateSHA128(const std::string &input) {
  unsigned char hash[SHA_DIGEST_LENGTH]; // SHA_DIGEST_LENGTH is 16 for SHA-128
  SHA1(reinterpret_cast<const unsigned char *>(input.c_str()), input.length(),
       hash);

  std::string hashString;
  for (int i = 0; i < SHA_DIGEST_LENGTH; ++i) {
    hashString += std::to_string(hash[i]);
  }

  return hashString;
}

#endif // HASHING_H_
