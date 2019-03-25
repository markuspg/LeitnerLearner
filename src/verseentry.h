#ifndef VERSEENTRY_H
#define VERSEENTRY_H

#include <QWidget>

class Verse;

namespace Ui {
class VerseEntry;
} // namespace Ui

class VerseEntry : public QWidget
{
    Q_OBJECT

public:
    explicit VerseEntry(QWidget *const argParent = nullptr);
    ~VerseEntry() override;

public slots:
    void OnVerseSavingFailed();
    void OnVerseSavingSucceeded();

signals:
    void Req_VerseSaving(Verse argVerse);

private:
    Ui::VerseEntry *const ui = nullptr;

private slots:
    void OnAddButtonClicked();
};

#endif // VERSEENTRY_H
