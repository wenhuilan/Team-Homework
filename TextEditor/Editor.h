#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QTextEdit>

class MainWindow;
// 文本编辑器主体
class Editor : public QTextEdit
{
    Q_OBJECT
public:
    Editor(MainWindow* parent = nullptr);
};

#endif // EDITOR_H
