#include <QAction>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include "FileMenu.h"
#include "mainwindow.h"
#include "Editor.h"


FileMenu::FileMenu(const QString& title,MainWindow* parent) : QMenu(title,parent)
{
    mainWindow = parent;
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

void FileMenu::SetCurFileName(const QString &fileName)
{
    curFileName = fileName;
    mainWindow->editor->document()->setModified(false);

    QString titleName;
    if (fileName.isEmpty())
        titleName = "untitled.txt";
    else
        titleName = QFileInfo(fileName).fileName();
    setWindowModified(false);
}

QString FileMenu::ShowFileDialog(QFileDialog::AcceptMode mode)
{
    //这个函数可以实现对于文件的打开以及保存
    QString res = "";
    QFileDialog fd(this);
    QStringList filters;

    filters.append("Text Files (*.txt)");
    filters.append("All Files (*)");

    fd.setWindowTitle("文件");//对话框标题
    fd.setAcceptMode(mode);
    //        fd.setFilter();

    if( mode == QFileDialog::AcceptOpen )//是打开文件还是保存文件
    {
        fd.setFileMode(QFileDialog::ExistingFile);//设置可选单个已存在的文件
    }

    if( fd.exec() == QFileDialog::Accepted )
    {
        res = fd.selectedFiles().first();    //函数返回装有选中的文件的绝对路径的链表
        qDebug()<<fd.selectedFiles();
        qDebug()<<res;
    }

    return res;
}

QString FileMenu::SaveCurFile(QString path)
{
    QString res = path;

    if( res == "" )
        res = ShowFileDialog(QFileDialog::AcceptSave);
    if( res != "" )
    {
        QFile file(res);
        if( file.open(QIODevice::WriteOnly | QIODevice::Text) )
        {
            QTextStream out(&file);
            out << mainWindow->editor->toPlainText();           // 简单的保存字符，并没有保存字体和颜色相关信息，此处需改进
            file.close();
            mainWindow->setWindowTitle("Text - [ " + res + " ]");
        }
        else
        {
            // ShowErrorMessage(QString("Save file error!") + "\"" + ret + "\"");
            res = "";
        }
    }
    return res;
}

void FileMenu::OnFileNew()
{
    QMessageBox::StandardButton ok=QMessageBox::warning(this,tr("Warning"),
                                                          tr("创建新文件？"),
                                                          QMessageBox::Yes | QMessageBox::Default,
                                                          QMessageBox::No);//通过QMessagebox里面的东西来

    curFileName.clear();
    mainWindow->editor->setText(QString());
    if( curFileName == ""&& ok==QMessageBox::StandardButton::Yes)
        curFileName = ShowFileDialog(QFileDialog::AcceptSave);
}

void FileMenu::OnFileOpen()
{
    QString path = ShowFileDialog(QFileDialog::AcceptOpen);
    SetCurFileName(path);
    if(path != "")
    {
        QFile file(path);
        if( file.open(QIODevice::ReadOnly | QIODevice::Text) )
        {
            mainWindow->editor->setPlainText(QString(file.readAll()));      //读取文件的所有数据并导入到编辑组件
            file.close();
            mainWindow->setWindowTitle("text - [ " + path + " ]");
        }
        else
        {
            //ShowErrorMessage(QString("Open file error!") + "\"" + path + "\"");//自定义的一个错误提示对话框
        }
    }
}

void FileMenu::OnFileSave()
{
    QString path = SaveCurFile(curFileName);

    if( path != "" )
    {
        curFileName = path;
    }
}

void FileMenu::OnExit()
{
    mainWindow->close();
}

