#ifndef VERSECHECKER_H
#define VERSECHECKER_H

#include <QWidget>

class Verse;

namespace Ui {
class VerseChecker;
} // namespace Ui

class VerseChecker : public QWidget
{
    Q_OBJECT

public:
    explicit VerseChecker(QWidget *const argParent = nullptr);
    ~VerseChecker() override;

    void SetVerseToCheck(const Verse &argVerse);

signals:
    void VerseVerificationFailed(Verse argVerse);
    void VerseVerificationSucceeded(Verse argVerse);

private:
    enum class EPBWrongState {
        SHOW,
        WRONG
    };

    void SetPBWrongState(const EPBWrongState argNewState);

    EPBWrongState pbWrongState = EPBWrongState::SHOW;
    Ui::VerseChecker *const ui = nullptr;

private slots:
    void OnPBCorrectClicked();
    void OnPBWrongClicked();
};

#endif // VERSECHECKER_H
