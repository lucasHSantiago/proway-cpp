#include <functional>

class ScopeGuard
{
private:
    using Action = std::function<void(void)>;

public:
    ScopeGuard(Action fAction)
        : fAction{ std::move(fAction) }
    {

    }

    ~ScopeGuard()
    {
        if (bool{ fAction })
            fAction();
    }

private:
    Action fAction;
};

namespace Uso
{
    int main()
    {
        int* pVal = new int(10);
        ScopeGuard scopeGuard([&]()
            {
                delete pVal;
            });

        /*
        HMODULE dllHandle = LoadLibrary("DLLs.dll");
        ScopeGuard scope([&]()
        {
            if (dllHandle)
                FreeLibrary(dllHandle);
        });
        */

        return 0;
    }

}