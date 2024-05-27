#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

class Editor;
class MediaPlayerVideo;
class QMenuBar;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    Ui::MainWindow *ui;

    QMenuBar* menuBar;
    Editor* editor;
  std::vector<Editor*> editors;
    QString curFilePath;
};
#endif // MAINWINDOW_H
