#include "adddialog.h"
#include "ui_adddialog.h"
#include <QIntValidator>
#include <QMessageBox>

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    ui->lineEditOrderNumber->setValidator(new QIntValidator(1, 99999999, this));
}

AddDialog::~AddDialog() {
    delete ui;
}

QString AddDialog::orderNumber() const {
    return ui->lineEditOrderNumber->text();
}

QString AddDialog::customer() const {
    return ui->lineEditCustomer->text();
}

QString AddDialog::product() const {
    return ui->lineEditProduct->text();
}

bool AddDialog::discount() const {
    return ui->checkBoxDiscount->isChecked();
}

bool AddDialog::shipping() const {
    return ui->checkBoxShipping->isChecked();
}

void AddDialog::setOrderNumber(const QString &value) {
    ui->lineEditOrderNumber->setText(value);
}

void AddDialog::setCustomer(const QString &value) {
    ui->lineEditCustomer->setText(value);
}

void AddDialog::setProduct(const QString &value) {
    ui->lineEditProduct->setText(value);
}

void AddDialog::setDiscount(bool value) {
    ui->checkBoxDiscount->setChecked(value);
}

void AddDialog::setShipping(bool value) {
    ui->checkBoxShipping->setChecked(value);
}

void AddDialog::on_buttonOk_clicked() {
    if(ui->lineEditOrderNumber->text().isEmpty() ||
       ui->lineEditCustomer->text().isEmpty() ||
       ui->lineEditProduct->text().isEmpty())
    {
        QMessageBox::warning(
            this,
            "Ошибка ввода",
            "Все поля (кроме чекбоксов) должны быть заполнены!"
        );
        return;
    }
    accept();
}

void AddDialog::on_buttonCancel_clicked() {
    reject();
}