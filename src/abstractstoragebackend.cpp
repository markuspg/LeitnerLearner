#include "abstractstoragebackend.h"

IOException* IOException::clone() const
{
    return new IOException{*this};
}

void IOException::raise() const
{
    throw *this;
}

AbstractStorageBackend::AbstractStorageBackend(QObject *const argParent) :
    QObject{argParent}
{
}
