/*
Abir Mahmood
CSC 211H
Dr.Azhar
Honors Project 
*/
#ifndef RECYCLINGBINFINDER_H
#define RECYCLINGBINFINDER_H

#include <QWidget>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class RecyclingBinFinder; }
QT_END_NAMESPACE

class RecyclingBinFinder : public QWidget 
{
    Q_OBJECT

public:
    RecyclingBinFinder(QWidget *parent = nullptr);
    ~RecyclingBinFinder();
    QStringList binList; // to store information


private slots:

    void on_manButton_clicked();

    void on_qnsButton_clicked();
        void on_qnsButton_2_clicked();

    void on_bkButton_clicked();

    void on_bxButton_clicked();

    void on_siButton_clicked();

    void on_homeButton_clicked();
    void on_homeButton_2_clicked();

    void on_siButton_2_clicked();

private:
    Ui::RecyclingBinFinder *ui; // UI elements and layout
    void loadFile(); // File I/O and data loading function
};
#endif // RECYCLINGBINFINDER_H
