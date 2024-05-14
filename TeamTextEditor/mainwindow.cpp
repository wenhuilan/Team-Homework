#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("new text");
    this->resize(800,600);

    //=====最顶上的 menu =====
    menuBar = new QMenuBar(this);
    this->setMenuBar(menuBar);

    QMenu *menuFile = new QMenu(tr("File"),this);
    QMenu *menuEdit = new QMenu(tr("Edit"),this);
    QMenu *menuStyle = new QMenu(tr("Style"),this);

    menuBar->addMenu(menuFile);
    menuBar->addMenu(menuEdit);
    menuBar->addMenu(menuStyle);

    //+++++ 菜单功能待添加 +++++
    QAction* newAct = new QAction(tr("new"),this);
    QAction* openAct = new QAction(tr("open"),this);
    QAction* saveAct = new QAction(tr("save"),this);
    QAction* exitAct = new QAction(tr("exit"),this);
    menuFile->addAction(newAct);
    menuFile->addAction(openAct);
    menuFile->addAction(exitAct);
    menuFile->addAction(saveAct);
    menuFile->addSeparator();

    // 文件菜单栏的消息处理
    connect(newAct,SIGNAL(triggered(bool)),this,SLOT(OnNewFile()));
    connect(openAct,SIGNAL(triggered(bool)),this,SLOT(OnOpenFile()));
    connect(exitAct,SIGNAL(triggered(bool)),this,SLOT(OnExit()));
    connect(saveAct,SIGNAL(triggered(bool)),this,SLOT(OnSaveFile()));


    QAction* copyAct = new QAction(tr("copy"),this);
    QAction* cutAct = new QAction(tr("cut"),this);
    QAction* pasteAct = new QAction(tr("paste"),this);
    QAction* undoAct = new QAction(tr("undo"),this);
    QAction* redoAct = new QAction(tr("redo"),this);
    menuEdit->addAction(copyAct);
    menuEdit->addAction(cutAct);
    menuEdit->addAction(pasteAct);
    menuEdit->addAction(undoAct);
    menuEdit->addAction(redoAct);
    menuEdit->addSeparator();

    // 编辑菜单栏消息处理
    connect(copyAct,SIGNAL(triggered(bool)),this,SLOT(OnTextCopy()));
    connect(cutAct,SIGNAL(triggered(bool)),this,SLOT(OnTextCut()));
    connect(pasteAct,SIGNAL(triggered(bool)),this,SLOT(OnTextPaste()));
    connect(undoAct,SIGNAL(triggered(bool)),this,SLOT(OnTextUndo()));
    connect(redoAct,SIGNAL(triggered(bool)),this,SLOT(OnTextRedo()));



    QAction* styleAct = new QAction(tr("style"),this);
    QAction* colorAct = new QAction(tr("color"),this);
    menuStyle->addAction(styleAct);
    menuStyle->addAction(colorAct);
    menuStyle->addSeparator();
    //样式菜单栏的消息处理
    connect(styleAct,SIGNAL(triggered(bool)),this,SLOT(OnTextFont()));
    connect(cutAct,SIGNAL(triggered(bool)),this,SLOT(OnTextColor()));


    //===== 工具栏 =====
    toolBar = new QToolBar(this);
    this->addToolBar(toolBar);
    toolBar->setFloatable(false);//设置不允许浮动
    toolBar->setMovable(false);//设置不允许移动
    toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);//设置工具项为图片在文字上方

    QAction *testAction = new QAction("Test 12345",this);
    toolBar->addAction(testAction);
    //+++++ 更多工具待实现 +++++

    //===== 主要部分 =====
    textEdit = new QTextEdit(this);
    QFont font = QFont("宋体",18,QFont::Normal,true);
    textEdit->setText(tr("welcome to this editor"));

    this->setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//实现对于文件的打开以及保存
QString MainWindow::ShowFileDialog(QFileDialog::AcceptMode mode)
{

    QString res = "";
    QFileDialog fd(this);
    QStringList filters;

    filters.append("Text Files (*.txt)");
    filters.append("All Files (*)");

    fd.setWindowTitle("文件");                          //对话框标题
    fd.setAcceptMode(mode);
    //fd.setFilter();

    if( mode == QFileDialog::AcceptOpen )               //是打开文件还是保存文件
    {
        fd.setFileMode(QFileDialog::ExistingFile);      //设置可选单个已存在的文件
    }
    if( fd.exec() == QFileDialog::Accepted )
    {
        res = fd.selectedFiles()[0];                    //函数返回装有选中的文件的绝对路径的链表
    }

    return res;
}

// 创建新文件
void MainWindow::OnNewFile()
{
    //弹出对话框
    QMessageBox::StandardButton ok = QMessageBox::warning(this,tr("Warning"),tr("do you want to save current file?"),
                                                          QMessageBox::Yes | QMessageBox::Default,
                                                          QMessageBox::No);

    m_fileName.clear();
    textEdit->setText(QString());
    if(m_fileName=="" || ok==QMessageBox::StandardButton::No)
        m_fileName = ShowFileDialog(QFileDialog::AcceptSave);
    else
    {
        if(ok==QMessageBox::StandardButton::Yes)             //+++++如果有文件，需先问问是否要保存+++++
        {

        }
    }
}
