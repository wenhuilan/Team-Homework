#include"Editor.h"

Editor::Editor(MainWindow* parent)
    : QTextEdit(parent)
    , m_highlighter(new Highlighter(document()))
{
}

void
Editor::highlightSelection(QTextEdit::ExtraSelection& extraSelection,
                           QColor color)
{
    auto extraSelectionList{ extraSelections() };
    // Clear highlight of previous matched pattern
    for (auto& item : extraSelectionList) {
        item.format.clearBackground();
    }
    setExtraSelections(extraSelectionList);

    m_extraSelection = extraSelection;
    m_extraSelection.format.setBackground(color);
    m_extraSelection.format.setProperty(QTextFormat::FullWidthSelection, true);

    auto iter{ std::find_if(extraSelectionList.rend(),
                           extraSelectionList.rbegin(),
                           [&](const auto& item) {
                               return item.cursor == m_extraSelection.cursor;
                           }) };
    // Never searched before
    if (iter == extraSelectionList.rbegin()) {
        qDebug() << "Editor::highlightSelection(): never searched before";
        extraSelectionList.append(m_extraSelection);
    } else
    // Searched before
    {
        qDebug() << "Editor::highlightSelection(): searched before";
        // Highlight matched pattern
        *iter = m_extraSelection;
    }
    setExtraSelections(extraSelectionList);
}

void
Editor::highlightSelections(
    QList<QTextEdit::ExtraSelection>& extraSelectionList,
    QColor color)
{
    for (auto& extraSelection : extraSelectionList) {
        extraSelection.format.setBackground(color);
        extraSelection.format.setProperty(QTextFormat::FullWidthSelection,
                                          true);
    }
    setExtraSelections(extraSelectionList);
}


void
Editor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(0xFFFFCC);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

void
Editor::searchRegex(const QRegularExpression& regex,
                    QTextDocument::FindFlags findFlags)
{
    qDebug() << QStringLiteral("Editor::searchRegex(): regex is %1")
                    .arg(regex.pattern());
    auto* d{ document() };
    qDebug() << QStringLiteral(
                    "Editor::searchRegex(): m_searchPosition before find() is %1")
                    .arg(m_searchPosition);
    auto cursor = d->find(regex, m_searchPosition, findFlags);
    qDebug() << "Editor::searchRegex(): cursor's pos: " << cursor.position();
    /// If regex is not found, emit signal searchRegexNotFound and return.
    if (cursor.isNull()) {
        qDebug() << "Editor::searchRegex(): search failed";
        emit searchRegexIsNotFound();
        return;
    }
    qDebug() << "Editor::searchRegex(): search successfully";
    if (!m_centerOnScrollOption)
        setCenterOnScrollOption(true);
    emit searchRegexIsFound();

    /// Highlight matched word and calculate m_searchPosition
    m_extraSelection.cursor = cursor;
    m_extraSelection.format.setProperty(QTextFormat::FullWidthSelection, true);
    if (findFlags.testFlag(QTextDocument::FindBackward)) {
        qDebug() << "search backward";
        cursor.movePosition(QTextCursor::PreviousWord);
        qDebug() << "cursor.position(): " << m_searchPosition;
        m_searchPosition = cursor.position();
    } else {
        cursor.movePosition(QTextCursor::NextCell);
        m_searchPosition =
            2 * m_extraSelection.cursor.position() - cursor.position();
    }
    auto c{ textCursor() };
    c.movePosition(QTextCursor::End);
    m_searchPosition = std::clamp(m_searchPosition, 0, c.position());
    c.setPosition(m_searchPosition);
    setTextCursor(c);
    qDebug() << QStringLiteral(
                    "Editor::searchRegex(): m_searchPosition after find() is %1")
                    .arg(m_searchPosition);
    highlightSelection(m_extraSelection);
}

void
Editor::setCenterOnScrollOption(bool option)
{
    m_centerOnScrollOption = option;
}

Editor::~Editor()
{
    delete m_highlighter;
}
