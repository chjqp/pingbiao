#include "userwidget.h"
#include "ui_userwidget.h"

UserWidget::UserWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWidget)
{
    ui->setupUi(this);

}

UserWidget::~UserWidget()
{
    delete ui;
}

// 设置用户名字
void UserWidget::setUserName(const QString& name)
{
    ui->namelb->setText(name);
}

// 获取用户名字
QString UserWidget::getUserName() const
{
    return ui->namelb->text();
}

// 设置用户头衔
void UserWidget::setUserTitle(const QString& title)
{
    ui->titlelb->setText(title);
}

// 获取用户头衔
QString UserWidget::getUserTitle() const
{
    return ui->titlelb->text();
}

// 设置用户头像
void UserWidget::setUserAvatar(const QPixmap& avatar)
{
    ui->avatarlb->setPixmap(avatar);
}

// 获取用户头像
QPixmap UserWidget::getUserAvatar() const
{
    return ui->avatarlb->pixmap();
}
