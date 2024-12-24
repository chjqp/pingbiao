// #include "mainwidget.h"
// #include "ui_mainwidget.h"

// // 构造函数
// MainWidget::MainWidget(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::MainWidget)
// {
//     ui->setupUi(this);

//     // 创建按钮并输出相关属性进行调试
//     toolVideoButton = new QPushButton(this);
//     toolVideoButton->setGeometry(1310, 62, 32, 32);
//     toolVideoButton->setIcon(QIcon(":/img/toolvideo.png"));
//     toolVideoButton->setVisible(true);
//     toolVideoButton->setEnabled(true);
//     qDebug() << "toolVideoButton geometry: " << toolVideoButton->geometry();
//     qDebug() << "toolVideoButton visible: " << toolVideoButton->isVisible();
//     qDebug() << "toolVideoButton enabled: " << toolVideoButton->isEnabled();
//     QIcon icon = toolVideoButton->icon();
//     qDebug() << "toolVideoButton icon size: " << icon.actualSize(QSize(100, 100));
//     qDebug() << "toolVideoButton icon availableSizes: " << icon.availableSizes();
//     qDebug() << "toolVideoButton stylesheet: " << toolVideoButton->styleSheet();

//     toolExtraButton = new QPushButton(this);
//     toolExtraButton->setGeometry(324, 1030, 24, 24);
//     toolExtraButton->setIcon(QIcon(":/img/toolextra.png"));
//     toolExtraButton->setVisible(true);
//     toolExtraButton->setEnabled(true);
//     qDebug() << "toolExtraButton geometry: " << toolExtraButton->geometry();
//     qDebug() << "toolExtraButton visible: " << toolExtraButton->isVisible();
//     qDebug() << "toolExtraButton enabled: " << toolExtraButton->isEnabled();
//     QIcon iconExtra = toolExtraButton->icon();
//     qDebug() << "toolExtraButton icon size: " << iconExtra.actualSize(QSize(100, 100));
//     qDebug() << "toolExtraButton icon availableSizes: " << iconExtra.availableSizes();
//     qDebug() << "toolExtraButton stylesheet: " << toolExtraButton->styleSheet();

//     toolPicButton = new QPushButton(this);
//     toolPicButton->setGeometry(361, 1030, 24, 24);
//     toolPicButton->setIcon(QIcon(":/img/toolpic.png"));
//     toolPicButton->setVisible(true);
//     toolPicButton->setEnabled(true);
//     qDebug() << "toolPicButton geometry: " << toolPicButton->geometry();
//     qDebug() << "toolPicButton visible: " << toolPicButton->isVisible();
//     qDebug() << "toolPicButton enabled: " << toolPicButton->isEnabled();
//     QIcon iconPic = toolPicButton->icon();
//     qDebug() << "toolPicButton icon size: " << iconPic.actualSize(QSize(100, 100));
//     qDebug() << "toolPicButton icon availableSizes: " << iconPic.availableSizes();
//     qDebug() << "toolPicButton stylesheet: " << toolPicButton->styleSheet();

//     toolEmojiButton = new QPushButton(this);
//     toolEmojiButton->setGeometry(396, 1030, 24, 24);
//     toolEmojiButton->setIcon(QIcon(":/img/toolemojy.png"));
//     toolEmojiButton->setVisible(true);
//     toolEmojiButton->setEnabled(true);
//     qDebug() << "toolEmojiButton geometry: " << toolEmojiButton->geometry();
//     qDebug() << "toolEmojiButton visible: " << toolEmojiButton->isVisible();
//     qDebug() << "toolEmojiButton enabled: " << toolEmojiButton->isEnabled();
//     QIcon iconEmoji = toolEmojiButton->icon();
//     qDebug() << "toolEmojiButton icon size: " << iconEmoji.actualSize(QSize(100, 100));
//     qDebug() << "toolEmojiButton icon availableSizes: " << iconEmoji.availableSizes();
//     qDebug() << "toolEmojiButton stylesheet: " << toolEmojiButton->styleSheet();

//     toolSendButton = new QPushButton(this);
//     toolSendButton->setGeometry(1113, 1030, 24, 24);
//     toolSendButton->setIcon(QIcon(":/img/toolsend.png"));
//     toolSendButton->setVisible(true);
//     toolSendButton->setEnabled(true);
//     qDebug() << "toolSendButton geometry: " << toolSendButton->geometry();
//     qDebug() << "toolSendButton visible: " << toolSendButton->isVisible();
//     qDebug() << "toolSendButton enabled: " << toolSendButton->isEnabled();
//     QIcon iconSend = toolSendButton->icon();
//     qDebug() << "toolSendButton icon size: " << iconSend.actualSize(QSize(100, 100));
//     qDebug() << "toolSendButton icon availableSizes: " << iconSend.availableSizes();
//     qDebug() << "toolSendButton stylesheet: " << toolSendButton->styleSheet();

//     // 初始化好友列表布局
//     friendsListWidget = new QListWidget(this);
//     // 将好友列表布局添加到主窗口的某个位置
//     // 假设这里添加到主窗口的左侧，你可以根据实际情况调整

//     QVBoxLayout *layout = new QVBoxLayout(ui->widget_2);
//     layout->addWidget(friendsListWidget);

//     // scrollBar = new QScrollBar(Qt::Vertical, this);
//     // scrollBar->setGeometry(/* 设置滑动条的位置和大小 */);

//     // 添加一些示例好友
//     QPixmap avatar1(":/img/head1.png");
//     addFriend("Alice", "Friend", avatar1);
//     QPixmap avatar2(":/img/head1.png");
//     addFriend("Bob", "Colleague", avatar2);
//     for(int i=1;i<=10;i++){
//         addFriend("Bob", "Colleague", avatar2);
//     }
//     this->show();
// }

// // 析构函数
// MainWidget::~MainWidget()
// {
//     delete ui;
//     // 释放按钮内存
//     delete toolVideoButton;
//     delete toolExtraButton;
//     delete toolPicButton;
//     delete toolEmojiButton;
//     delete toolSendButton;
//     // 释放好友列表相关内存
//     qDeleteAll(friendsList);
//     delete   friendsListWidget;
// }

// // 添加好友到列表的函数
// void MainWidget::addFriend(const QString& name, const QString& title, const QPixmap& avatar)
// {
//     UserWidget *userWidget = new UserWidget(this);
//     userWidget->setUserName(name);
//     userWidget->setUserTitle(title);
//     userWidget->setUserAvatar(avatar);

//     QListWidgetItem *item = new QListWidgetItem;
//     item->setSizeHint(userWidget->sizeHint());

//     friendsListWidget->addItem(item);
//     friendsListWidget->setItemWidget(item, userWidget);
// }

























#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPixmap>

// 构造函数
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // 创建按钮并输出相关属性进行调试
    toolVideoButton = new QPushButton(this);
    toolVideoButton->setGeometry(1310, 62, 32, 32);
    toolVideoButton->setIcon(QIcon(":/img/toolvideo.png"));
    toolVideoButton->setVisible(true);
    toolVideoButton->setEnabled(true);
    qDebug() << "toolVideoButton geometry: " << toolVideoButton->geometry();
    qDebug() << "toolVideoButton visible: " << toolVideoButton->isVisible();
    qDebug() << "toolVideoButton enabled: " << toolVideoButton->isEnabled();
    QIcon icon = toolVideoButton->icon();
    qDebug() << "toolVideoButton icon size: " << icon.actualSize(QSize(100, 100));
    qDebug() << "toolVideoButton icon availableSizes: " << icon.availableSizes();
    qDebug() << "toolVideoButton stylesheet: " << toolVideoButton->styleSheet();

    toolExtraButton = new QPushButton(this);
    toolExtraButton->setGeometry(324, 1030, 24, 24);
    toolExtraButton->setIcon(QIcon(":/img/toolextra.png"));
    toolExtraButton->setVisible(true);
    toolExtraButton->setEnabled(true);
    qDebug() << "toolExtraButton geometry: " << toolExtraButton->geometry();
    qDebug() << "toolExtraButton visible: " << toolExtraButton->isVisible();
    qDebug() << "toolExtraButton enabled: " << toolExtraButton->isEnabled();
    QIcon iconExtra = toolExtraButton->icon();
    qDebug() << "toolExtraButton icon size: " << iconExtra.actualSize(QSize(100, 100));
    qDebug() << "toolExtraButton icon availableSizes: " << iconExtra.availableSizes();
    qDebug() << "toolExtraButton stylesheet: " << toolExtraButton->styleSheet();

    toolPicButton = new QPushButton(this);
    toolPicButton->setGeometry(361, 1030, 24, 24);
    toolPicButton->setIcon(QIcon(":/img/toolpic.png"));
    toolPicButton->setVisible(true);
    toolPicButton->setEnabled(true);
    qDebug() << "toolPicButton geometry: " << toolPicButton->geometry();
    qDebug() << "toolPicButton visible: " << toolPicButton->isVisible();
    qDebug() << "toolPicButton enabled: " << toolPicButton->isEnabled();
    QIcon iconPic = toolPicButton->icon();
    qDebug() << "toolPicButton icon size: " << iconPic.actualSize(QSize(100, 100));
    qDebug() << "toolPicButton icon availableSizes: " << iconPic.availableSizes();
    qDebug() << "toolPicButton stylesheet: " << toolPicButton->styleSheet();

    toolEmojiButton = new QPushButton(this);
    toolEmojiButton->setGeometry(396, 1030, 24, 24);
    toolEmojiButton->setIcon(QIcon(":/img/toolemojy.png"));
    toolEmojiButton->setVisible(true);
    toolEmojiButton->setEnabled(true);
    qDebug() << "toolEmojiButton geometry: " << toolEmojiButton->geometry();
    qDebug() << "toolEmojiButton visible: " << toolEmojiButton->isVisible();
    qDebug() << "toolEmojiButton enabled: " << toolEmojiButton->isEnabled();
    QIcon iconEmoji = toolEmojiButton->icon();
    qDebug() << "toolEmojiButton icon size: " << iconEmoji.actualSize(QSize(100, 100));
    qDebug() << "toolEmojiButton icon availableSizes: " << iconEmoji.availableSizes();
    qDebug() << "toolEmojiButton stylesheet: " << toolEmojiButton->styleSheet();

    toolSendButton = new QPushButton(this);
    toolSendButton->setGeometry(1113, 1030, 24, 24);
    toolSendButton->setIcon(QIcon(":/img/toolsend.png"));
    toolSendButton->setVisible(true);
    toolSendButton->setEnabled(true);
    qDebug() << "toolSendButton geometry: " << toolSendButton->geometry();
    qDebug() << "toolSendButton visible: " << toolSendButton->isVisible();
    qDebug() << "toolSendButton enabled: " << toolSendButton->isEnabled();
    QIcon iconSend = toolSendButton->icon();
    qDebug() << "toolSendButton icon size: " << iconSend.actualSize(QSize(100, 100));
    qDebug() << "toolSendButton icon availableSizes: " << iconSend.availableSizes();
    qDebug() << "toolSendButton stylesheet: " << toolSendButton->styleSheet();


    scrollArea = new QScrollArea(ui->widget_2);
    scrollArea->setBackgroundRole(QPalette::NoRole);
    scrollArea->setWidgetResizable(true);

    // 创建一个用于存放好友列表的部件
    QWidget *friendsWidget = new QWidget;
    friendsLayout = new QVBoxLayout(friendsWidget);
    friendsLayout->setSpacing(0);
    friendsLayout->setContentsMargins(0, 0, 0, 0);

    // 添加一些示例好友
    QPixmap avatar1(":/img/head1.png");
    addFriend("Alice", "Friend", avatar1);
    QPixmap avatar2(":/img/head1.png");
    for (int i = 0; i < 14; ++i) {
        addFriend("Bob", "Colleague", avatar2);
    }

    // 设置好友列表部件的布局
    friendsWidget->setLayout(friendsLayout);

    // 将好友列表部件添加到滚动区域
    scrollArea->setWidget(friendsWidget);

    // 设置滚动区域在ui->widget_2中的位置和大小（根据界面设计调整）
    // 例如，以下是简单设置让其占满ui->widget_2空间，你可按需更改
    scrollArea->setGeometry(0, 0, ui->widget_2->width(), ui->widget_2->height());
    // 关键步骤：确保滚动区域根据其内部内容自动显示滚动条
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    this->show();
}


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
        delete   friendsWidget;
    }

// 添加好友到列表的函数
void MainWidget::addFriend(const QString& name, const QString& title, const QPixmap& avatar)
{
    UserWidget *userWidget = new UserWidget(this);
    userWidget->setUserName(name);
    userWidget->setUserTitle(title);
    userWidget->setUserAvatar(avatar);
    userWidget->setStyleSheet("background-color: white;");
    userWidget->setFixedSize(306, 84);
    friendsList.append(userWidget);
    friendsLayout->addWidget(userWidget);
    // 添加分隔线
    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    line->setStyleSheet("color: #E4E4E4;");
    friendsLayout->addWidget(line);

    // // 更新 friendsWidget 的大小
    // friendsWidget->adjustSize();
}
// 重写 resizeEvent 函数以确保滚动区域大小随窗口调整
void MainWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    scrollArea->setGeometry(0, 0, ui->widget_2->width(), ui->widget_2->height());
}
