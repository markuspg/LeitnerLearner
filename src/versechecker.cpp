#include "verse.h"
#include "versechecker.h"
#include "ui_versechecker.h"

VerseChecker::VerseChecker(QWidget *const argParent) :
    QWidget{argParent},
    ui{new Ui::VerseChecker}
{
    ui->setupUi(this);

    connect(ui->PBCorrect, &QPushButton::clicked,
            this, &VerseChecker::OnPBCorrectClicked);
    connect(ui->PBWrong, &QPushButton::clicked,
            this, &VerseChecker::OnPBWrongClicked);
}

VerseChecker::~VerseChecker()
{
    delete ui;
}

void VerseChecker::OnPBCorrectClicked()
{
    SetPBWrongState(EPBWrongState::SHOW);

    emit VerseVerificationSucceeded(Verse{});
}

void VerseChecker::OnPBWrongClicked()
{
    if (pbWrongState == EPBWrongState::SHOW) {
        SetPBWrongState(EPBWrongState::WRONG);
    } else {
        SetPBWrongState(EPBWrongState::SHOW);

        emit VerseVerificationFailed(Verse{});
    }
}

void VerseChecker::SetPBWrongState(const EPBWrongState argNewState)
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

void VerseChecker::SetVerseToCheck(const Verse &argVerse)
{
    Q_UNUSED(argVerse)

    ui->PBWrong->setEnabled(true);
}
