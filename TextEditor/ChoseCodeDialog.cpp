#include "ChoseCodeDialog.h"
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "Editor.h"
#include <QStringEncoder>
ChoseCodeDialog::ChoseCodeDialog(MainWindow* mainwindow)
{
    mainWindow = mainwindow;
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QWidget* w = new QWidget(this);
    codecBtnGroup = new QButtonGroup(this);
    codecBtnGroup->setExclusive(true);          // 设置组间互
    this->setLayout(mainLayout);
    mainLayout->addWidget(w);

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
    int i = 0;
    for(auto cf : codecFuncMap.asKeyValueRange())
    {
        QPushButton* btn = new QPushButton(cf.first,this);
        codecBtnGroup->addButton(btn);
        codecBtnGroup->setId(btn,i++);
        mainLayout->addWidget(btn);
    }
    connect(codecBtnGroup,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(OnCodecBtnTriggered(QAbstractButton*)));
    mainLayout->addStretch(1);

    QHBoxLayout* buttomLayout = new QHBoxLayout(this);
    mainLayout->addLayout(buttomLayout);

    QPushButton* okBtn = new QPushButton("Ok",this);
    buttomLayout->addWidget(okBtn);
    connect(okBtn,SIGNAL(pressed()),this,SLOT(accept()));


    QPushButton* recoverBtn = new QPushButton("Recover",this);
    buttomLayout->addWidget(recoverBtn);
    connect(recoverBtn,SIGNAL(pressed()),this,SLOT(reject()));
}

void ChoseCodeDialog::OnCodecBtnTriggered(QAbstractButton* btn)
{
    selectedCodeType = btn->text();
}

void ChoseCodeDialog::Accepted()
{
    QTextDocument* doc = mainWindow->editor->document();
    QString res = doc->toRawText();
    recoverData = res;
    if(codecFuncMap.contains(selectedCodeType) && codecFuncMap[selectedCodeType])
    {
        res = codecFuncMap[selectedCodeType](res);
        mainWindow->editor->setPlainText(res);
    }
}

void ChoseCodeDialog::Reject()
{
    if(recoverData=="")return;
    mainWindow->editor->setPlainText(recoverData);
}
