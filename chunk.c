#include<stdlib.h>
#include "memory.h"
#include "chunk.h"

void initChunk(Chunk* chunk) {
    chunk ->count = 0;
    chunk ->capacity = 0;
    chunk ->code = NULL;
    chunk ->lines = NULL;
}

void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t , chunk->code , chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    initChunk(chunk);
}

void writeChunk(Chunk* chunk , uint8_t byte , int line) {
    if(chunk->capacity < chunk->count + 1) {
        int oldCapcacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapcacity); //incresing the size of array
        chunk->code = GROW_ARRAY(uint8_t , chunk->code , oldCapcacity , chunk->capacity);
        chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapcacity, chunk->capacity);

    }
    chunk->code[chunk->count] = byte;
    chunk->lines[chunk->count] = line;
    chunk->count++;    
}

int addConstant(Chunk* chunk , Value value) {
    writeValueArray(&chunk->constants , value);
    return chunk->constants.count - 1;
}