#include "userwidget.h"
#include "ui_userwidget.h"

UserWidget::UserWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserWidget)
{
    ui->setupUi(this);
    // ui->label->setStyleSheet(

    //                      "border-radius: 28px; "  // 设置圆角
    //                      );       // 设置内边距

    ui->avatarlb->setStyleSheet("background-image: url(:/img/head1.png); "
                         "border-radius: 28px; "

                         );
}

UserWidget::~UserWidget()
{
    delete ui;
}
