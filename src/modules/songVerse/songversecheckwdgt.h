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

#ifndef SONGVERSECHECKWDGT_H
#define SONGVERSECHECKWDGT_H

#include "../../abstractcheckwdgt.h"
#include "../../singleton.h"

namespace Ui {
class SongVerseCheckWdgt;
} // namespace Ui

class SongVerseCheckWdgt : public AbstractCheckWdgt,
                           public Singleton<SongVerseCheckWdgt>
{
    Q_OBJECT

public:
    explicit SongVerseCheckWdgt(QWidget *argParent = nullptr);
    ~SongVerseCheckWdgt() override;

     void ShowData() override;

private:
     void SetDataToCheckInternal(const AbstractDataTypeSharedPtr &argData) override;
     void ShowCheckedDataWdgt(bool argDisplayData) override;

    Ui::SongVerseCheckWdgt *const ui = nullptr;
};

#endif // SONGVERSECHECKWDGT_H
