#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QTextEdit>
#include "Highlighter.h"
#include "mainwindow.h"
#include <QColor>
#include <QPlainTextEdit>
#include <QPoint>
#include <QRegularExpression>
#include <QSize>
#include <QTextBlock>
#include <QTextCursor>
#include <QTextDocument>
#include <QTextLayout>
#include <QTextStream>


class MainWindow;
// 文本编辑器主体
// class Editor : public QTextEdit
// {
//     Q_OBJECT
// public:
//     Editor(MainWindow* parent = nullptr);
// };

// #endif // EDITOR_H
class Editor : public QTextEdit
{
    Q_OBJECT
public:
    Editor(MainWindow* parent = nullptr);
    ~Editor();
    void setCenterOnScrollOption(bool option);

private:
    int m_searchPosition; //< searchRegex() from this
    bool m_centerOnScrollOption =
        false;                   //< Confugration option: wether center on scroll
    QTextEdit::ExtraSelection
        m_extraSelection; //< block hightlighted by searchRegex()
    Highlighter* m_highlighter;
    void highlightSelections(
        QList<QTextEdit::ExtraSelection>& extraSelectionList,
        QColor color = QColor(Qt::yellow).lighter());
    void highlightSelection(QTextEdit::ExtraSelection& extraSelection,
                            QColor color = QColor(Qt::yellow).lighter());

public slots:
    void searchRegex(const QRegularExpression& regex,
                     QTextDocument::FindFlags findFlags);
signals:
    void searchRegexIsFound();
    void searchRegexIsNotFound();


public slots:
    void highlightCurrentLine();
};

#endif // EDITOR_H
