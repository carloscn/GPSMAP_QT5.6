#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWebKit>
#include <QWebFrame>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    void setCoordinate(QString lon,QString lat);
    void gpsDatasProcessing( QByteArray GPSBuffer );
    void UTC2BTC( QString *str );


private:
    Ui::Widget *ui;
    QTimer *timer;
    QTimer *serialTimer;
    QSerialPort *serialPort;
    QByteArray rxArray;
    bool serialRead;
    long times;

public slots:
    void getCoordinate(QString lon,QString lat);

private slots:
    void on_pushButtonStreetMap_clicked();
    void on_pushButtonSatelliteMap_clicked();
    void slotPopulateJavaScriptWindowObject();
    void slotTimeout();
    void RxData();
    void on_button_startDevice_clicked();
    void on_button_stopDevice_clicked();
    void slotSerialTimerOut();
};

#endif // WIDGET_H
