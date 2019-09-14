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

#ifndef BACKEND_H
#define BACKEND_H

#include "abstractdatatype.h"

#include <QObject>

class AbstractStorageBackend;
class ConfigurationHandler;

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int savedVerses READ GetSavedVerses() NOTIFY SavedVersesChanged)
    Q_PROPERTY(QString checkedBook READ GetCheckedBook() NOTIFY CheckedBookChanged)
    Q_PROPERTY(int checkedChapterNo READ GetCheckedChapterNo() NOTIFY CheckedChapterNoChanged)
    Q_PROPERTY(int checkedVerseNo READ GetCheckedVerseNo() NOTIFY CheckedVerseNoChanged)
    Q_PROPERTY(QString checkedVerseText READ GetCheckedVerseText() NOTIFY CheckedVerseTextChanged)

public:
    Backend(QObject *argParent = nullptr);

    QString GetCheckedBook() const { return currCheckedBook; }
    int GetCheckedChapterNo() const noexcept { return currCheckedChapterNo; }
    int GetCheckedVerseNo() const noexcept { return currCheckedVerseNo; }
    QString GetCheckedVerseText() const { return currCheckedVerseText; }
    ConfigurationHandler* GetConfigHndlr() const noexcept { return configHndlr; }
    int GetSavedVerses() const noexcept { return savedVersesQty; }
    AbstractStorageBackend* GetStorageBcknd() const noexcept { return storageBackend; }
    void Initialize();
    Q_INVOKABLE void saveVerse(const QString &argBook, int argChapterNo,
                               int argVerseNo, const QString &argVerseText);

public slots:
    void requestNextVerse();
    void verseAnsweredRightly();
    void verseAnsweredWrongly();

signals:
    void CheckedBookChanged();
    void CheckedChapterNoChanged();
    void CheckedVerseNoChanged();
    void CheckedVerseTextChanged();
    void SavedVersesChanged();

private:
    ConfigurationHandler *const configHndlr = nullptr;
    QString currCheckedBook;
    int currCheckedChapterNo = 0;
    int currCheckedVerseNo = 0;
    QString currCheckedVerseText;
    AbstractDataTypeSharedPtr currDataItem;
    unsigned int savedVersesQty = 0u;
    AbstractStorageBackend *const storageBackend = nullptr;

private slots:
    void RetrieveNewVerse(const AbstractDataTypeSharedPtr &argDataPtr);
    void VerseGotSuccessfullySaved();
};

#endif // BACKEND_H
