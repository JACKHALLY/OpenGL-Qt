#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include "cgwidget.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    bool isFullScreen = false;
    int screenChoice;
    screenChoice = QMessageBox::information(nullptr,
                                            "Start FullScreen",
                                            "Would you want to run in fullscreen mode?",
                                             QMessageBox::Yes,
                                             QMessageBox::No | QMessageBox::Default);
    switch(screenChoice)
    {
    case QMessageBox::Yes:
        isFullScreen = true;
        break;
    case QMessageBox::No:
        isFullScreen = false;
        break;
    }

    QString dataFile = QFileDialog::getOpenFileName(nullptr, "select data file",
                                                    ".");
    if(dataFile.isEmpty())
    {
        QMessageBox::information(nullptr,
                                 "Tips",
                                 "No data file, bye!",
                                 QMessageBox::Ok);
        return 0;
    }

    CGWidget w(nullptr, "Polylines", isFullScreen, dataFile);
    w.show();

    return app.exec();
}
