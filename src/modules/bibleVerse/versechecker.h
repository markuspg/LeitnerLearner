#ifndef VERSECHECKER_H
#define VERSECHECKER_H

#include "../../abstractdatachecker.h"

class VerseChecker : public AbstractDataChecker
{
    Q_OBJECT

public:
    explicit VerseChecker(QWidget *const argParent = nullptr);

    void SetDataToCheck(const AbstractDataTypeSharedPtr &argData) override;
};

#endif // VERSECHECKER_H
