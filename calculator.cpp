#include "calculator.h"
#include "./ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
    , first_num(0)

{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(get_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(get_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(get_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(get_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(get_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(get_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(get_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(get_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(get_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(get_numbers()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(get_operation()));

    connect(ui->pushButton_add,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_sub,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mul,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
    ui->pushButton_mul->setCheckable(true);
    ui->pushButton_sub->setCheckable(true);

}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::get_numbers()
{
    QPushButton* button = (QPushButton *)sender();
    QString display;

    if(ui->result->text().contains(".") && button->text() == "0")
    {
       display = ui->result->text() + button->text();
    }
    else
    {
        double all_numbers = (ui->result->text() + button->text()).toDouble();
        display = QString::number(all_numbers, 'g', 15);
    }
    ui->result->setText(display);
}


void Calculator::on_pushButton_point_clicked()
{
    if(!ui->result->text().contains('.'))
    {
        ui->result->setText(ui->result->text() + ".");
    }
}


void Calculator::get_operation()
{
    QPushButton* button = (QPushButton *)sender();
    QString display;
    double all_numbers;


    if (button->text() == "%")
    {
        all_numbers = (ui->result->text().toDouble());
        all_numbers *= 0.01;
        display = QString::number(all_numbers, 'g', 15);
        ui->result->setText(display);
    }
}


void Calculator::math_operations()
{
    QPushButton* button = (QPushButton *)sender();
    first_num = (ui->result->text().toDouble());
    ui->result->setText("0");
     button->setChecked(true);
}

void Calculator::on_pushButton_clear_clicked()
{
    ui->result->setText("0");
    ui->pushButton_add->setChecked(false);
    ui->pushButton_sub->setChecked(false);
    ui->pushButton_mul->setChecked(false);
    ui->pushButton_div->setChecked(false);
}


void Calculator::on_pushButton_equal_clicked()
{
    double labelNumber, second_num;
    QString display;


    second_num = ui->result->text().toDouble();
    if(ui->pushButton_add->isChecked())
    {
        labelNumber = second_num + first_num;
        display = QString::number(labelNumber, 'g', 15);
        ui->result->setText(display);
        ui->pushButton_add->setChecked(false);

    }
    else if(ui->pushButton_sub->isChecked())
    {
        labelNumber = first_num - second_num;
        display = QString::number(labelNumber, 'g', 15);
        ui->result->setText(display);
        ui->pushButton_sub->setChecked(false);

    }
    else if(ui->pushButton_div->isChecked())
    {
        if(second_num == 0)
        {
            ui->result->setText("0");
        }
        else
        {
            labelNumber = first_num / second_num;
            display = QString::number(labelNumber, 'g', 15);
            ui->result->setText(display);
        }
        ui->pushButton_div->setChecked(false);

    }
    else if(ui->pushButton_mul->isChecked())
    {
        labelNumber = second_num * first_num;
        display = QString::number(labelNumber, 'g', 15);
        ui->result->setText(display);
        ui->pushButton_mul->setChecked(false);
    }
}


void Calculator::on_pushButton_backspace_clicked()
{
    QString display = ui->result->text();
    if(display.size() == 1)
    {
        ui->result->setText("0");
    }
    else
    {
        display.chop(1);
        ui->result->setText(display);
    }

}

