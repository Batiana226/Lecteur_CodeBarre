#include "mainwindow.h"
#include "QZXing"
#include "QZXing.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

        QImage imageToDecode(":/Lecteur_CodeBarre/code/index3.png");
        QZXing decoder;
            //mandatory settings
        decoder.setDecoder(QZXing:: DecoderFormat_QR_CODE | QZXing:: DecoderFormat_EAN_13 );

            //optional settings
            decoder.setSourceFilterType(QZXing::SourceFilter_ImageNormal | QZXing::SourceFilter_ImageInverted);
            //decoder.setSourceFilterType(QZXing::SourceFilter_ImageNormal);
            decoder.setTryHarderBehaviour(QZXing::TryHarderBehaviour_ThoroughScanning | QZXing::TryHarderBehaviour_Rotate);

            //trigger decode
        QString result = decoder.decodeImage(imageToDecode);
        cout << result.toStdString()<<endl;

}
