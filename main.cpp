/*
Abir Mahmood
CSC 211H
Dr.Azhar
Honors Project 
*/

#include <QApplication>
#include <QScreen>
#include "recyclingbinfinder.h"

int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);
        RecyclingBinFinder w;



        // Center the main window on the screen
        QScreen *primaryScreen = QGuiApplication::primaryScreen();
        QRect screenGeometry = primaryScreen->geometry();
        int x = (screenGeometry.width() - w.width()) / 2;
        int y = (screenGeometry.height() - w.height()) / 2;
        w.setGeometry(x, y, w.width(), w.height());

        // Show the main window after setting its geometry
        w.show();

        return a.exec();
    }
    catch(int num)
    {
        return 0;
    }
}