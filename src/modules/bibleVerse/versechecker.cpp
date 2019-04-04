#include "verse.h"
#include "versechecker.h"

#include <QPlainTextEdit>

VerseChecker::VerseChecker(QWidget *const argParent) :
    AbstractDataChecker{new QPlainTextEdit, argParent}
{
}

void VerseChecker::SetDataToCheck(const AbstractDataTypeSharedPtr &argData)
{
    AbstractDataChecker::SetDataToCheck(argData);
}
