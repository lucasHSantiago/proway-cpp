#pragma once

#include "IDataFetcher.h"

class DLLS_EXT_CLASS Processor
{
public:
    Processor(IDataFetcher* fetcher);

public:
    int Process();

private:
    IDataFetcher* fetcher;
};

