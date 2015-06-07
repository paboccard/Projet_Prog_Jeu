#include "MainWindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

	QString locale = "fr"; //QLocale::system().name().section('_', 0, 0);
	QTranslator translator;
	translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
	a.installTranslator(&translator);

    MainWindow w;
    w.show();

    return a.exec();
}
