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



void RecyclingBinFinder::on_siButton_2_clicked()
{
    exit(0); // System exit
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


void RecyclingBinFinder::on_qnsButton_2_clicked()
{
    ui->displayWindow->clear();
    ui->displayWindow->setPlainText("Welcome to RecycleBinFinder NYC, where the magic of recycling comes alive for our little eco-warriors! 🌿🗽 Join us on an exciting adventure to discover and compare recycling bins in the heart of New York City, all designed just for you. Explore the world of sustainability in a way that's fun, engaging, and perfect for kids who dream of making our planet a greener, cleaner place. Let's embark on this journey together, empowering the next generation to recycle, discover, and make a positive impact right here in NYC and beyond! 🌍✨");  // Updating UI element

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



void RecyclingBinFinder::on_homeButton_2_clicked()
{
    ui->displayWindow->clear();        // Displaying information on UI element

 ui->displayWindow->setPlainText("Recycling Rules for NYC\n\n"
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

void RecyclingBinFinder::on_homeButton_3_clicked()
{
     ui->displayWindow->clear();
    ui->displayWindow->setPlainText(
        "Philadelphia Policy \nHey there, awesome recyclers! 🌟\n\n"
        "1. **Sort it Out:**\n"
        "   - Use different bins for different things.\n"
        "   - Kitchen bin for clean bottles and cans.\n"
        "   - Bathroom bin for toilet paper rolls and clean shampoo bottles.\n"
        "   - Office bin for used paper and mail.\n"
        "   - But guess what? In Philly, you can toss all recyclables together!\n\n"

        "2. **Keep it Clean and Dry:**\n"
        "   - No food or liquid in the recycling bin!\n"
        "   - Rinse bottles, cans, and plastic, then let them dry.\n"
        "   - Get a lid for your bin or cover it up to keep everything dry and happy.\n\n"

        "3. **When in Doubt, Leave it Out:**\n"
        "   - Don't stress. If you're not sure, it's cool to throw it in the regular trash. Better safe than sorry!\n\n"

        "4. **Use the Right Container:**\n"
        "   - Grab a recycling bin from the city, or use your own.\n"
        "   - Make sure it's not bigger than 32 gallons or heavier than 40 pounds.\n"
        "   - And no plastic bags or cardboard boxes, they can cause trouble!\n\n"

        "Remember, you're saving the planet by being a recycling superhero! 🌍♻️ Keep it up!"
        );
}



RecyclingBinFinder::RecyclingBinFinder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecyclingBinFinder)  // Dynamic memory allocation using 'new'
{
    ui->setupUi(this);
    loadFile(); // File I/O
}






void RecyclingBinFinder::on_homeButton_4_clicked()
{
    ui->displayWindow->clear();
    ui->displayWindow->setPlainText(
        "1. New Jersey Police \n **Is recycling important?**\n"
        "   - Yes! Recycling helps our environment and economy. It saves resources, energy, and reduces pollution.\n\n"

        "2. **Do businesses and schools in NJ have to recycle?**\n"
        "   - Absolutely! It's the law in New Jersey. Everyone, from homes to schools and businesses, must recycle.\n\n"

        "3. **Why do recycling programs vary in NJ?**\n"
        "   - Counties decide their own recycling plans, so programs might differ. Check your local rules for specifics.\n\n"

        "4. **What's dual stream and single stream recycling?**\n"
        "   - Dual: Separate bins for paper and containers. Single: All recyclables in one bin. Both are cool, but single is more common!\n\n"

        "5. **What happens to recyclables after I toss them in the bin?**\n"
        "   - They go to a recycling center. Machines and people sort them, then they're turned into new stuff, like paper, cans, and bottles!\n\n"

        "6. **What do the numbers on plastic products mean?**\n"
        "   - Those numbers help identify plastic types. Check your local rules to know which ones are okay in your recycling.\n\n"

        "7. **Can Styrofoam be recycled?**\n"
        "   - Yes, but it's tricky. Not many places do it. Check with your local recycling program for guidance.\n\n"

        "8. **Can pizza boxes be recycled?**\n"
        "   - Maybe. It depends on your local program. Clean parts are usually okay, but check first!\n\n"

        "9. **Should I leave caps on plastic bottles for recycling?**\n"
        "   - Yup! It's okay now. The caps can be recycled too. Check with your local rules just to be sure.\n\n"

        "10. **Can I put shredded paper in the recycling bin?**\n"
        "    - Nope. Shredded paper needs special recycling. Ask your local recycling program about it.\n\n"

        "11. **Can I toss plastic bags in the recycling bin?**\n"
        "    - No way! Plastic bags go back to the store for special recycling. They cause problems at regular recycling centers.\n\n"

        "12. **Is it okay to toss unsure items into the recycling bin?**\n"
        "    - Nope. If you're not sure, check with your local recycling program. Putting wrong stuff in can mess up the recycling process.\n\n"
        );


}

