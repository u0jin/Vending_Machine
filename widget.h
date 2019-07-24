#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QMainWindow
{
    Q_OBJECT

public:

    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void changeMoney(int n);

    int money{0};

private slots:


    void on_btn_10_clicked();

    void on_apple_100_clicked();

    void on_ice_200_clicked();

    void on_soda_150_clicked();

    void on_icecream_10_clicked();

    void on_btn_50_clicked();

    void on_btn_100_clicked();

    void on_btn_500_clicked();

    void on_btn_return_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
