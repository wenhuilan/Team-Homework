#include "mainwindow.h"
#include <QMenuBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "./ui_mainwindow.h"
#include "EditMenu.h"
#include "FileMenu.h"
#include "Editor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menuBar = new QMenuBar(this);
    this->setMenuBar(menuBar);

    QMenu* fileMenu = new FileMenu(tr("file"),this);
    menuBar->addMenu(fileMenu);
    menuBar->addSeparator();

    QMenu* editMenu = new EditMenu(tr("edit"),this);
    menuBar->addMenu(editMenu);
    menuBar->addSeparator();

    editor = new Editor(this);
    this->setCentralWidget(editor);
}

MainWindow::~MainWindow()
{
    delete ui;
}
