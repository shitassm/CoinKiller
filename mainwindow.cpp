#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "filesystem.h"

#include "leveleditorwindow.h"
#include "sillytest.h" // REMOVE ME!!

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About that thing you're using", "CoinKiller v1.0 -- by StapleButter\n\nhttp://kuribo64.net/ or whatever\n\noh and this is free software, if you paid for it, you got scammed");
}

void MainWindow::on_actionLoadROM_triggered()
{
    qDebug("load ROM");

    // testing shit
    QFile lol("C:/Documents/1-1.sarc");
    qDebug("%s", lol.exists()?"good":"bad");

    ExternalFilesystem* exfs = new ExternalFilesystem("C:/Documents");
    ExternalFile* exfile = (ExternalFile*)exfs->openFile("/1-1.sarc");
    SarcFilesystem* sarc = new SarcFilesystem(exfile);

    SarcFilesystem* sarc2 = new SarcFilesystem(exfs->openFile("/J_Kihon.sarc"));

    /*FileBase* durp = sarc->openFile("/course/course1_bgdatL1.bin");
    durp->open(); durp->seek(0);
    quint32 da = durp->read32(), db = durp->read32();
    qDebug("%08X %08X %08X", da, db, durp->size());*/

    // full tile: 24x24
    // gfx: 20x20


    LevelEditorWindow* crap = new LevelEditorWindow(this, sarc);//new Ctpk(sarc2->openFile("/BG_tex/J_Kihon.ctpk")));
    crap->show(); // derp
}

void MainWindow::on_actionDebug_test_triggered()
{
    SillyTest* silly = new SillyTest(this);
    silly->show();
}
