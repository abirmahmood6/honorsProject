#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recyclingbinfinder.h"  // Include the header file for RecyclingBinFinder

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the login button signal to the login slot
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoginClicked()
{
    // Replace 'your_username' and 'your_password' with the actual username and password
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    // Simple check for username and password
    if (username == "your_username" && password == "your_password") {
        // Successful login, open RecyclingBinFinder window
        RecyclingBinFinder *recyclingBinFinder = new RecyclingBinFinder(this);
        recyclingBinFinder->show();
        this->hide();  // Hide the login window
    } else {
        // Display an error message or handle incorrect login credentials
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password. Please try again.");
    }
}
