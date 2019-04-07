#ifndef ABSTRACTENTRYWDGT_H
#define ABSTRACTENTRYWDGT_H

#include "abstractdatatype.h"

#include <QWidget>

class AbstractEntryWdgt : public QWidget
{
    Q_OBJECT

public:
    explicit AbstractEntryWdgt(QWidget *const argParent = nullptr);

    virtual AbstractDataTypeSharedPtr GetDataPr() = 0;

signals:
    /*!
     * \brief This signal tells the it containing widget that data is complete for submission
     */
    void DataComplete();
};

#endif // ABSTRACTENTRYWDGT_H
