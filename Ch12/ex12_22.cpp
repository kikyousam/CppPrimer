#include "ex12_22.h"

ConstStrBlobPtr StrBlob::begin() const
{
    return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::end() const
{
    return ConstStrBlobPtr(*this, data->size());
}