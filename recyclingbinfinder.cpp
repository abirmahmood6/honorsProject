/*
Abir Mahmood
CSC 211H
Dr.Azhar
Honors Project 
*/
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include "recyclingbinfinder.h"
#include "./ui_recyclingbinfinder.h"
#include "specificborough.h"
#include <QFile>



RecyclingBinFinder::RecyclingBinFinder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecyclingBinFinder)  // Dynamic memory allocation using 'new'
{
    ui->setupUi(this);
    loadFile(); // File I/O
}


RecyclingBinFinder::~RecyclingBinFinder()
{
    delete ui; // Dynamic memory deallocation using 'delete'
}


void RecyclingBinFinder::on_manButton_clicked()
{
    ui->displayWindow->clear();  // Updating UI element
    specificBorough man;
    man.setName("MAN");
    QStringList manList = man.boroList(binList);
    for(int i = 0; i<manList.length(); i++)
        ui->displayWindow->insertPlainText(manList[i]); // Updating UI element
}



void RecyclingBinFinder::on_qnsButton_clicked()
{
    ui->displayWindow->clear();
    specificBorough qns;
    qns.setName("QNS");
    QStringList qnsList = qns.boroList(binList);
    for(int i = 0; i<qnsList.length(); i++)
        ui->displayWindow->insertPlainText(qnsList[i]);
}


void RecyclingBinFinder::on_bkButton_clicked()
{
    ui->displayWindow->clear();
    specificBorough bk;
    bk.setName("BKN");
    QStringList bkList = bk.boroList(binList);
    for(int i = 0; i<bkList.length(); i++)
        ui->displayWindow->insertPlainText(bkList[i]);
}


void RecyclingBinFinder::on_bxButton_clicked()
{
    ui->displayWindow->clear();
    specificBorough bx;
    bx.setName("BX");
    QStringList bxList = bx.boroList(binList);
    for(int i = 0; i<bxList.length(); i++)
        ui->displayWindow->insertPlainText(bxList[i]);
}


void RecyclingBinFinder::on_siButton_clicked()
{
    ui->displayWindow->clear();
    specificBorough si;
    si.setName("SI");
    QStringList siList = si.boroList(binList);
    for(int i = 0; i<siList.length(); i++)
        ui->displayWindow->insertPlainText(siList[i]);
}

void RecyclingBinFinder::on_homeButton_clicked()
{
    ui->displayWindow->clear();
    for(int i = 0; i < 136; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(j == 3)
            {
               ui->displayWindow->insertPlainText(binList[(7*i)+j] + "\n");
            }
        }
    }
}

// Similar functions for other borough buttons

void RecyclingBinFinder::loadFile()
{
    QFile file(":/Public_Recycling_Bins.csv");   // File I/O
    if(!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.errorString();  // Standard Output (qDebug)
            return;
    }
    if(!file.exists())   //exception handing: throw exception when file fails to open
    {
        throw 1; // Exception handling
    }
    QTextStream test(&file); // File I/O
    while(!test.atEnd())
    {
        binList.append(test.readLine().split(","));   // Dynamic array manipulation
    }
}


void RecyclingBinFinder::on_siButton_2_clicked()
{
    exit(0); // System exit
}


void RecyclingBinFinder::on_qnsButton_2_clicked()
{
    ui->displayWindow->clear();
    ui->displayWindow->setPlainText("Welcome to RecycleBinFinder NYC, where the magic of recycling comes alive for our little eco-warriors! 🌿🗽 Join us on an exciting adventure to discover and compare recycling bins in the heart of New York City, all designed just for you. Explore the world of sustainability in a way that's fun, engaging, and perfect for kids who dream of making our planet a greener, cleaner place. Let's embark on this journey together, empowering the next generation to recycle, discover, and make a positive impact right here in NYC and beyond! 🌍✨");  // Updating UI element

}


void RecyclingBinFinder::on_homeButton_2_clicked()
{
    ui->displayWindow->clear();        // Displaying information on UI element

 ui->displayWindow->setPlainText("Recycling Rules for Super Earth Helpers\n\n"
    "🌍 What to Recycle:\n"
    "Sort It Out: Split your recycling into two squads. Use a bin with a cool lid or a clear bag.\n"
    "Cardboard Alert: Flatten and tie bundled cardboard next to bins. NO cardboard boxes as bins!\n\n"
    "🤖 How to Sort Recycling:\n"
    "Metal, Glass, Plastic, Cartons: Team up! Put metal, glass, plastic, and cartons together in a labeled bin or clear bag. Rinse containers for superhero cleanliness!\n"
    "Mixed Paper and Cardboard: Keep them buddies! Recycle mixed paper in a labeled bin. Bundle cardboard and place it nearby.\n\n"
    "♻️ What Can Be Recycled:\n"
    "Metal Mania: Aluminum foil, trays, caps, lids, even wire hangers!\n"
    "Glass Gang: Bottles and jars only, no superhero glasses allowed.\n"
    "Plastic Patrol: Rigid plastics, like containers, cups, and toys (batteries out).\n"
    "Carton Crew: Milk and soup cartons, juice boxes - but NOT with mixed paper.\n\n"
    "🚫 What to Keep Out:\n"
    "Tanglers Trouble: Cables, wires, and other tangly stuff.\n"
    "Bowling Balls Ban: No sports balls either.\n Source: https://www.nyc.gov/assets/dsny/site/services/recycling/what-to-recycle \n");
}

