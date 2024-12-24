#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPixmap>
#include <QScrollBar>
#include <QFrame>
#include <QBuffer>

// 构造函数
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // 创建按钮并输出相关属性进行调试
    toolVideoButton = new QPushButton(this);
    setupButton(toolVideoButton, ":/img/toolvideo.png", QRect(1310, 62, 32, 32));

    toolExtraButton = new QPushButton(this);
    setupButton(toolExtraButton, ":/img/toolextra.png", QRect(324, 1030, 24, 24));

    toolPicButton = new QPushButton(this);
    setupButton(toolPicButton, ":/img/toolpic.png", QRect(361, 1030, 24, 24));

    toolEmojiButton = new QPushButton(this);
    setupButton(toolEmojiButton, ":/img/toolemojy.png", QRect(396, 1030, 24, 24));

    toolSendButton = new QPushButton(this);
    setupButton(toolSendButton, ":/img/toolsend.png", QRect(1113, 1030, 24, 24));


    // 初始化好友列表布局
    friendsListWidget = new QListWidget();
    friendsListWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    friendsListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    friendsListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // 将好友列表布局添加到主窗口的某个位置
    QVBoxLayout *layout = new QVBoxLayout(ui->widget_2);
    layout->addWidget(friendsListWidget);

    // 添加一些示例好友
    QPixmap avatar1(":/img/head1.png");
    addFriend("Alice", "Friend", avatar1);
    QPixmap avatar2(":/img/head1.png");
    for (int i = 0; i < 20; ++i) {
        addFriend("Bob", "Colleague", avatar2);
    }

    this->show();
}

// 析构函数
MainWidget::~MainWidget()
{
    delete ui;
    // 释放按钮内存
    delete toolVideoButton;
    delete toolExtraButton;
    delete toolPicButton;
    delete toolEmojiButton;
    delete toolSendButton;
    // 释放好友列表相关内存
    qDeleteAll(friendsList);
    delete friendsListWidget;
}

// 添加好友到列表的函数
void MainWidget::addFriend(const QString& name, const QString& title, const QPixmap& avatar)
{
    UserWidget *userWidget = new UserWidget();
    userWidget->setUserName(name);
    userWidget->setUserTitle(title);
    userWidget->setUserAvatar(avatar);
    userWidget->setFixedSize(306, 84);

    QListWidgetItem *item = new QListWidgetItem(friendsListWidget);
    item->setSizeHint(QSize(306, 84));
    friendsListWidget->addItem(item);
    friendsListWidget->setItemWidget(item, userWidget);

    // 添加分隔线
    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    line->setStyleSheet("color: #E4E4E4;");
    line->setFixedHeight(1);

    QListWidgetItem *lineItem = new QListWidgetItem(friendsListWidget);
    lineItem->setSizeHint(QSize(306, 1));
    friendsListWidget->addItem(lineItem);
    friendsListWidget->setItemWidget(lineItem, line);

    friendsList.append(userWidget);
}
// void MainWidget::setupButton(QPushButton *button, const QString &iconPath, const QRect &geometry)
// {
//     button->setGeometry(geometry);
//     QString base64Image = loadImageAsBase64(iconPath);
//     QString styleSheet = QString("background-image: url(data:image/png;base64,%1); background-repeat: no-repeat; background-position: center;").arg(base64Image);
//     button->setStyleSheet(styleSheet);
//     button->setVisible(true);
//     button->setEnabled(true);
//     qDebug() << button->objectName() << "geometry: " << button->geometry();
//     qDebug() << button->objectName() << "visible: " << button->isVisible();
//     qDebug() << button->objectName() << "enabled: " << button->isEnabled();
//     qDebug() << button->objectName() << "stylesheet: " << button->styleSheet();
// }



void MainWidget::setupButton(QPushButton *button, const QString &iconPath, const QRect &geometry)
{
    button->setGeometry(geometry);
    QPixmap pixmap(iconPath);
    if (pixmap.isNull()) {
        qDebug() << "Could not create pixmap from" << iconPath;
        return;
    }
    button->setIcon(QIcon(pixmap));
    button->setIconSize(pixmap.size());
    button->setVisible(true);
    button->setEnabled(true);
    qDebug() << button->objectName() << "geometry: " << button->geometry();
    qDebug() << button->objectName() << "visible: " << button->isVisible();
    qDebug() << button->objectName() << "enabled: " << button->isEnabled();
    qDebug() << button->objectName() << "icon size: " << button->iconSize();
}


// QPixmap avatar1(":/img/head1.png");
// addFriend("Alice", "Friend", avatar1);
//     setupButton(toolSendButton, ":/img/toolsend.png", QRect(1113, 1030, 24, 24));
// void UserWidget::setUserAvatar(const QPixmap& avatar)
// {
//     // ui->avatarlb->setPixmap(avatar);
//     // 将 QPixmap 转换为 QImage
//     QImage image = avatar.toImage();

//     // 将 QImage 转换为 base64 编码的字符串
//     QByteArray byteArray;
//     QBuffer buffer(&byteArray);
//     image.save(&buffer, "PNG");
//     QString base64Image = QString::fromLatin1(byteArray.toBase64().data());

//     // 使用样式表设置背景图像
//     QString styleSheet = QString("background-image: url(data:image/png;base64,%1); background-repeat: no-repeat; background-position: center;").arg(base64Image);
//     this->setStyleSheet(styleSheet);
// }
// 封装的加载图像并转换为 base64 编码字符串的方法
QString MainWidget::loadImageAsBase64(const QString &imagePath)
{
    QPixmap pixmap(imagePath);
    QImage image = pixmap.toImage();

    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    image.save(&buffer, "PNG");
    return QString::fromLatin1(byteArray.toBase64().data());
}

// 重写 resizeEvent 函数以确保滚动区域大小随窗口调整
void MainWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    friendsListWidget->setGeometry(0, 0, ui->widget_2->width(), ui->widget_2->height());
}
