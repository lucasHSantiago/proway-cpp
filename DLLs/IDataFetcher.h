#pragma once

class DLLS_EXT_CLASS IDataFetcher
{
public:
    virtual ~IDataFetcher() = default;
    virtual int FetchData() = 0;
};

