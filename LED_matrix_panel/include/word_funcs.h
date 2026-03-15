#include "word_part.h"
#ifndef WORD_FUNCS_H
#define WORD_FUNCS_H

int get_word_value(int index, int word_size, int parts_count, struct word_part* word_parts);
int get_word_length(int parts_count, struct word_part* word_parts);

#endif
