#ifndef MAINDATA_H
#define MAINDATA_H

#include <QString>

class Editor;

// 数据类，便于索引数据
class MainData
{
public:
    static QString curFilePath;         // 当前文件的目录
    static Editor* curEditor;           // 当前的文本编辑器
public:
    MainData();
};

#endif // MAINDATA_H
