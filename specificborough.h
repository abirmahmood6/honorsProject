/*
Abir Mahmood
CSC 211H
Dr.Azhar
Honors Project
 */
#ifndef SPECIFICBOROUGH_H
#define SPECIFICBOROUGH_H

#include "borough.h"
#include <QTextStream>

class specificBorough:public borough
{
public:
    specificBorough();
    QStringList boroList(QStringList cityList);
};

#endif // SPECIFICBOROUGH_H
