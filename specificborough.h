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

class specificBorough:public borough  // Inheriting from the 'borough' class
{
public:
    specificBorough(); // Default constructor
    QStringList boroList(QStringList cityList); // Function for filtering and extracting information from NYCData
};

#endif // SPECIFICBOROUGH_H
