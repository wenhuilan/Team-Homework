#include "FileMenu.h"
#include "mainwindow.h"
#include <QAction>

FileMenu::FileMenu(const QString& title,MainWindow* parent) : QMenu(title,parent)
{
    QAction* actNew = new QAction(tr("new"),this);
    this->addAction(actNew);
    connect(actNew,SIGNAL(triggered(bool)),this,SLOT(OnFileNew()));

    QAction* actOpen = new QAction(tr("open"),this);
    this->addAction(actOpen);
    connect(actOpen,SIGNAL(triggered(bool)),this,SLOT(OnFileOpen()));


    QAction* actSave = new QAction(tr("save"),this);
    this->addAction(actSave);
    connect(actSave,SIGNAL(triggered(bool)),this,SLOT(OnFileSave()));

    this->addSeparator();

    QAction* actExit = new QAction(tr("exit"),this);
    this->addAction(actExit);
    connect(actExit,SIGNAL(triggered(bool)),this,SLOT(OnExit()));

}

void FileMenu::OnFileNew()
{

}

void FileMenu::OnFileOpen()
{

}

void FileMenu::OnFileSave()
{

}

void FileMenu::OnExit()
{

}

