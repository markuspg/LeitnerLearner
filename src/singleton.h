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

#ifndef SINGLETON_H
#define SINGLETON_H

#include <QException>

#include <atomic>

// InstanceExistsException -----------------------------------------------------

class InstanceExistsException : public QException
{
    InstanceExistsException* clone() const override;
    void raise() const override;
};

// Singleton -------------------------------------------------------------------

template<typename T>
class Singleton
{
public:
    Singleton() { if (instanceExists.test_and_set()) { throw  InstanceExistsException{}; } }
    ~Singleton() { instanceExists.clear(); }

private:
    static std::atomic_flag instanceExists;
};

template<typename T>
std::atomic_flag Singleton<T>::instanceExists = ATOMIC_FLAG_INIT;

#endif // SINGLETON_H
