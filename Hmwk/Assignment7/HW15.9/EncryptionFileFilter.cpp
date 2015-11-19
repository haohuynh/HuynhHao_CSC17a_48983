/* 
 * File:   EncryptionFile.cpp
 * Author: HaoHuynh
 * 
 * Created on November 18, 2015, 6:27 PM
 */

#include "EncryptionFileFilter.h"

EncryptionFile::EncryptionFile(int key) {
    this->key = key;
}

EncryptionFile::EncryptionFile(const EncryptionFile& orig) {
}

EncryptionFile::~EncryptionFile() {
}

char EncryptionFile::transform(char ch) {
    return (ch + key); // Encrypts a character by the shifting technique
}
