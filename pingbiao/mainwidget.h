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
#include <QWheelEvent>
//差滚动条，以及几个按钮无法成功安上去,相同的方法，图片加载失败          好友列表设置背景白色后，字体不舒服
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

    QListWidget *friendsListWidget;
    QList<UserWidget *> friendsList;
    void addFriend(const QString& name, const QString& title, const QPixmap& avatar);
    QString loadImageAsBase64(const QString &imagePath);
    // 封装的设置按钮图标的方法
    void setupButton(QPushButton *button, const QString &iconPath, const QRect &geometry);
};

#endif // MAINWIDGET_H
