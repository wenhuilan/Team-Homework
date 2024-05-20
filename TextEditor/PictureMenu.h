#ifndef PICTUREMENU_H
#define PICTUREMENU_H
#include <QMenu>
#include <QAbstractItemModel>
class MainWindow;
class PictureMenu : public  QMenu
{
    Q_OBJECT

public:
PictureMenu(const QString& title,MainWindow* parent = nullptr,MainWindow *ui = nullptr);
public slots:
    void OnPicture();
    void OnVedio();
private:
 MainWindow* mainWindow;
    MainWindow *ui;
};

#endif // PICTUREMENU_H
