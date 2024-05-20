#include "PictureMenu.h"
#include "mainwindow.h"
#include <QAction>
#include <QFileDialog>
#include <QDebug>
#include "Editor.h"


    PictureMenu::PictureMenu(const QString& title,MainWindow* parent,MainWindow *ui) : QMenu(title,parent)

{

      mainWindow = parent;
    QAction* actNew = new QAction(tr("打开图片"),this);

    this->addAction(actNew);
    connect(actNew,SIGNAL(triggered(bool)),this,SLOT(OnPicture()));

    QAction* actOpen = new QAction(tr("打开视频"),this);

    this->addAction(actOpen);
    connect(actOpen,SIGNAL(triggered(bool)),this,SLOT(OnVedio()));

}


void PictureMenu::OnPicture()
{

    QString filename = QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.jpg)\n(*.png)"));
     QImage image(filename); // 加载图像
    if(!image.isNull())
     {
         mainWindow->editor->clear();
         // 插入图片到编辑器中
         QTextCursor cursor =  mainWindow->editor->textCursor();
         QTextImageFormat imageFormat;
         imageFormat.setName(filename);
         imageFormat.setWidth(image.width());
         imageFormat.setHeight(image.height());
         cursor.insertImage(imageFormat);
     }
    else{
         // ui->statusbar->showMessage(tr("Save Image Fail!!"),3000);
         return;
    }

}

void PictureMenu::OnVedio()
{



}
