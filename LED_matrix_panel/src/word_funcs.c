#include "../include/word_funcs.h"
#include "../include/word_part.h"


int get_word_value(int index, int word_size, int parts_count, struct word_part* word_parts) {
    int current_index = 0;
	int part = 0;

	if (index < 0) {
		current_index = word_size + index; 
	} else {
		current_index = index;
	}
    
    for(part = 0; part < parts_count; part++) {
        if(current_index < (word_parts[part]).size) {
            return word_parts[part].data_[current_index];
        }
        current_index -= word_parts[part].size;
    }

    return 0;
}

int get_word_length(int parts_count, struct word_part* word_parts) {
    int total = 0;
	int part = 0;
    for(part = 0; part < parts_count; part++) {
        total += word_parts[part].size;
    }
    return total;
}

