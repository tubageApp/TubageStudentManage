#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stusqlist.h"
#include <QMainWindow>
#include "page_login.h"
#include "dlg_addstu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void on_btn_Exit_clicked();

    void on_btn_moni_clicked();

    void on_pushButton_clicked();

    void on_btn_clear_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_btn_search_clicked();

private:
    void updateTable();

private:
    Ui::MainWindow *ui;
    Page_Login m_dlgLogin;
    StuSqlist *m_ptrStuSql;
    QStringList m_lName;
    dlg_AddStu m_addStu;
};
#endif // MAINWINDOW_H

