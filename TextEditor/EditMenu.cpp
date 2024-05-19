#include <QAction>
#include <QColorDialog>
#include <QFontDialog>
#include "EditMenu.h"
#include "Editor.h"
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

    QAction* actStyle = new QAction(tr("color"),this);
    this->addAction(actStyle);
    connect(actStyle,SIGNAL(triggered(bool)),this,SLOT(OnColor()));

    QAction* actFont = new QAction(tr("font"),this);
    this->addAction(actFont);
    connect(actFont,SIGNAL(triggered(bool)),this,SLOT(OnFont()));

    QAction* actCodec = new QAction(tr("code"),this);
    this->addAction(actCodec);
    connect(actCodec,SIGNAL(triggered(bool)),this,SLOT(OnCodec()));

    choseCodeDialog = new ChoseCodeDialog(mainWindow);
}

EditMenu::~EditMenu()
{
    delete choseCodeDialog;
}

void EditMenu::OnCopy()
{
    mainWindow->editor->copy();
}

void EditMenu::OnCut()
{
    mainWindow->editor->cut();
}

void EditMenu::OnRedo()
{
    mainWindow->editor->redo();
}

void EditMenu::OnUndo()
{
    mainWindow->editor->undo();
}

void EditMenu::OnPaste()
{
    mainWindow->editor->paste();
}

// 修改字体样式
void EditMenu::OnColor()
{
    QColor color;
    QColor c = QColorDialog::getColor(color,this,"颜色选择框");
    if(c.isValid())
    {
        color = c;
        // 设置鼠标选中的文本颜色
        mainWindow->editor->setTextColor(c);
    }
}

void EditMenu::OnFont()
{
    bool ok;
    QFont font;
    QFont f = QFontDialog::getFont(&ok,font,this,"选择文本框要设置的字体");    //基础的用户字体对话框
    if(ok)
    {
        font = f;
        // 设置鼠标选中的文本的字体
        mainWindow->editor->setCurrentFont(f);
    }
}

// 修改编码
void EditMenu::OnCodec()
{
    choseCodeDialog->resize(200,350);
    // 调出修改编码对话框
    if(choseCodeDialog->exec()==QDialog::Accepted)
    {
        choseCodeDialog->Accepted();
    }
    else
    {
        choseCodeDialog->Reject();
    }
}
