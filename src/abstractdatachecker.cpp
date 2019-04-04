#include "abstractdatachecker.h"
#include "ui_abstractdatachecker.h"

#include <QtDebug>

AbstractDataChecker::AbstractDataChecker(QWidget *const argDisplayWdgt,
                                         QWidget *const argParent) :
    QWidget{argParent},
    displayWdgt{argDisplayWdgt},
    ui{new Ui::AbstractDataChecker}
{
    ui->setupUi(this);

    ui->VLAbstractDataChecker->insertWidget(0, displayWdgt);

    connect(ui->PBCorrect, &QPushButton::clicked,
            this, &AbstractDataChecker::OnPBCorrectClicked);
    connect(ui->PBWrong, &QPushButton::clicked,
            this, &AbstractDataChecker::OnPBWrongClicked);
}

AbstractDataChecker::~AbstractDataChecker()
{
    delete ui;
}

void AbstractDataChecker::OnPBCorrectClicked()
{
    SetPBWrongState(EPBWrongState::SHOW);

    emit DataVerificationSucceeded(AbstractDataTypeSharedPtr{});
}

void AbstractDataChecker::OnPBWrongClicked()
{
    if (pbWrongState == EPBWrongState::SHOW) {
        SetPBWrongState(EPBWrongState::WRONG);
    } else {
        SetPBWrongState(EPBWrongState::SHOW);

        emit DataVerificationFailed(AbstractDataTypeSharedPtr{});
    }
}

void AbstractDataChecker::SetDataToCheck(const AbstractDataTypeSharedPtr &argData)
{
    Q_UNUSED(argData)

    ui->PBWrong->setEnabled(true);
}

void AbstractDataChecker::SetPBWrongState(const EPBWrongState argNewState)
{
    if (argNewState == EPBWrongState::WRONG) {
        ui->PBWrong->setText(tr("Wrong"));
        ui->PBCorrect->setEnabled(true);
        pbWrongState = argNewState;
    } else {
        ui->PBWrong->setText(tr("Show"));
        ui->PBCorrect->setEnabled(false);
        pbWrongState = argNewState;
    }
}
