#include "ThemeMenu.h"
#include "mainwindow.h"
#include <QAction>
#include "Editor.h"


ThemeMenu::ThemeMenu(const QString& title,MainWindow* parent,MainWindow *ui) : QMenu(title,parent)

{

    mainWindow = parent;

    QIcon darkIcon(":/dark.png");
    QIcon lightIcon(":/light.png");
    QIcon eyeIcon(":/eye.png");


    QAction* actDark = new QAction(tr("深色主题"),this);
    actDark->setIcon(darkIcon);
    this->addAction(actDark);
    connect(actDark,SIGNAL(triggered(bool)),this,SLOT(OnDark()));

    QAction* actLight = new QAction(tr("浅色主题"),this);
    actLight->setIcon(lightIcon);
    this->addAction(actLight);
    connect(actLight,SIGNAL(triggered(bool)),this,SLOT(OnLight()));

    QAction* actProtect = new QAction(tr("护眼主题"),this);
    actProtect->setIcon(eyeIcon);
    this->addAction(actProtect);
    connect(actProtect,SIGNAL(triggered(bool)),this,SLOT(OnProtect()));

}


void ThemeMenu::OnDark()
{
    mainWindow->editor->setStyleSheet("background-color:#6c6c6c;");
     mainWindow->setStyleSheet("QMainWindow { background-color: black; }");


}

void ThemeMenu::OnLight()
{
    mainWindow->editor->setStyleSheet("background-color:#fofofo;");
    mainWindow->setStyleSheet("QMainWindow { background-color: #fff; }");
}

void ThemeMenu::OnProtect()
{
    mainWindow->editor->setStyleSheet("background-color:#c9ffdb;");
    mainWindow->setStyleSheet("QMainWindow { background-color: #8effbb; }");
}
