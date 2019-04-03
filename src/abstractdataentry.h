#ifndef ABSTRACTDATAENTRY_H
#define ABSTRACTDATAENTRY_H

#include <QWidget>

class AbstractDataEntry : public QWidget
{
    Q_OBJECT

public:
    explicit AbstractDataEntry(QWidget *const argParent = nullptr);
};

#endif // ABSTRACTDATAENTRY_H
