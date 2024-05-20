#include "mainwindow.h"
#include <QMenuBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "./ui_mainwindow.h"
#include "EditMenu.h"
#include "FileMenu.h"
#include "PictureMenu.h""
#include "ThemeMenu.h"
#include "Editor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("文本编辑器");
    this->setStyleSheet("QMainWindow { background-color: black; }"); // 设置窗口的背景颜色为白色
      this->setStyleSheet("QMainWindow { background-color: # c5ffdc; }");

    QIcon icon(":/document-file-exe.png");
    this->setWindowIcon(icon);
    menuBar = new QMenuBar(this);
    this->setMenuBar(menuBar);


    QIcon fileIcon(":/file.png"); // 假设你有一个名为"file.png"的图标文件在资源文件中
    QIcon editIcon(":/edit.png");
    QIcon codeIcon(":/code.png");
    QIcon fontIcon(":/font.png");
    QIcon themeIcon(":/theme.png");
    QIcon imgIcon(":/img.png");
    QIcon mathIcon(":/math.png");

    QMenu *fileMenu = new FileMenu(tr("file"),this);
    fileMenu->setIcon(fileIcon);
    QMenu * editMenu = new EditMenu(tr("Edit"),this);
     editMenu->setIcon(editIcon);
    QMenu *menuCode = new QMenu(tr("code"),this);
    menuCode->setIcon(codeIcon);

    QMenu *menuTheme = new ThemeMenu(tr("theme"),this);
    menuTheme->setIcon(themeIcon);
    QMenu *menuImg = new PictureMenu(tr("img"),this);
    menuImg->setIcon(imgIcon);
    QMenu *menuMath = new QMenu(tr("math"),this);
    menuMath->setIcon(mathIcon);

    menuBar->addMenu(fileMenu);
      menuBar->addSeparator();
    menuBar->addMenu( editMenu);
        menuBar->addSeparator();
    menuBar->addMenu(menuCode);
          menuBar->addSeparator();
    menuBar->addMenu(menuTheme);
              menuBar->addSeparator();
    menuBar->addMenu(menuImg);
                menuBar->addSeparator();
    menuBar->addMenu(menuMath);
      menuBar->addSeparator();

    editor = new Editor(this);
      // editor->setStyleSheet("background-color:#6c6c6c;");
    editor->setStyleSheet("background-color:#aeffdo;");
    this->setCentralWidget(editor);
}

MainWindow::~MainWindow()
{
    delete ui;
}
