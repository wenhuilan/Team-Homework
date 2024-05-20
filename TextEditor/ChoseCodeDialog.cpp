#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStringEncoder>
#include "Editor.h"
#include "ChoseCodeDialog.h"

ChoseCodeDialog::ChoseCodeDialog(MainWindow* mainwindow)
{
    mainWindow = mainwindow;
    QVBoxLayout* mainLayout = new QVBoxLayout(this);            // 主布局
    QWidget* w = new QWidget(this);                             // 主要的界面
    codecBtnGroup = new QButtonGroup(this);
    codecBtnGroup->setExclusive(true);                          // 设置组间互斥
    this->setLayout(mainLayout);                                // 设置对话窗的布局
    mainLayout->addWidget(w);                                   // 主布局中添加主窗口

    // 各种编码的处理
    codecFuncMap.insert("utf-8",[](const QString& str){
        auto from = QStringEncoder(QStringEncoder::Utf8);
        return QString(from(str));
    });
    codecFuncMap.insert("utf-16",[](const QString& str){
        auto from = QStringEncoder(QStringEncoder::Utf16);
        return QString(from(str));
    });
    codecFuncMap.insert("utf-32",[](const QString& str){
        auto from = QStringEncoder(QStringEncoder::Utf32);
        return QString(from(str));
    });
    codecFuncMap.insert("System",[](const QString& str){
        auto from = QStringEncoder(QStringEncoder::System);
        return QString(from(str));
    });

    // 依据上面的表，生成按钮
    int i = 0;
    for(auto cf : codecFuncMap.asKeyValueRange())
    {
        QPushButton* btn = new QPushButton(cf.first,this);
        codecBtnGroup->addButton(btn);                          // 按钮组中添加按钮
        codecBtnGroup->setId(btn,i++);                          // 设置按钮的组间编号
        mainLayout->addWidget(btn);                             // 将按钮加入主布局中
    }
    connect(codecBtnGroup,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(OnCodecBtnTriggered(QAbstractButton*)));
    mainLayout->addStretch(1);

    QHBoxLayout* buttomLayout = new QHBoxLayout(this);          // 主布局最底部的布局
    mainLayout->addLayout(buttomLayout);                        // 在添加stretch后添加，让该布局到底部去

    QPushButton* okBtn = new QPushButton("Ok",this);            // 给最底部添加两个按钮，ok 和 recover
    buttomLayout->addWidget(okBtn);
    connect(okBtn,SIGNAL(pressed()),this,SLOT(accept()));       // ok按下，将编辑器中的文本转码


    QPushButton* recoverBtn = new QPushButton("Recover",this);
    buttomLayout->addWidget(recoverBtn);
    connect(recoverBtn,SIGNAL(pressed()),this,SLOT(OnRecover()));  // recover按下，将编辑器中的文本设置为上次转码前的文本
}

ChoseCodeDialog::~ChoseCodeDialog()
{
    delete codecBtnGroup;
    codecFuncMap.clear();
    recoverData.clear();
    mainWindow = NULL;
}

void ChoseCodeDialog::OnCodecBtnTriggered(QAbstractButton* btn)
{
    selectedCodeType = btn->text();
}

void ChoseCodeDialog::Accepted()
{
    QTextDocument* doc = mainWindow->editor->document();        // 获取到编辑器的文本
    QString res = doc->toRawText();
    recoverData = res;                                          // 记录转码前的文本
    if(codecFuncMap.contains(selectedCodeType) && codecFuncMap[selectedCodeType])
    {
        res = codecFuncMap[selectedCodeType](res);              // 执行转码操作
        hasEncoded = true;
        mainWindow->editor->setPlainText(res);                  // 修改文本
    }
}

void ChoseCodeDialog::OnRecover()
{
    mainWindow->editor->setPlainText(recoverData);              // 重置文本为上次转码前的文本
    this->close();
}
