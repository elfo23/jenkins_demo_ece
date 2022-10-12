/*
 * circular_buffer.c
 *
 *  Created on: 22.01.2022
 *      Author:         Valentina Ceru, Philipp Steinwender
 *      Description:    implementation of a circular buffer data structure
 */

#include "circular_buffer.h"

void CircularBufferInit(CircularBuffer *buffer, uint16_t bufferSize, uint16_t *valuesArray)
{
    buffer->Filled = false;
    buffer->First = valuesArray;
    //point to the last possible element
    buffer->Last = valuesArray + bufferSize - 1;
    buffer->Head = buffer->First;
    buffer->Tail = buffer->Last;
    buffer->BufferSize = bufferSize;
}

void AddElement(CircularBuffer *buffer, uint16_t elementToAdd)
{
    //if the buffer is full, we return
    if (buffer->Head == buffer->Tail)
    {
        return;
    }

    //write the given element to the first free space
    *(buffer->Head) = elementToAdd;

    //check, if end/start of circle was reached and increase head pointer
    if (buffer->Head == buffer->Last)
    {
        buffer->Head = buffer->First;
        buffer->Filled = true;
    }
    else
    {
        buffer->Head++;
    }
}

void AddElementOverwrite(CircularBuffer *buffer, uint16_t elementToAdd)
{
    //write the given element to the first free space
    *(buffer->Head) = elementToAdd;

    //check, if end/start of circle was reached and increase head pointer
    if (buffer->Head == buffer->Last)
    {
        buffer->Head = buffer->First;
        buffer->Filled = true;
    }
    else
    {
        buffer->Head++;
    }
}

uint32_t GetElementsSum(CircularBuffer *buffer)
{
    if (buffer->Filled == false)
    {
        return 0;
    }

    uint32_t sum = 0;
    uint8_t i = 0;
    for (i = 0; i < buffer->BufferSize; i++)
    {
        sum += buffer->First[i];
    }

    return sum;
}

uint32_t GetAverageOfPrevious(CircularBuffer *buffer)
{
    if (buffer->Filled == false)
    {
        return 0;
    }

    uint16_t numberOfElements = buffer->BufferSize >> 1;
    uint32_t sum = SumUpFromHeadClockwise(buffer, numberOfElements);
    return sum / numberOfElements;
}

uint32_t GetAverageOfNew(CircularBuffer *buffer)
{
    if (buffer->Filled == false)
    {
        return 0;
    }

    uint16_t numberOfElements = buffer->BufferSize >> 1;
    uint32_t sum = SumUpFromHeadCounterClockwise(buffer, numberOfElements);
    return sum / numberOfElements;
}

uint32_t SumUpFromHeadClockwise(CircularBuffer *buffer, uint8_t elementsToSumUp)
{
    if (buffer->Filled == false)
    {
        return 0;
    }

    uint32_t sum = 0;
    uint16_t *ptr;
    uint8_t i = 0;
    if (buffer->Head == buffer->Last)
    {
        ptr = buffer->First;
    }
    else
    {
        ptr = buffer->Head;
    }

    for (i = 0; i < elementsToSumUp; i++)
    {
        if (ptr == buffer->Last)
        {
            sum += *ptr;
            ptr = buffer->First;
        }
        else
        {
            sum += *ptr;
            ptr++;
        }
    }

    return sum;
}

uint32_t SumUpFromHeadCounterClockwise(CircularBuffer *buffer, uint8_t elementsToSumUp)
{
    if (buffer->Filled == false)
    {
        return 0;
    }

    uint32_t sum = 0;
    uint8_t i = 0;
    uint16_t *ptr;

    if (buffer->Head == buffer->First)
    {
        ptr = buffer->Last;
    }
    else
    {
        ptr = buffer->Head - 1;
    }

    for (i = 0; i < elementsToSumUp; i++)
    {
        if (ptr == buffer->First)
        {
            sum += *ptr;
            ptr = buffer->Last;
        }
        else
        {
            sum += *ptr;
            ptr--;
        }
    }

    return sum;
}
