#ifndef EDITMENU_H
#define EDITMENU_H

#include <QMenu>
class MainWindow;
class ChoseCodeDialog;
class EditMenu : public QMenu
{
    Q_OBJECT
public:
    EditMenu(const QString& title,MainWindow* parent = nullptr);

public slots:
    void OnUndo();
    void OnRedo();
    void OnCopy();
    void OnCut();
    void OnPaste();
    void OnStyle();
    void OnCodec();
private:
    MainWindow* mainWindow;
    ChoseCodeDialog* choseCodeDialog;
};

#endif // EDITMENU_H
