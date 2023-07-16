#include "dlg_addstu.h"
#include "ui_dlg_addstu.h"
#include "stusqlist.h"
#include <QMessageBox>
#include <QDebug>

dlg_AddStu::dlg_AddStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_AddStu)
{
    ui->setupUi(this);


}

dlg_AddStu::~dlg_AddStu()
{
    delete ui;
}

void dlg_AddStu::setType(bool isAdd,StuInfo info)
{
    m_isAdd = isAdd;
    m_info = info;
    if(!isAdd)
    {
        m_info = info;
        qDebug()<<m_info.id;
        ui->le_name->setText(m_info.name);
        ui->le_age->setValue(m_info.age);
        ui->le_grade->setText(QString::number(m_info.grade));
        ui->le_class->setText(QString::number(m_info.stuClass));
        ui->le_stuID->setText(QString::number(m_info.studentId));
        ui->le_phone->setText(m_info.phone);
        ui->le_wechat->setText(m_info.weChat);
    }
}


void dlg_AddStu::on_btn_save_clicked()
{
    auto ptr = StuSqlist::getinstance();
    m_info.name=ui->le_name->text();
    m_info.age=ui->le_age->text().toInt();
    m_info.grade=ui->le_grade->text().toInt();
    m_info.stuClass=ui->le_class->text().toInt();
    m_info.studentId=ui->le_stuID->text().toInt();
    m_info.phone=ui->le_phone->text();
    m_info.weChat=ui->le_wechat->text();

    if(m_isAdd)
    {
        ptr->addStu(m_info);
    }
    else
    {
        ptr->UpdateStuInfo(m_info);
    }

    QMessageBox::information(nullptr,"信息","存储成功！");
    this->hide();
}


void dlg_AddStu::on_btn_exit_clicked()
{
    this->hide();
}

