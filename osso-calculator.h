/*
    osso-calculator.h - OSSO Calculator
    Copyright (C) 2011  Pali Rohár <pali.rohar@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef OSSO_CALCULATOR_H
#define OSSO_CALCULATOR_H

#include <QObject>

class QString;
class QMainWindow;

class OssoCalculatorUI;

class OssoCalculator : public QObject {

	Q_OBJECT
	Q_CLASSINFO("D-Bus Interface", "com.nokia.osso_calculator")

	public:
		OssoCalculator(QObject * parent = NULL);
		~OssoCalculator();

	public slots:
		Q_SCRIPTABLE void top_application();

	private:
		OssoCalculatorUI * ui;
		QMainWindow * window;
		QString expression;
		QString memory;
		int brackets;

		QString executeCommand(const QString &command);

	private slots:
		void clickedButton(const QString &name);

};

#endif
