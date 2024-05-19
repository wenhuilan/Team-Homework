#ifndef EDITMENU_H
#define EDITMENU_H

#include <QMenu>
class MainWindow;
class ChoseCodeDialog;

// 菜单栏中的 edit 菜单
class EditMenu : public QMenu
{
    Q_OBJECT
public:
    EditMenu(const QString& title,MainWindow* parent = nullptr);
    ~EditMenu();
public slots:
    void OnUndo();
    void OnRedo();
    void OnCopy();
    void OnCut();
    void OnPaste();
    void OnColor();
    void OnFont();
    void OnCodec();
private:
    MainWindow* mainWindow;
    ChoseCodeDialog* choseCodeDialog;
};

#endif // EDITMENU_H
