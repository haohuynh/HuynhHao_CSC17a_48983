/* 
 * File:   EncryptionFile.h
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 6:27 PM
 */

#ifndef ENCRYPTIONFILE_H
#define	ENCRYPTIONFILE_H

#include "AbstractFileFilter.h"

class EncryptionFile : public AbstractFileFilter {
private:
    int key;

public:
    EncryptionFile(int = 8);
    EncryptionFile(const EncryptionFile& orig);
    virtual ~EncryptionFile();

    virtual char transform(char ch);
};

#endif	/* ENCRYPTIONFILE_H */

