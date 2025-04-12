#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

namespace Ui {
    class AddDialog;
}

class AddDialog : public QDialog {
    Q_OBJECT
public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

    QString orderNumber() const;
    QString customer()    const;
    QString product()     const;
    bool discount()       const;
    bool shipping()       const;

    void setOrderNumber(const QString &value);
    void setCustomer(const QString &value);
    void setProduct(const QString &value);
    void setDiscount(bool value);
    void setShipping(bool value);

    private slots:
        void on_buttonOk_clicked();
    void on_buttonCancel_clicked();

private:
    Ui::AddDialog *ui;
};

#endif