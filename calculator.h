#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
    double first_num;

private slots:
        void get_numbers();
        void on_pushButton_point_clicked();
        void get_operation();
        void on_pushButton_clear_clicked();
        void on_pushButton_equal_clicked();
        void math_operations();
        void on_pushButton_backspace_clicked();
};
#endif // CALCULATOR_H
