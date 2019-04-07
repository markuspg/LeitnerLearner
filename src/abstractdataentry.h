#ifndef ABSTRACTDATAENTRY_H
#define ABSTRACTDATAENTRY_H

#include <QWidget>

namespace Ui {
class AbstractDataEntry;
} // namespace Ui

class AbstractDataEntry : public QWidget
{
    Q_OBJECT

public:
    explicit AbstractDataEntry(QWidget *const argParent = nullptr);
    ~AbstractDataEntry() override;

protected:
    Ui::AbstractDataEntry *const ui = nullptr;
};

#endif // ABSTRACTDATAENTRY_H
