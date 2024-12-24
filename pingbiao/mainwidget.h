// #ifndef MAINWIDGET_H
// #define MAINWIDGET_H

// #include <QWidget>
// #include <QPushButton>
// #include <QVBoxLayout>
// #include <QLabel>
// #include <QList>
// #include "userwidget.h"
// #include <QScrollBar>
// #include <QListWidget>
// namespace Ui {
// class MainWidget;
// }

// class MainWidget : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit MainWidget(QWidget *parent = nullptr);
//     ~MainWidget();

// private:
//     Ui::MainWidget *ui;

//     // 按照图片名声明按钮
//     QPushButton *toolVideoButton;
//     QPushButton *toolExtraButton;
//     QPushButton *toolPicButton;
//     QPushButton *toolEmojiButton;
//     QPushButton *toolSendButton;

//     // 用于好友列表的布局
//     QListWidget *friendsListWidget;
//     // 存储好友列表中的UserWidget实例
//     QList<UserWidget *> friendsList;

//     QScrollBar *scrollBar;

//     // 函数用于添加好友到列表
//     void addFriend(const QString& name, const QString& title, const QPixmap& avatar);
// };

// #endif // MAINWIDGET_H




#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QList>
#include "userwidget.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QScrollArea>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWidget *ui;

    // 按照图片名声明按钮
    QPushButton *toolVideoButton;
    QPushButton *toolExtraButton;
    QPushButton *toolPicButton;
    QPushButton *toolEmojiButton;
    QPushButton *toolSendButton;

    QScrollArea *scrollArea;
    QWidget *friendsWidget;
    QVBoxLayout *friendsLayout;
    QList<UserWidget *> friendsList;
    void addFriend(const QString& name, const QString& title, const QPixmap& avatar);
};

#endif // MAINWIDGET_H
