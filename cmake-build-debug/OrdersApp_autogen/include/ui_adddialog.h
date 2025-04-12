/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddDialog
{
public:
    QFormLayout *formLayout;
    QLabel *labelOrderNumber;
    QLineEdit *lineEditOrderNumber;
    QLabel *labelCustomer;
    QLineEdit *lineEditCustomer;
    QLabel *labelProduct;
    QLineEdit *lineEditProduct;
    QCheckBox *checkBoxDiscount;
    QCheckBox *checkBoxShipping;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;

    void setupUi(QDialog *AddDialog)
    {
        if (AddDialog->objectName().isEmpty())
            AddDialog->setObjectName(QString::fromUtf8("AddDialog"));
        AddDialog->resize(300, 200);
        formLayout = new QFormLayout(AddDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelOrderNumber = new QLabel(AddDialog);
        labelOrderNumber->setObjectName(QString::fromUtf8("labelOrderNumber"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelOrderNumber);

        lineEditOrderNumber = new QLineEdit(AddDialog);
        lineEditOrderNumber->setObjectName(QString::fromUtf8("lineEditOrderNumber"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditOrderNumber);

        labelCustomer = new QLabel(AddDialog);
        labelCustomer->setObjectName(QString::fromUtf8("labelCustomer"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelCustomer);

        lineEditCustomer = new QLineEdit(AddDialog);
        lineEditCustomer->setObjectName(QString::fromUtf8("lineEditCustomer"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditCustomer);

        labelProduct = new QLabel(AddDialog);
        labelProduct->setObjectName(QString::fromUtf8("labelProduct"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelProduct);

        lineEditProduct = new QLineEdit(AddDialog);
        lineEditProduct->setObjectName(QString::fromUtf8("lineEditProduct"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditProduct);

        checkBoxDiscount = new QCheckBox(AddDialog);
        checkBoxDiscount->setObjectName(QString::fromUtf8("checkBoxDiscount"));

        formLayout->setWidget(3, QFormLayout::LabelRole, checkBoxDiscount);

        checkBoxShipping = new QCheckBox(AddDialog);
        checkBoxShipping->setObjectName(QString::fromUtf8("checkBoxShipping"));

        formLayout->setWidget(3, QFormLayout::FieldRole, checkBoxShipping);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonOk = new QPushButton(AddDialog);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(buttonOk);

        buttonCancel = new QPushButton(AddDialog);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(buttonCancel);


        formLayout->setLayout(4, QFormLayout::SpanningRole, horizontalLayout);


        retranslateUi(AddDialog);

        QMetaObject::connectSlotsByName(AddDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDialog)
    {
        AddDialog->setWindowTitle(QCoreApplication::translate("AddDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 / \320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        labelOrderNumber->setText(QCoreApplication::translate("AddDialog", "\320\235\320\276\320\274\320\265\321\200 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        labelCustomer->setText(QCoreApplication::translate("AddDialog", "\320\237\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\214", nullptr));
        labelProduct->setText(QCoreApplication::translate("AddDialog", "\320\242\320\276\320\262\320\260\321\200", nullptr));
        checkBoxDiscount->setText(QCoreApplication::translate("AddDialog", "\320\241\320\272\320\270\320\264\320\272\320\260", nullptr));
        checkBoxShipping->setText(QCoreApplication::translate("AddDialog", "\320\224\320\276\321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        buttonOk->setText(QCoreApplication::translate("AddDialog", "OK", nullptr));
        buttonCancel->setText(QCoreApplication::translate("AddDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDialog: public Ui_AddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
