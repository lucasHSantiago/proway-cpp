#include "pch.h"

#include "../DLLs/DLLs.h"
#include "../DLLs/Processor.h"

#include "MockDataFetcher.h"

namespace Mock
{
    TEST(ProcessorTest, ProcessDoublesTheFetchedData)
    {
        MockDataFetcher mock;

        //// Define comportamento esperado
        EXPECT_CALL(mock, FetchData())
            .Times(1)
            .WillOnce(testing::Return(21));

        Processor processor(&mock);

        EXPECT_EQ(processor.Process(), 42);
    }
}
