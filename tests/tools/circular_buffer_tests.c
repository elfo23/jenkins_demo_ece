#include <stdio.h>
#include <string.h>
#include <unity.h>
#include <circular_buffer.h>

void setUp(void)
{
    printf("Setup\n");
}

void tearDown(void)
{
    printf("Teardown\n");
}

void AddElementOverwrite_Check()
{
    CircularBuffer testBuffer;
    uint16_t testValues[8] = {0};

    CircularBufferInit(&testBuffer, 8, testValues);

    for (uint16_t i = 0; i < 10; i++)
    {
        AddElementOverwrite(&testBuffer, i);
    }

    TEST_ASSERT_EQUAL(8, testBuffer.BufferSize);
    TEST_ASSERT_EQUAL(8, testBuffer.First[0]);
    TEST_ASSERT_EQUAL(9, testBuffer.First[1]);
}

void GetElementsSum_Check()
{
    CircularBuffer testBuffer;
    uint16_t testValues[8] = {0};

    CircularBufferInit(&testBuffer, 8, testValues);

    for (uint16_t i = 0; i < 10; i++)
    {
        AddElementOverwrite(&testBuffer, i);
    }

    uint32_t sum = GetElementsSum(&testBuffer);
    TEST_ASSERT_EQUAL(44, sum);
}

void SumUpFromHeadClockwise_Check()
{
    CircularBuffer testBuffer;
    uint16_t testValues[8] = {0};
    CircularBufferInit(&testBuffer, 8, testValues);
    for (uint16_t i = 0; i < 10; i++)
    {
        AddElementOverwrite(&testBuffer, i);
    }

    uint32_t sum = SumUpFromHeadClockwise(&testBuffer, 4);
    TEST_ASSERT_EQUAL(14, sum);
}

void SumUpFromHeadCounterClockwise_Check()
{
    CircularBuffer testBuffer;
    uint16_t testValues[8] = {0};
    CircularBufferInit(&testBuffer, 8, testValues);
    for (uint16_t i = 0; i < 10; i++)
    {
        AddElementOverwrite(&testBuffer, i);
    }

    uint32_t sum = SumUpFromHeadCounterClockwise(&testBuffer, 4);
    TEST_ASSERT_EQUAL(30, sum);
}

void GetAverageOfPrevious_Check()
{
    CircularBuffer testBuffer;
    uint16_t testValues[8] = {0};
    CircularBufferInit(&testBuffer, 8, testValues);
    for (uint16_t i = 0; i < 10; i++)
    {
        AddElementOverwrite(&testBuffer, i);
    }

    uint32_t avg = GetAverageOfPrevious(&testBuffer);
    TEST_ASSERT_EQUAL(3, avg);
}

void GetAverageOfNew_Check()
{
    CircularBuffer testBuffer;
    uint16_t testValues[8] = {0};
    CircularBufferInit(&testBuffer, 8, testValues);
    for (uint16_t i = 0; i < 10; i++)
    {
        AddElementOverwrite(&testBuffer, i);
    }

    uint32_t avg = GetAverageOfNew(&testBuffer);
    TEST_ASSERT_EQUAL(7, avg);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(AddElementOverwrite_Check);
    RUN_TEST(GetElementsSum_Check);
    RUN_TEST(SumUpFromHeadClockwise_Check);
    RUN_TEST(SumUpFromHeadCounterClockwise_Check);
    RUN_TEST(GetAverageOfPrevious_Check);
    RUN_TEST(GetAverageOfNew_Check);
    return UNITY_END();
}