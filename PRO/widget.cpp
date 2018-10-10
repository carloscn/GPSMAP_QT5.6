#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include "QString"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("GPS定位解析系统");
    serialRead = false;
    times = 0;
    // 初始化地图
    timer=new QTimer(this);
    serialTimer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimeout()));
    connect(serialTimer,SIGNAL(timeout()),this,SLOT(slotSerialTimerOut()) );
    //timer->start(1000);
    serialTimer->start(1000);            // 500ms超时
    QString strMapPath = "file:///";
    strMapPath+=QCoreApplication::applicationDirPath();
    strMapPath+="/map/map.html";
    qDebug() << strMapPath ;
    QUrl url(strMapPath);
    ui->webView->load(url);
    ui->webView->setContentsMargins(0,0,0,0);
    ui->webView->setTextSizeMultiplier(1);//设置网页字体大小
    connect(ui->webView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(slotPopulateJavaScriptWindowObject()));
    // 初始化文本信息
    ui->lineEdit_altitude->setText(tr("待机中..."));
    ui->lineEdit_latitude->setText(tr("待机中..."));
    ui->lineEdit_longitude->setText(tr("待机中..."));
    ui->lineEdit_speed->setText(tr("待机中..."));
    ui->lineEdit_UTC->setText(tr("待机中..."));
    ui->textBrowser->append(tr("--------------------------------------------------------------------------"));
    ui->textBrowser->append(tr("SYSTEM: 欢迎使用GPS解析系统，该系统运行于Windows"));
    ui->textBrowser->append(tr("SYSTEM: 本消息窗口会接收GPS数据信息。"));
    ui->textBrowser->append(tr("SYSTEM: 系统初始化需要5s的时间，请5s后点击【连接】按钮建立连接，否则软件会崩溃！"));
    ui->textBrowser->append(tr("---------------------------------------------------------------------------"));
    // 初始化串口
    serialPort = new QSerialPort;
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(RxData()));
    // 初始化按钮
    ui->button_stopDevice->setEnabled(false);
    ui->button_startDevice->setEnabled(true);
    ui->pushButtonSatelliteMap->setEnabled(true);
    ui->pushButtonStreetMap->setEnabled(false);
    QMessageBox::information(this,"Information", "正在启动软件...请等待地图加载完毕后再进行操作！！！");

}

Widget::~Widget()
{
    delete ui;
}
/*
$GNRMC,114821.880,V,3957.378130,N,11620.848015,E,0.000,0.000,230417,,E,N*23
$GNGGA,114821.880,3957.378130,N,11620.848015,E,0,00,127.000,100.800,M,0,M,,*6D
$GNGLL,3957.378130,N,11620.848015,E,114821.880,V,N*52
$GNGSA,A,1,,,,,,,,,,,,,127.000,127.000,127.000*2A
$GNGSA,A,1,,,,,,,,,,,,,127.000,127.000,127.000*2A
$GPGSV,1,1,4,17,57,315,21,22,35,67,,28,75,176,,30,12,204,*74
*/
// 接收数据槽函数

void Widget::RxData(){


    QString rxString;

    rxArray.append(serialPort->readAll());
    //qDebug() << QString(rxArray);
    if( serialRead == true ){
        // 数据对齐，如果上次数据是一半，抛弃数据，重新接受
        times++;
        rxString = QString(rxArray);
        //qDebug() << "rec:" << rxString;
        ui->textBrowser->append(tr("--------------------------------------------------------------------------"));
        ui->textBrowser->append("从北斗GPS传感器第（"+QString::number(times)+"）次接受数据：");
        ui->textBrowser->append(tr("--------------------------------------------------------------------------"));
        ui->textBrowser->append(QString(rxArray));
        gpsDatasProcessing( rxArray );
        rxArray.clear();
        serialRead = false;
        if( times%50 == 0 ) {
            ui->textBrowser->clear();
        }
        ui->textBrowser->append(tr("--------------------------------------------------------------------------\r"));
    }else{
        return;
    }
    // 解析数据

}
void Widget::gpsDatasProcessing(QByteArray GPSBuffer)
{

    QString GPSBufferString = QString( GPSBuffer );
    int error_pos = 0;
    QString GNRMC_String = NULL;
    QString GPGGA_String = NULL;
    QString GPGSV_String = NULL;
    QString GPRMC_String = NULL;
    QString GPGLL_String = NULL;
    QString GNGGA_String = NULL;
    bool latiflag = false;
    bool atiflag = false;
    bool utcflag = false;
    bool speedflag = false;
    bool longtiflag = false;

    QList<QString> gpsStringList = GPSBufferString.split('\n');


    // 由于定时间隔，数据包发生黏连，纠正数据。
    if( gpsStringList.at(0).at(0) != '$' ) {
        QString ErrorString =  gpsStringList.at(gpsStringList.length()-1) + gpsStringList.at(0);
        error_pos = 1;
        if( ErrorString.contains("$GNRMC") ){
            GNRMC_String = ErrorString;
        }else if( ErrorString.contains("$GPGGA") ) {
            GPGGA_String = ErrorString;
        }else if( ErrorString.contains("$GPGSV")  ) {
            GPGSV_String = ErrorString;
        }else if( ErrorString.contains("$GPRMC") ) {
            GPRMC_String = ErrorString;
        }else if( ErrorString.contains("$GPGLL") ) {
            GPGLL_String = ErrorString;
        }else if( ErrorString.contains("$GNGGA") ) {
            GNGGA_String = ErrorString;
        }

    }else{
        error_pos = 0;
    }
    // 从QList中得到数据
    for( int i = error_pos; i < gpsStringList.length()- error_pos; i++ ) {
        if( gpsStringList.at(i).contains("$GNRMC") ){
            GNRMC_String = gpsStringList.at(i);
        }else if( gpsStringList.at(i).contains("$GPGGA") ) {
            GPGGA_String = gpsStringList.at(i);
        }else if( gpsStringList.at(i).contains("$GPGSV")  ) {
            GPGSV_String = gpsStringList.at(i);
        }else if( gpsStringList.at(i).contains("$GPRMC") ) {
            GPRMC_String = gpsStringList.at(i);
        }else if( gpsStringList.at(i).contains("$GPGLL") ) {
            GPGLL_String = gpsStringList.at(i);
        }else if( gpsStringList.at(i).contains("$GNGGA") ) {
            GNGGA_String = gpsStringList.at(i);
        }
    }
    if( !GPGGA_String.isNull() ) {
        QList<QString> gpggaStrList = GPGGA_String.split(",");
        QString utcstr = gpggaStrList.at(1);
        ui->lineEdit_UTC->setText("格林威治时间："+utcstr.mid(0,2)+":"+utcstr.mid(2,2)+":"+utcstr.mid(4,2));
        QString latistr = gpggaStrList.at(2);
        ui->lineEdit_latitude->setText("北纬"+latistr.mid(0,2)+"度"+latistr.mid(2,7)+"分");
        QString altistr = gpggaStrList.at(4);
        ui->lineEdit_longitude->setText("西经"+altistr.mid(0,3)+"度"+altistr.mid(3,7)+"分");
        utcflag = true;
        latiflag = true;
        atiflag = true;
    }
    if( !GNGGA_String.isNull() ) {
        if( !latiflag ) {
            QList<QString> gnggaStrList = GNGGA_String.split(",");
            QString utcstr = gnggaStrList.at(1);
            UTC2BTC(&utcstr);
            ui->lineEdit_UTC->setText("北京时间："+utcstr.mid(0,2)+":"+utcstr.mid(2,2)+":"+utcstr.mid(4,2));
            QString latistr = gnggaStrList.at(2);
            ui->lineEdit_latitude->setText("北纬"+latistr.mid(0,2)+"°"+latistr.mid(2,9)+"'");
            double double_lati = latistr.mid(0,2).toDouble()+(latistr.mid(2,7).toDouble()+0.25)/60;
            QString altistr = gnggaStrList.at(4);
            ui->lineEdit_longitude->setText("西经"+altistr.mid(0,3)+"°"+altistr.mid(3,9)+"'");
            double double_alti = altistr.mid(0,3).toDouble()+(altistr.mid(3,7).toDouble()+0.25)/60;

            setCoordinate(QString::number(double_alti),QString::number(double_lati));
            //setCoordinate(QString::number(108.886119),QString::number(34.223921));
            qDebug()<< "纬度："<<QString::number(double_alti)<<"|"<<"经度："<< QString::number(double_lati) << "\n";
            QString longtistr = gnggaStrList.at(9);
            ui->lineEdit_altitude->setText(longtistr+"m ");
            ui->lineEdit_speed->setText("无效PPS");

            utcflag = true;
            latiflag = true;
            atiflag = true;

        }
    }

}
void Widget::UTC2BTC( QString *str )
{
    int hour = 0;
    int mini = 0;
    int sec = 0;
    QString hour_str;
    QString mini_str;
    QString sec_str;
    hour = str->mid(0,2).toInt();
    mini = str->mid(2,4).toInt();
    sec = str->mid(4,6).toInt();

    if( hour < 16 ) {
        hour = hour + 8;
    }else if( hour > 16) {
        hour = (hour-24)+8;
    }else if( hour == 16 ) {
        hour = 0;
    }
    if( hour < 9 ) {
        hour_str = '0'+QString::number(hour);
    }else{
        hour_str = QString::number(hour);
    }
    if( mini < 9 ) {
        mini_str = '0'+QString::number(mini);
    }else{
        mini_str = QString::number(mini);
    }
    if( sec < 9 ) {
        sec_str = '0'+QString::number(sec);
    }else{
        sec_str = QString::number(sec);
    }


    *str = hour_str+mini_str+sec_str;

}

void Widget::getCoordinate(QString lon,QString lat)
{
    QString tempLon="鼠标经度:"+lon+"°";
    QString tempLat="鼠标纬度:"+lat+"°";
    ui->labelMouseLongitude->setText(tempLon);
    ui->labelMouseLatitude->setText(tempLat);
}

void Widget::setCoordinate(QString lon,QString lat)
{
    QWebFrame *webFrame = ui->webView->page()->mainFrame();
    QString cmd = QString("showAddress(\"%1\",\"%2\")").arg(lon).arg(lat);
    webFrame->evaluateJavaScript(cmd);
}

void Widget::slotTimeout()
{
    static double tempLon=116.468278;
    tempLon+=0.01;

    setCoordinate(QString::number(125.0),QString::number(43.0));
}

void Widget::slotSerialTimerOut()
{
    if( serialRead == false ){
        serialRead = true;
    }
}

void Widget::on_pushButtonStreetMap_clicked()
{
    QWebFrame *frame = ui->webView->page()->mainFrame();
    QString cmd = QString("showStreetMap()");
    frame->evaluateJavaScript(cmd);
    ui->pushButtonSatelliteMap->setEnabled(true);
    ui->pushButtonStreetMap->setEnabled(false);
}

void Widget::on_pushButtonSatelliteMap_clicked()
{
    QWebFrame *frame = ui->webView->page()->mainFrame();
    QString cmd = QString("showSatelliteMap()");
    frame->evaluateJavaScript(cmd);
    ui->pushButtonSatelliteMap->setEnabled(false);
    ui->pushButtonStreetMap->setEnabled(true);
}

void Widget::slotPopulateJavaScriptWindowObject()
{
    ui->webView->page()->mainFrame()->addToJavaScriptWindowObject("ReinforcePC", this);
}

void Widget::on_button_startDevice_clicked()
{
    QString portName;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;

        serial.setPort(info);
        if (serial.open(QIODevice::ReadWrite))
        {
            portName = info.portName();
            ui->textBrowser->append(tr("SYSTEM: 扫描串口")+info.portName()+tr("建立连接....."));
            qDebug()<<"打开系统成功，通信串口号为：";
            qDebug()<<portName;
            serialPort->setPortName(info.portName());
            qDebug()<< "现在可以进行操作了！";

            serial.close();
        }
    }
    if (!serialPort->open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this,"Warring","Open serial port fail!");
        ui->textBrowser->append(tr("SYSTEM: 串口打开失败，请检查串口是否被其他软件占用，或检查串口连接是否正常！"));

    }
    else
    {

        ui->textBrowser->append(tr("SYSTEM: 已经和串口")+portName+tr("建立连接！！"));
        ui->button_stopDevice->setEnabled(true);
        ui->button_startDevice->setEnabled(false);
        QMessageBox::information(this,"Information", "串口"+ portName+"被启动！\n"+"开始接收GPS信号，地图此时会自动定位到当前位置！");

    }

    qDebug() << "The serial has been openned!! \n";
}

void Widget::on_button_stopDevice_clicked()
{
    serialPort->close();

    QMessageBox::information(this,"Success", "Serial port has been closed!");
    ui->textBrowser->append(tr("SYSTEM: 已经断开通信端口，现在无法使用软件！"));
    ui->button_stopDevice->setEnabled(false);
    ui->button_startDevice->setEnabled(true);
}
