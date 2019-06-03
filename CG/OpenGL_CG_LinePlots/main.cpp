#include <QApplication>
#include <QMessageBox>
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

    CGWidget w(nullptr, "Line Plots", isFullScreen);
    w.show();

    return app.exec();
}
