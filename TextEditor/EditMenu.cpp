#include "EditMenu.h"
#include <QAction>
#include "mainwindow.h"
#include "ChoseCodeDialog.h"

EditMenu::EditMenu(const QString& title,MainWindow* parent):QMenu(title,parent)
{
    mainWindow = parent;

    QAction* actUndo = new QAction(tr("undo"),this);
    this->addAction(actUndo);
    connect(actUndo,SIGNAL(triggered(bool)),this,SLOT(OnUndo()));
    actUndo->setShortcut(QKeySequence(Qt::CTRL|Qt::Key_Z));             // 设置撤回快捷键

    QAction* actRedo = new QAction(tr("redo"),this);
    this->addAction(actRedo);
    connect(actRedo,SIGNAL(triggered(bool)),this,SLOT(OnRedo()));
    actRedo->setShortcut(QKeySequence(Qt::CTRL|Qt::Key_Y));             // 设置取消撤回快捷键

    QAction* actCopy = new QAction(tr("copy"),this);
    this->addAction(actCopy);
    connect(actCopy,SIGNAL(triggered(bool)),this,SLOT(OnCopy()));
    actCopy->setShortcut(QKeySequence(Qt::CTRL|Qt::Key_C));             // 设置复制快捷键

    QAction* actCut = new QAction(tr("cut"),this);
    this->addAction(actCut);
    connect(actCut,SIGNAL(triggered(bool)),this,SLOT(OnCut()));
    actCut->setShortcut(QKeySequence(Qt::CTRL|Qt::Key_X));              // 设置剪切快捷键

    QAction* actPaste = new QAction(tr("paste"),this);
    this->addAction(actPaste);
    connect(actPaste,SIGNAL(triggered(bool)),this,SLOT(OnPaste()));
    actPaste->setShortcut(QKeySequence(Qt::CTRL|Qt::Key_V));            // 设置粘贴快捷键

    this->addSeparator();

    QAction* actStyle = new QAction(tr("style"),this);
    this->addAction(actStyle);
    connect(actStyle,SIGNAL(triggered(bool)),this,SLOT(OnStyle()));

    QAction* actCodec = new QAction(tr("code"),this);
    this->addAction(actCodec);
    connect(actCodec,SIGNAL(triggered(bool)),this,SLOT(OnCodec()));

    choseCodeDialog = new ChoseCodeDialog(mainWindow);
}

void EditMenu::OnCopy()
{

}

void EditMenu::OnCut()
{

}

void EditMenu::OnRedo()
{

}

void EditMenu::OnUndo()
{

}

void EditMenu::OnPaste()
{

}

void EditMenu::OnStyle()
{

}

void EditMenu::OnCodec()
{
    choseCodeDialog->resize(200,350);
    if(choseCodeDialog->exec()==QDialog::Accepted)
    {
        choseCodeDialog->Accepted();
    }
    else
    {
        choseCodeDialog->Reject();
    }
}
