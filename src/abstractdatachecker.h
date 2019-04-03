#ifndef ABSTRACTDATACHECKER_H
#define ABSTRACTDATACHECKER_H

#include <QWidget>

class AbstractDataChecker : public QWidget
{
    Q_OBJECT

public:
    explicit AbstractDataChecker(QWidget *const argParent = nullptr);
};

#endif // ABSTRACTDATACHECKER_H
