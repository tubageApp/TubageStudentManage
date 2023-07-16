#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include "stusqlist.h"

#include <QWidget>

namespace Ui {
class Page_Login;
}

class Page_Login : public QWidget
{
    Q_OBJECT

public:
    explicit Page_Login(QWidget *parent = nullptr);
    ~Page_Login();

private slots:
    void on_btn_Login_clicked();

    void on_btn_Quit_clicked();

signals:
    void sendLoginSuccess();
private:
    Ui::Page_Login *ui;
    StuSqlist *m_ptrUserSql;
};

#endif // PAGE_LOGIN_H

