#ifndef ABSTRACTDATACHECKER_H
#define ABSTRACTDATACHECKER_H

#include "abstractdatatype.h"

#include <QWidget>

namespace Ui {
class AbstractDataChecker;
} // namespace Ui

class AbstractDataChecker : public QWidget
{
    Q_OBJECT

public:
    explicit AbstractDataChecker(QWidget *const argDisplayWdgt,
                                 QWidget *const argParent = nullptr);
    ~AbstractDataChecker() override;

    virtual void SetDataToCheck(const AbstractDataTypeSharedPtr &argData);

signals:
    void DataVerificationFailed(AbstractDataTypeSharedPtr argData);
    void DataVerificationSucceeded(AbstractDataTypeSharedPtr argData);

protected:
    QWidget *const displayWdgt = nullptr;
    Ui::AbstractDataChecker *const ui = nullptr;

private:
    enum class EPBWrongState {
        SHOW,
        WRONG
    };

    void SetPBWrongState(const EPBWrongState argNewState);

    EPBWrongState pbWrongState = EPBWrongState::SHOW;

private slots:
    void OnPBCorrectClicked();
    void OnPBWrongClicked();
};

#endif // ABSTRACTDATACHECKER_H
