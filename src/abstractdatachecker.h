/*
 * Copyright 2019 Markus Prasser
 *
 * This file is part of LeitnerLearner.
 *
 *  LeitnerLearner is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  LeitnerLearner is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with LeitnerLearner.  If not, see <http://www.gnu.org/licenses/>.
 */

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

public slots:
    virtual void DataLevelUpdateFailed();
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
