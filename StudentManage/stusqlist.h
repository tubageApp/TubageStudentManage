#ifndef STUSQLIST_H
#define STUSQLIST_H

#include <QObject>
#include <QList>
#include <QSqlDatabase>

struct StuInfo
{
    int id;             //唯一标识
    QString name;       //姓名
    quint8 age;         //年龄
    quint16 grade;      //年级
    quint16 stuClass;   //班级
    quint32 studentId;  //学号
    QString phone;     //电话
    QString weChat;    //微信
    StuInfo() {}
};
struct UserInfo
{
    QString userName;  //用户名
    QString Password;  //密码
    QString Aut;       //权限
    UserInfo() {}
};


class StuSqlist : public QObject
{
    Q_OBJECT
public:
    static StuSqlist *ptrstuSql;
    static StuSqlist *getinstance()
    {
        if(nullptr==ptrstuSql)
        {
            ptrstuSql=new StuSqlist;
        }
        return ptrstuSql;
    }

    explicit StuSqlist(QObject *parent = nullptr);

    //初始化
    void init();

    //查询所有学生数量
    quint32 getStuCnt();

    //查询第几页学生数据
    QList<StuInfo> getPageStu(quint32 page,quint32 uiCnt);

    //增加学生
    bool addStu(StuInfo);

    //删除学生
    bool delStu(int id);

    //清空学生表
    bool clearStuTable();

    //修改学生信息
    bool UpdateStuInfo(StuInfo info);

    //查询所有用户
    QList<UserInfo> getAllUser();

    //查询用户名是否存在
    QString isExit(QString strUser);

    //更新用户信息
    bool UpdateUser(UserInfo info);

    //添加单个用户
    bool AddUser(UserInfo info);

    //删除单个用户
    bool delUser(QString strUserName);

signals:
private:
    QSqlDatabase m_db;

};

#endif // STUSQLIST_H

