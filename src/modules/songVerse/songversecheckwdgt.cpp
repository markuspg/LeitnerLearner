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

#include "songverse.h"
#include "songversecheckwdgt.h"
#include "ui_songversecheckwdgt.h"

#include <QDebug>

SongVerseCheckWdgt::SongVerseCheckWdgt(QWidget *const argParent) :
    AbstractCheckWdgt{argParent},
    ui{new Ui::SongVerseCheckWdgt}
{
    ui->setupUi(this);
    ui->PTESongVerseText->hide();
}

SongVerseCheckWdgt::~SongVerseCheckWdgt()
{
    delete ui;
}

void SongVerseCheckWdgt::SetDataToCheckInternal(
        const AbstractDataTypeSharedPtr &argData)
{
    const auto verseData = std::dynamic_pointer_cast<SongVerse>(argData);
    if (!verseData) {
        qWarning() << "Data of wrong type passed to SongVerseCheckWdgt";
        return;
    }
    ui->LESongName->setText(verseData->GetSongName());
    ui->LESongVerseNo->setText(QString{verseData->GetVerseNo()});
    ui->PTESongVerseText->setPlainText(verseData->GetVerseText());
}

void SongVerseCheckWdgt::ShowCheckedDataWdgt(const bool argDisplayData)
{
    if (argDisplayData == true) {
        ui->PTESongVerseText->show();
    } else {
        ui->PTESongVerseText->hide();
    }
}

void SongVerseCheckWdgt::ShowData()
{
    ShowCheckedDataWdgt(true);
}
