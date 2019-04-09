#ifndef ABSTRACTDATAENTRY_H
#define ABSTRACTDATAENTRY_H

#include "abstractdatatype.h"

#include <QWidget>

class AbstractEntryWdgt;

namespace Ui {
class AbstractDataEntry;
} // namespace Ui

class AbstractDataEntry : public QWidget
{
    Q_OBJECT

public:
    explicit AbstractDataEntry(AbstractEntryWdgt *const argEntryWdgt,
                               QWidget *const argParent = nullptr);
    ~AbstractDataEntry() override;

public slots:
    void OnDataSavingFailed();
    void OnDataSavingSucceeded();

signals:
    void Req_DataSaving(AbstractDataTypeSharedPtr argData);

protected:
    AbstractEntryWdgt *const entryWdgt = nullptr;
    Ui::AbstractDataEntry *const ui = nullptr;

private slots:
    void OnAddButtonClicked();
    void OnDataComplete();
};

#endif // ABSTRACTDATAENTRY_H
