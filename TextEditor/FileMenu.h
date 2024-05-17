#ifndef FILEMENU_H
#define FILEMENU_H

#include <QMenu>

class MainWindow;
class FileMenu : public QMenu
{
    Q_OBJECT
public:
    FileMenu(const QString& title,MainWindow* parent = nullptr);
public slots:
    void OnFileNew();
    void OnFileOpen();
    void OnFileSave();
    void OnExit();
};

#endif // FILEMENU_H
