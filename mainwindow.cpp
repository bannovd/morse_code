#include "mainwindow.h"
#include "ui_mainwindow.h"


bool isMorse(const QString & str)
{
    QRegExp rx = QRegExp("^[\\.\\-\\s]*$");
    rx.indexIn(str);
    return rx.matchedLength() == str.length();
}


QString translateToMorse(const QString & str)
{
    return str;
}

QString translateFromMorse(const QString & str)
{
    return str;
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_loadFromFile, SIGNAL (triggered()), this, SLOT (loadFromFile()));
    connect(ui->action_saveToFile, SIGNAL (triggered()), this, SLOT (saveToFile()));
    connect(ui->te_left, SIGNAL (textChanged()), this, SLOT (translateText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home/", tr("Text Files (*.txt)"));
    QFile file(fileName);
    QString line;
    ui->te_left->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            ui->te_left->setText(ui->te_left->toPlainText() + line);
        }
    }
    file.close();
}

void MainWindow::saveToFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "/home/untitled.txt", tr("Text Files (*.txt)"));
    if (fileName != "")
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {

        } else {
            QTextStream stream(&file);
            stream << ui->te_right->toPlainText();
            stream.flush();
            file.close();
        }
    }
}

void MainWindow::translateText()
{
    QString str = ui->te_left->toPlainText();
    bool isMorseText = isMorse(str);
    ui->te_right->clear();
    if (isMorseText)
    {
        ui->label_left->setText("Азбука Морзе");
        ui->label_right->setText("Английский");
        ui->te_right->setText(translator.fromMorseToEn(str));
    }
    else
    {
        ui->label_left->setText("Английский");
        ui->label_right->setText("Азбука Морзе");
        ui->te_right->setText(translator.fromEnToMorse(str));
    }
}


