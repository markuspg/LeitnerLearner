#ifndef ABSTRACTENTRYWDGT_H
#define ABSTRACTENTRYWDGT_H

#include "abstractdatatype.h"

#include <QWidget>

class AbstractEntryWdgt : public QWidget
{
    Q_OBJECT

public:
    explicit AbstractEntryWdgt(QWidget *const argParent = nullptr);

    /*!
     * \brief GetDataPr returns a pointer to the data and otherwise an empty shared pointer
     * \return A shared pointer pointing to the data (or an empty one)
     */
    virtual AbstractDataTypeSharedPtr GetDataPr() = 0;

signals:
    /*!
     * \brief This signal tells the its containing widget that data is complete for submission
     */
    void DataComplete();

protected:
    bool dataHasBeenCompleted = false;
};

#endif // ABSTRACTENTRYWDGT_H
