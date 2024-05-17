#include "MainToolBar.h"

MainToolBar::MainToolBar(QWidget*parent):QToolBar(parent)
{
    this->setFloatable(false);
    this->setMovable(false);
    this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);



}
