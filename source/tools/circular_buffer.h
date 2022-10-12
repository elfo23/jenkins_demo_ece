/*
 * circular_buffer.h
 *
 *  Created on: 22.01.2022
 *      Author:         Valentina Ceru, Philipp Steinwender
 *      Description:    implementation of a circular buffer data structure
 *                      https://github.com/embeddedartistry/embedded-resources/blob/master/examples/c/circular_buffer/circular_buffer.c
 */

#ifndef TOOLS_CIRCULAR_BUFFER
#define TOOLS_CIRCULAR_BUFFER

#include <stdbool.h>
#include <inttypes.h>

//structs
typedef struct
{
    bool Filled;
    uint16_t *First; //points to the first element
    uint16_t *Last;  //points to the last element
    uint16_t *Head;  //points to the first free element
    uint16_t *Tail;  //points to the first used element
    uint16_t BufferSize;  //number of elements possible
} CircularBuffer;

//initializes a CircularBuffer with an given valuesArray
//buffer        : CircularBuffer struct to init
//bufferSize    : size of the CircularBuffer
//valuesArray   : pointer to the first element of the values array
void CircularBufferInit(CircularBuffer *buffer, uint16_t bufferSize, uint16_t *valuesArray);

//adds an element to the CircularBuffer
//element will only be added, if space left
//buffer        : buffer to add value
//elementToAdd  : element which will be added to buffer
void AddElement(CircularBuffer *buffer, uint16_t elementToAdd);

//adds an element to the CircularBuffer
//element overwrites old values, if no empty space is left
//buffer        : buffer to add value
//elementToAdd  : element which will be added to buffer
void AddElementOverwrite(CircularBuffer *buffer, uint16_t elementToAdd);

//returns the sum of all values inside the buffer
//buffer: buffer to sum up values
uint32_t GetElementsSum(CircularBuffer *buffer);

//returns the average of half of the buffers previous values
uint32_t GetAverageOfPrevious(CircularBuffer *buffer);

//returns the average of half of the buffers new values
uint32_t GetAverageOfNew(CircularBuffer *buffer);

uint32_t SumUpFromHeadClockwise(CircularBuffer *buffer, uint8_t elementsToSumUp);
uint32_t SumUpFromHeadCounterClockwise(CircularBuffer *buffer, uint8_t elementsToSumUp);

#endif /* TOOLS_CIRCULAR_BUFFER */
