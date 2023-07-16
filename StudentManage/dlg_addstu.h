#ifndef DLG_ADDSTU_H
#define DLG_ADDSTU_H

#include "stusqlist.h"

#include <QDialog>

namespace Ui {
class dlg_AddStu;
}

class dlg_AddStu : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_AddStu(QWidget *parent = nullptr);
    ~dlg_AddStu();

    void setType(bool isAdd, StuInfo info={});
private slots:
    void on_btn_save_clicked();

    void on_btn_exit_clicked();

private:
    Ui::dlg_AddStu *ui;
    bool m_isAdd;   //不是添加就是更新
    StuInfo m_info;
};

#endif // DLG_ADDSTU_H
