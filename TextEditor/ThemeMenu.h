#ifndef THEMEMENU_H
#define THEMEMENU_H
#include <QMenu>
#include <QAbstractItemModel>
class MainWindow;
class ThemeMenu : public QMenu
{
    Q_OBJECT
public:
    ThemeMenu(const QString& title,MainWindow* parent = nullptr,MainWindow *ui = nullptr);
public slots:
    void OnDark();
    void OnLight();
    void OnProtect();
private:
    MainWindow* mainWindow;
    MainWindow *ui;
};

#endif // THEMEMENU_H
