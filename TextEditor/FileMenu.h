#ifndef FILEMENU_H
#define FILEMENU_H

#include <QMenu>
#include <QFileDialog>
class MainWindow;
class FileMenu : public QMenu
{
    Q_OBJECT
public:
    FileMenu(const QString& title,MainWindow* parent = nullptr);
    void SetCurFileName(const QString &fileName);
    QString ShowFileDialog(QFileDialog::AcceptMode mode);
    QString SaveCurFile(QString path);
public slots:
    void OnFileNew();
    void OnFileOpen();
    void OnFileSave();
    void OnExit();
private:
    MainWindow* mainWindow;
    QString curFileName;
};

#endif // FILEMENU_H
