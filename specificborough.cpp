/*
Abir Mahmood
CSC 211H
Dr.Azhar
Honors Project
 */
#include "specificborough.h"
#include <QStringList>

specificBorough::specificBorough()
{
}

QStringList specificBorough::boroList(QStringList cityList)
{
    QStringList list;
    for(int i = 0; i < 136; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if((cityList[(7*i)] == boroughName) && j == 3)
            {
                list.append(cityList[(7*i)+j] + "\n");
            }
        }
    }
    return list;
}
