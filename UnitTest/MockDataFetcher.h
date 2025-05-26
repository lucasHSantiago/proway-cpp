#pragma once

#include <gmock/gmock.h>

#include "../DLLs/DLLs.h"
#include "../DLLs/IDataFetcher.h"

class MockDataFetcher : public IDataFetcher
{
public:
    MOCK_METHOD(int, FetchData, (), (override));
}; 
