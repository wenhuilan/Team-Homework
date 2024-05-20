#ifndef CODEMENU_H
#define CODEMENU_H

#include <QMenu>
class MainWindow;
class CodeMenu : public QMenu
{
    Q_OBJECT

public:
   CodeMenu(const QString& title,MainWindow* parent = nullptr);

private:
    MainWindow* mainWindow;
};

#endif // CODEMENU_H
