#include "page_login.h"
#include "ui_page_login.h"
#include "stusqlist.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>

Page_Login::Page_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Login)
{
    ui->setupUi(this);

}

Page_Login::~Page_Login()
{
    delete ui;
}

void Page_Login::on_btn_Login_clicked()
{
    m_ptrUserSql = StuSqlist::getinstance();
    m_ptrUserSql->init();
    //数据库查找用户名和密码
    //如果失败就提示
    //成功就进入主窗口
    QString strusername = ui->le_UserName->text();
    QString strpassword = ui->le_Password->text();
    if(m_ptrUserSql->isExit(strusername)!=nullptr)
    {
        if(strpassword==m_ptrUserSql->isExit(strusername))
        {
            emit sendLoginSuccess();
            this->close();
        }
        else
        {
            QMessageBox::information(nullptr,"警告","密码输入有误！");
        }
    }
    else
    {
        QMessageBox::information(nullptr,"警告","用户名不存在！");
    }
}


void Page_Login::on_btn_Quit_clicked()
{
    //退出
    exit(0);
}

