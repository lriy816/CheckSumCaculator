//
// Created by lriy on 3/6/23.
//
#include <arpa/inet.h>
#include <stdio.h>
#include "lib.h"
#include "window.h"
#include "ui_window.h"
#include "ComputeIP.h"
using namespace std;
window::window(QWidget *parent)
    : QMainWindow(parent),ui(new Ui::AppWindow)
{
    ui->setupUi(this);
}
window::~window() noexcept
{
    delete ui;
}

void window::on_clearButton_clicked()
{
    ui->srcEdit->clear();
    ui->destEdit->clear();
    ui->tlEdit->clear();
    ui->protocolEdit->clear();
    ui->checksumEdit->clear();
    ui->textEdit->clear();

    ui->dsfEdit->clear();
    ui->idenEdit->clear();
    ui->flagsEdit->clear();
    ui->offsetEdit->clear();
    ui->ttlEdit->clear();

}
void window::on_beginButton_clicked()
{
    char buf[20];


        ComputeIP a;

        QString src = ui->srcEdit->text();
        string stdsrc = src.toUtf8().constData();
        inet_pton(AF_INET, reverseIP(stdsrc).c_str(),&a.src);

        QString dest = ui->destEdit->text();
        string stddest = dest.toUtf8().constData();
        inet_pton(AF_INET, reverseIP(stddest).c_str(),&a.dest);

        QString tl = ui->tlEdit->text();
        a.tl = tl.toUInt();

        QString protocol = ui->protocolEdit->text();
        a.protocol = protocol.toUInt();

        QString dsf = ui->dsfEdit->text();
        a.dsf = dsf.toUInt();

        QString iden = ui->idenEdit->text();
        a.iden = iden.toUInt();

        QString flags = ui->flagsEdit->text();
        a.flags = flags.toUInt();

        QString offset = ui->offsetEdit->text();
        a.offset = offset.toUInt();

        QString ttl = ui->ttlEdit->text();
        a.ttl = ttl.toUInt();




        a.compute(this);
        snprintf(buf,20,"%x",a.checksum);
        ui->checksumEdit->setText(QString(buf));

}