#ifndef CHOSECODEDIALOG_H
#define CHOSECODEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include "mainwindow.h"
#include <QStringEncoder>
class QButtonGroup;
class QPushButton;

class ChoseCodeDialog : public QDialog
{
    Q_OBJECT
public:
    QButtonGroup* codecBtnGroup;
    QHash<QString,QString(*)(const QString&)>codecFuncMap;
    QString selectedCodeType = 0;
    MainWindow* mainWindow = nullptr;
    QString recoverData;
public:
    ChoseCodeDialog(MainWindow* mainwindow = nullptr);

    void Accepted();
    void Reject();
public slots:
    void OnCodecBtnTriggered(QAbstractButton* btn);
};

#endif // CHOSECODEDIALOG_H
