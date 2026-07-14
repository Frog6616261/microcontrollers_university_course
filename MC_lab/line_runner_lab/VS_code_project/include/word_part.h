#ifndef WORD_PART_H
#define WORD_PART_H

struct WordPart;

struct WordPart {
    __code unsigned char* bytes_;    
    int size;      
};

#endif