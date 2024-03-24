//Author: Cppbuzz.com
//Note: Users can download & modify this project as per their requirement

#include "findtourist.h"
#include "ui_findtourist.h"

FindTourist::FindTourist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindTourist)
{
    ui->setupUi(this);
    model = NULL;
}

FindTourist::~FindTourist()
{
    qDebug() << "In ~FindTourist()";
    delete ui;
    delete model;
}

void FindTourist::on_btnFind_clicked()
{
    QString touristfName = ui->txtTourstfName->text();
    qDebug() << "Tourist Name : "<< touristfName;
    QSqlDatabase database = QSqlDatabase::database("DB1");

    if(model == NULL)
        model = new QSqlQueryModel();

    model->setQuery("select * from Tourist where FirstName like '%" + touristfName + "%'", database);
    ui->tableView->setModel(model);
    qDebug() << " after btnFind_clicked";
}

