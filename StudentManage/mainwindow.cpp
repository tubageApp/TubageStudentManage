#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_ptrStuSql(nullptr)
{
    ui->setupUi(this);

    //内部添加QSS样式
//    QFile fread;
//    fread.setFileName(":/QSS.css");
//    fread.open(QIODevice::ReadOnly);
//    QString strQss = fread.readAll();
//    this->setStyleSheet(strQss);

    m_dlgLogin.show();
    auto f = [&](){
        this->show();
        ui->lbl_Admin->setText(m_dlgLogin.str);
    };
    connect(&m_dlgLogin,&Page_Login::sendLoginSuccess,this,f);

    ui->treeWidget->setColumnCount(1);

    QStringList l;
    l<<"学生信息管理系统";
    QTreeWidgetItem* pf = new QTreeWidgetItem(ui->treeWidget,l);
    ui->treeWidget->addTopLevelItem(pf);

    l.clear();
    l<<"学生管理";
    QTreeWidgetItem* p1 = new QTreeWidgetItem(pf,l);

    l.clear();
    l<<"管理员管理";
    QTreeWidgetItem* p2 = new QTreeWidgetItem(pf,l);

    pf->addChild(p1);
    pf->addChild(p2);

    //默认展开
    ui->treeWidget->expandAll();

    m_ptrStuSql = StuSqlist::getinstance();

    m_ptrStuSql->init();

    m_lName<<"归晓畅";
    m_lName<<"那拉易";
    m_lName<<"游星鹏";
    m_lName<<"邴旭";
    m_lName<<"颜弘伟";
    m_lName<<"多国安";
    m_lName<<"碧碧琴";
    m_lName<<"薄霏霏";
    m_lName<<"有曜儿";
    m_lName<<"隽芳洁";
    m_lName<<"阿骊泓";
    m_lName<<"龙子濯";
    m_lName<<"阙名";
    m_lName<<"慈骊颖";
    m_lName<<"似睿文";
    m_lName<<"受怀";
    m_lName<<"瑞筠溪";
    m_lName<<"辟夏菡";
    m_lName<<"福冠";
    m_lName<<"龚怀桃";
    m_lName<<"居弘致";
    m_lName<<"尾盼晴";
    m_lName<<"秘晓筠";
    m_lName<<"繁安安";
    m_lName<<"夹谷曼";
    m_lName<<"顿希";
    m_lName<<"闻人忻";
    m_lName<<"危晔";
    m_lName<<"伏清逸";
    m_lName<<"官湛娟";
    m_lName<<"牵蒙雨";
    m_lName<<"桂轩";
    m_lName<<"苗盼盼";
    m_lName<<"抗舒";
    m_lName<<"殳南晴";
    m_lName<<"种芦";
    m_lName<<"士恩";
    m_lName<<"阎雅宁";
    m_lName<<"斯星宇";
    m_lName<<"都秀慧";
    m_lName<<"冷香桃";
    m_lName<<"花忆雪";
    m_lName<<"凭秋白";
    m_lName<<"才盼芙";
    m_lName<<"泥心愫";
    m_lName<<"箕令雪";
    m_lName<<"经凌寒";
    m_lName<<"矫奇玮";
    m_lName<<"杨友灵";
    m_lName<<"余墨";
    m_lName<<"集清舒";
    m_lName<<"佛思怡";
    m_lName<<"尔凝";
    m_lName<<"秦淑静";
    m_lName<<"詹安平";
    m_lName<<"错子萱";
    m_lName<<"焉恬静";
    m_lName<<"杜雅凡";
    m_lName<<"燕梦竹";
    m_lName<<"诸高朗";
    m_lName<<"言莹华";
    m_lName<<"元铭";
    m_lName<<"曲向槐";
    m_lName<<"展可昕";
    m_lName<<"晏依瑶";
    m_lName<<"象甜恬";
    m_lName<<"森灵阳";
    m_lName<<"栾熙阳";
    m_lName<<"闵刚毅";
    m_lName<<"英雨晴";
    m_lName<<"宝香薇";
    m_lName<<"锺献玉";
    m_lName<<"图门晨";
    m_lName<<"竺梦山";
    m_lName<<"改慕梅";
    m_lName<<"府飞航";
    m_lName<<"丁智伟";
    m_lName<<"乌孙书";
    m_lName<<"祭红螺";
    m_lName<<"隋月灵";
    m_lName<<"弓南蓉";
    m_lName<<"莫燕";
    m_lName<<"堂淑兰";
    m_lName<<"王以筠";
    m_lName<<"弥怀柔";
    m_lName<<"宏涵忍";
    m_lName<<"溥雨筠";
    m_lName<<"甫津";
    m_lName<<"操萝";
    m_lName<<"侨幻丝";
    m_lName<<"东浩漫";
    m_lName<<"行茉莉";
    m_lName<<"蔺凡雁";
    m_lName<<"钭梦山";
    m_lName<<"成芳泽";
    m_lName<<"学艾";
    m_lName<<"励木兰";
    m_lName<<"穆初柳";
    m_lName<<"夔凝阳";
    m_lName<<"严浩阔";

    updateTable();

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_F6)    //设置按键   按F6刷新样式
    {
        QFile f;
        auto str = QCoreApplication::applicationDirPath();
        f.setFileName(str+"//"+"stuqss.css");
        f.open(QIODevice::ReadOnly);
        QString strQss = f.readAll();
        this->setStyleSheet(strQss);        //样式给主页面
        m_dlgLogin.setStyleSheet(strQss);   //样式给对话框
    }
}


void MainWindow::on_btn_Exit_clicked()
{
    exit(0);
}


void MainWindow::on_btn_moni_clicked()
{
    QRandomGenerator g;
    g.seed(0);
    //制作1000条学生数据
    for(int i=0;i<m_lName.size();i++)
    {
        StuInfo info;
        info.name=m_lName[i];
        info.age=g.bounded(17,24);
        info.grade = g.bounded(1,5);
        info.stuClass = g.bounded(1,8);
        info.studentId=2200609*100+i;
        info.phone = "17622223333";
        info.weChat="169963258";
        m_ptrStuSql->addStu(info);
    }
    qDebug()<<"成功！";
    updateTable();
}


void MainWindow::on_pushButton_clicked()
{
    m_addStu.setType(true);
    m_addStu.exec();
    updateTable();
}


void MainWindow::on_btn_clear_clicked()
{
    m_ptrStuSql->clearStuTable();
    updateTable();
}

void MainWindow::updateTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(9);
    QStringList l;
    l<<"序号"<<"id"<<"姓名"<<"年龄"<<"年级"<<"班级"<<"学号"<<"手机号"<<"微信号";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    //只选中行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //不能编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    auto cnt = m_ptrStuSql->getStuCnt();

    ui->lbl_cnt->setText(QString("学生数量:%1").arg(cnt));
    QList<StuInfo> lStudents = m_ptrStuSql->getPageStu(0,cnt);

    ui->tableWidget->setRowCount(cnt);
    for(int i=0;i<lStudents.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(lStudents[i].id)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(lStudents[i].name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(lStudents[i].age)));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lStudents[i].grade)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(lStudents[i].stuClass)));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(lStudents[i].studentId)));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(lStudents[i].phone));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(lStudents[i].weChat));
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    int i =ui->tableWidget->currentRow();

    if(i>=0)
    {
        int id = ui->tableWidget->item(i,1)->text().toUInt();
        m_ptrStuSql->delStu(id);
        updateTable();
        QMessageBox::information(nullptr,"信息","删除成功！");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    StuInfo info;
    int i =ui->tableWidget->currentRow();
    if(i>=0)
    {
        info.id = ui->tableWidget->item(i,1)->text().toUInt();
        qDebug()<<info.id;
        info.name = ui->tableWidget->item(i,2)->text();
        info.age = ui->tableWidget->item(i,3)->text().toUInt();
        info.grade = ui->tableWidget->item(i,4)->text().toUInt();
        info.stuClass = ui->tableWidget->item(i,5)->text().toUInt();
        info.studentId = ui->tableWidget->item(i,6)->text().toUInt();
        info.phone = ui->tableWidget->item(i,7)->text();
        info.weChat = ui->tableWidget->item(i,8)->text();
        m_addStu.setType(false,info);
        m_addStu.exec();
    }

    updateTable();
}


void MainWindow::on_btn_search_clicked()
{
    QString strFilter = ui->le_search->text();
    if(strFilter.isEmpty())
    {
        QMessageBox::information(nullptr,"警告","搜索框不能为空！");
        updateTable();
        return;
    }
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(9);
    QStringList l;
    l<<"序号"<<"id"<<"姓名"<<"年龄"<<"年级"<<"班级"<<"学号"<<"手机号"<<"微信号";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    auto cnt = m_ptrStuSql->getStuCnt();

    ui->lbl_cnt->setText(QString("学生数量:%1").arg(cnt));
    QList<StuInfo> lStudents = m_ptrStuSql->getPageStu(0,cnt);
    int index = 0;
    for(int i=0;i<lStudents.size();i++)
    {
        if(!lStudents[i].name.contains(strFilter))
        {
            continue;
        }
        ui->tableWidget->setItem(index,0,new QTableWidgetItem(QString::number(index)));
        ui->tableWidget->setItem(index,1,new QTableWidgetItem(QString::number(lStudents[i].id)));
        ui->tableWidget->setItem(index,2,new QTableWidgetItem(lStudents[i].name));
        ui->tableWidget->setItem(index,3,new QTableWidgetItem(QString::number(lStudents[i].age)));
        ui->tableWidget->setItem(index,4,new QTableWidgetItem(QString::number(lStudents[i].grade)));
        ui->tableWidget->setItem(index,5,new QTableWidgetItem(QString::number(lStudents[i].stuClass)));
        ui->tableWidget->setItem(index,6,new QTableWidgetItem(QString::number(lStudents[i].studentId)));
        ui->tableWidget->setItem(index,7,new QTableWidgetItem(lStudents[i].phone));
        ui->tableWidget->setItem(index,8,new QTableWidgetItem(lStudents[i].weChat));
        index++;
    }
    ui->tableWidget->setRowCount(index);
    ui->lbl_cnt->setText(QString("学生数量:%1").arg(index));
}

