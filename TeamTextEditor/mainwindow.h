#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDockWidget>
#include <QListWidget>
#include <QTextEdit>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QToolBar>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QString m_fileName;
    QTextEdit* textEdit;
    QListWidget* textList;
    QMenuBar* menuBar;
    QToolBar* toolBar;
    Ui::MainWindow *ui;

    QFont font;
    QColor color;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString SaveData(QString path);

    void SetFileName(const QString& fileName);

    QString ShowFileDialog(QFileDialog::AcceptMode mode);

    void MergeFormat(QTextCharFormat fmt);
public slots:
    void OnExit();
    void OnOpenFile();
    void OnSaveFile();
    void OnNewFile();

    void OnTextUndo();
    void OnTextRedo();
    void OnTextCut();
    void OnTextCopy();
    void OnTextPaste();

    void OnTextUnderline();
    void OnTextBold(){}
    void OnTextColor(){}
    void OnTextFont(){}

};
#endif // MAINWINDOW_H
