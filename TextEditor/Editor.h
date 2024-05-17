#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QTextEdit>

class MainWindow;
class Editor : public QTextEdit
{
    Q_OBJECT
public:
    Editor(MainWindow* parent = nullptr);
};

#endif // EDITOR_H
