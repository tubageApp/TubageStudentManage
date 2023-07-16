#include "stusqlist.h"
#include <QSqlQuery>
#include <QDebug>
#include <QCoreApplication>
#include <QSqlError>

StuSqlist * StuSqlist::ptrstuSql=nullptr;

StuSqlist::StuSqlist(QObject *parent)
    : QObject{parent}
{
//    init();

//    StuInfo s;
//    s.name="小明";
//    s.id=9;
//    for(int i=0;i<10;i++)
//    {
//        addStu(s);
//    }

//    getStuCnt();

//    getPageStu(0,2);

//    delStu(8);

//    UpdateStuInfo(s);
}

void StuSqlist::init()
{
    if (QSqlDatabase::drivers().isEmpty())
    {
        qDebug()<<"No database drivers found"<<endl;
    }

    m_db = QSqlDatabase::addDatabase("QSQLITE");

#if 0
    auto str = QCoreApplication::applicationDirPath()+"SqLite/data.db";
    qDebug()<<str<<endl;
#endif

    m_db.setDatabaseName("SqLite/data.db");
    if (!m_db.open())
    {
        qDebug()<<"db not open!";
    }
}

quint32 StuSqlist::getStuCnt()
{
    QSqlQuery sql(m_db);
    sql.exec("select count(id) from student;");
    quint32 uiCnt = 0;
    while(sql.next())
    {
        uiCnt = sql.value(0).toUInt();
    }
    return uiCnt;
}

QList<StuInfo> StuSqlist::getPageStu(quint32 page, quint32 uiCnt)
{
    QList<StuInfo> l;
    QSqlQuery sql(m_db);
    QString strsql = QString("select * from student order by id limit %1 offset %2").
                     arg(uiCnt).arg(page*uiCnt);
    sql.exec(strsql);
    StuInfo info;
    while(sql.next())
    {
        info.id = sql.value(0).toUInt();
        info.name = sql.value(1).toString();
        info.age = sql.value(2).toUInt();
        info.grade = sql.value(3).toUInt();
        info.stuClass = sql.value(4).toUInt();
        info.studentId = sql.value(5).toUInt();
        info.phone = sql.value(6).toString();
        info.weChat = sql.value(7).toString();
        l.push_back(info);
    }
    return l;
}

bool StuSqlist::addStu(StuInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into student values(nuLL,'%1',%2,%3,%4,%5,'%6','%7');").
                     arg(info.name).
                     arg(info.age).
                     arg(info.grade).
                     arg(info.stuClass).
                     arg(info.studentId).
                     arg(info.phone).
                     arg(info.weChat);
    return sql.exec(strSql);
}

bool StuSqlist::delStu(int id)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from student where id = %1;").arg(id));
}

bool StuSqlist::clearStuTable()
{
    QSqlQuery sql(m_db);
    sql.exec("delete from student");
    return sql.exec("delete from sqlite_sequence where name='student'");   //取消id自增
}

bool StuSqlist::UpdateStuInfo(StuInfo info)
{
    QSqlQuery sql(m_db);
    qDebug()<<info.id;
    QString strSql = QString("update student set name='%1', age=%2, grade=%3, class=%4, studentid=%5, phone='%6', wechat='%7'  where id=%8").
                     arg(info.name).
                     arg(info.age).
                     arg(info.grade).
                     arg(info.stuClass).
                     arg(info.studentId).
                     arg(info.phone).
                     arg(info.weChat).
                     arg(info.id);
    qDebug()<<strSql;
    qDebug()<<info.id;

    bool ret = sql.exec(strSql);
    QSqlError e = sql.lastError();
    if(e.isValid())
    {
        qDebug()<<e.text();
    }
    qDebug()<<ret;
    return ret;
}

QList<UserInfo> StuSqlist::getAllUser()
{
    QList<UserInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("select * from username");
    UserInfo info;
    while(sql.next())
    {
        info.userName = sql.value(0).toString();
        info.Password = sql.value(1).toString();
        info.Aut = sql.value(2).toString();
        l.push_back(info);
    }
    return l;
}

QString StuSqlist::isExit(QString strUser)
{
    QSqlQuery sql(m_db);
    sql.exec(QString("select *from username where username='%1'").arg(strUser));
    if(sql.next())
    {
        return sql.value(1).toString();
    }
    else
    {
        return nullptr;
    }
}

bool StuSqlist::UpdateUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("update username set password='%1', auth='%2' where username='%3';").
                     arg(info.Password).
                     arg(info.Aut).
                     arg(info.userName);
    bool ret = sql.exec(strSql);
    QSqlError e = sql.lastError();
    if(e.isValid())
    {
        qDebug()<<e.text();
    }
    return ret;
}

bool StuSqlist::AddUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into student values('%1','%2','%3');").
                     arg(info.userName).
                     arg(info.Password).
                     arg(info.Aut);
    return sql.exec(strSql);
}

bool StuSqlist::delUser(QString strUserName)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from username where username='%1';").arg(strUserName));
}

