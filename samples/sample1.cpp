#include "sample1.h"

// Returns true if specified number is prime; false otherwise.
bool IsPrime(int Number)
{
    if (Number <= 1)
    {
        return (false);
    }

    if (Number % 2 == 0)
    {
        return (Number == 2);
    }

    for (int Index = 3; ; Index += 2)
    {
        if (Index > Number / Index)
        {
            break;
        }

        if (Number % Index == 0)
        {
            return (false);
        }
    }

    return (true);
}