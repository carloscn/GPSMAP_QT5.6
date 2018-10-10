/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *button_startDevice;
    QPushButton *button_stopDevice;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *lineEdit_latitude;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *lineEdit_longitude;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *lineEdit_speed;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *lineEdit_altitude;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QLineEdit *lineEdit_UTC;
    QHBoxLayout *horizontalLayout;
    QLabel *labelMouseLongitude;
    QLabel *labelMouseLatitude;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSatelliteMap;
    QPushButton *pushButtonStreetMap;
    QWebView *webView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1561, 895);
        verticalLayout_7 = new QVBoxLayout(Widget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_4->addWidget(label_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        button_startDevice = new QPushButton(groupBox);
        button_startDevice->setObjectName(QStringLiteral("button_startDevice"));
        button_startDevice->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 127);"));

        horizontalLayout_3->addWidget(button_startDevice);

        button_stopDevice = new QPushButton(groupBox);
        button_stopDevice->setObjectName(QStringLiteral("button_stopDevice"));
        button_stopDevice->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 0);"));

        horizontalLayout_3->addWidget(button_stopDevice);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        lineEdit_latitude = new QLineEdit(groupBox);
        lineEdit_latitude->setObjectName(QStringLiteral("lineEdit_latitude"));

        horizontalLayout_4->addWidget(lineEdit_latitude);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        lineEdit_longitude = new QLineEdit(groupBox);
        lineEdit_longitude->setObjectName(QStringLiteral("lineEdit_longitude"));

        horizontalLayout_5->addWidget(lineEdit_longitude);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        lineEdit_speed = new QLineEdit(groupBox);
        lineEdit_speed->setObjectName(QStringLiteral("lineEdit_speed"));

        horizontalLayout_6->addWidget(lineEdit_speed);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_7->addWidget(label_4);

        lineEdit_altitude = new QLineEdit(groupBox);
        lineEdit_altitude->setObjectName(QStringLiteral("lineEdit_altitude"));

        horizontalLayout_7->addWidget(lineEdit_altitude);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_8->addWidget(label_5);

        lineEdit_UTC = new QLineEdit(groupBox);
        lineEdit_UTC->setObjectName(QStringLiteral("lineEdit_UTC"));

        horizontalLayout_8->addWidget(lineEdit_UTC);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout_5->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelMouseLongitude = new QLabel(groupBox);
        labelMouseLongitude->setObjectName(QStringLiteral("labelMouseLongitude"));
        labelMouseLongitude->setMinimumSize(QSize(250, 25));
        labelMouseLongitude->setMaximumSize(QSize(250, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        labelMouseLongitude->setFont(font);
        labelMouseLongitude->setTextFormat(Qt::PlainText);

        horizontalLayout->addWidget(labelMouseLongitude);

        labelMouseLatitude = new QLabel(groupBox);
        labelMouseLatitude->setObjectName(QStringLiteral("labelMouseLatitude"));
        labelMouseLatitude->setMinimumSize(QSize(200, 25));
        labelMouseLatitude->setMaximumSize(QSize(250, 25));
        labelMouseLatitude->setFont(font);
        labelMouseLatitude->setTextFormat(Qt::PlainText);

        horizontalLayout->addWidget(labelMouseLatitude);


        verticalLayout_5->addLayout(horizontalLayout);


        verticalLayout_6->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMinimumSize(QSize(0, 0));
        textBrowser->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);\n"
"background-color: rgb(0, 0, 0);\n"
"font: 7pt \"\345\256\213\344\275\223\";"));

        verticalLayout->addWidget(textBrowser);


        verticalLayout_6->addWidget(groupBox_2);


        verticalLayout_4->addLayout(verticalLayout_6);


        horizontalLayout_10->addLayout(verticalLayout_4);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_8 = new QVBoxLayout(groupBox_3);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonSatelliteMap = new QPushButton(groupBox_3);
        pushButtonSatelliteMap->setObjectName(QStringLiteral("pushButtonSatelliteMap"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        pushButtonSatelliteMap->setFont(font1);
        pushButtonSatelliteMap->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"font: 75 10pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_2->addWidget(pushButtonSatelliteMap);

        pushButtonStreetMap = new QPushButton(groupBox_3);
        pushButtonStreetMap->setObjectName(QStringLiteral("pushButtonStreetMap"));
        pushButtonStreetMap->setFont(font1);
        pushButtonStreetMap->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"font: 75 10pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_2->addWidget(pushButtonStreetMap);


        verticalLayout_2->addLayout(horizontalLayout_2);

        webView = new QWebView(groupBox_3);
        webView->setObjectName(QStringLiteral("webView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy);
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        verticalLayout_2->addWidget(webView);


        verticalLayout_8->addLayout(verticalLayout_2);


        horizontalLayout_10->addWidget(groupBox_3);


        verticalLayout_7->addLayout(horizontalLayout_10);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label_7->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600;\">  \345\214\227\346\226\227GPS\345\256\232\344\275\215\350\247\243\346\236\220\347\263\273\347\273\237</span></p></body></html>", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\346\216\247\345\210\266\351\235\242\346\235\277", 0));
        button_startDevice->setText(QApplication::translate("Widget", "\345\274\200\345\220\257\350\256\276\345\244\207", 0));
        button_stopDevice->setText(QApplication::translate("Widget", "\345\205\263\351\227\255\350\256\276\345\244\207", 0));
        label->setText(QApplication::translate("Widget", "\347\272\254\345\272\246\357\274\232", 0));
        label_2->setText(QApplication::translate("Widget", "\347\273\217\345\272\246\357\274\232", 0));
        label_3->setText(QApplication::translate("Widget", "\351\200\237\345\272\246\357\274\232", 0));
        label_4->setText(QApplication::translate("Widget", "\351\253\230\345\272\246\357\274\232", 0));
        label_5->setText(QApplication::translate("Widget", "\346\227\266\351\227\264\357\274\232", 0));
        labelMouseLongitude->setText(QString());
        labelMouseLatitude->setText(QString());
        groupBox_2->setTitle(QApplication::translate("Widget", "GPS\346\216\245\346\224\266\344\277\241\346\201\257", 0));
        groupBox_3->setTitle(QApplication::translate("Widget", "\345\234\260\345\233\276\346\230\276\347\244\272", 0));
        pushButtonSatelliteMap->setText(QApplication::translate("Widget", "\345\215\253\346\230\237\345\233\276", 0));
        pushButtonStreetMap->setText(QApplication::translate("Widget", "\350\241\227\351\201\223\345\233\276", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
