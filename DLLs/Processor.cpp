#include "pch.h"
#include "Processor.h"

Processor::Processor(IDataFetcher* fetcher)
    : fetcher(fetcher)
{
}

int Processor::Process()
{
    int data = fetcher->FetchData();
    return data * 2;
}
