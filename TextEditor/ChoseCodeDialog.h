#ifndef CHOSECODEDIALOG_H
#define CHOSECODEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include "mainwindow.h"
#include <QStringEncoder>
class QButtonGroup;
class QPushButton;

// 切换编码界面
class ChoseCodeDialog : public QDialog
{
    Q_OBJECT
public:
    QButtonGroup* codecBtnGroup;                            // 所有的编码按钮组成的组
    QHash<QString,QString(*)(const QString&)>codecFuncMap;  // 每个编码按钮的名字到相关处理函数的哈希表
    QString selectedCodeType = 0;                           // 选中的编码方式
    MainWindow* mainWindow = nullptr;                       // 主界面，用于索引到编辑器的
    QString recoverData;                                    // 进行编码前的数据，用于撤回使用
public:
    ChoseCodeDialog(MainWindow* mainwindow = nullptr);
    ~ChoseCodeDialog();

    void Accepted();
    void Reject();
public slots:
    void OnCodecBtnTriggered(QAbstractButton* btn);
};

#endif // CHOSECODEDIALOG_H
