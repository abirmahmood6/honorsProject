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
     // Default constructor 
}

QStringList specificBorough::boroList(QStringList cityList)
{
    QStringList list;
      // Loop through the cityList
    for(int i = 0; i < 136; i++)
    {
        for(int j = 0; j < 7; j++)
        
        {  // Loop through the cityList
            if((cityList[(7*i)] == boroughName) && j == 3)
            {
                // Append the information to the list
                list.append(cityList[(7*i)+j] + "\n");
            }
        }
    }
     // returnign the filtered list
    return list;
}
