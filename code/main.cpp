#include "mainwindow.h"
#include "QZXing"
#include "QZXing.h"
#include <QApplication>
#include <iostream>


using namespace std;

int main()
{

        QImage imageToDecode(":/Lecteur_CodeBarre/code/DSC00000.jpg");
        QZXing decoder;
            //mandatory settings
        decoder.setDecoder(QZXing:: DecoderFormat_QR_CODE | QZXing:: DecoderFormat_EAN_13 | QZXing::DecoderFormat_DATA_MATRIX);

            //optional settings
            decoder.setSourceFilterType(QZXing::SourceFilter_ImageNormal | QZXing::SourceFilter_ImageInverted);
            //decoder.setSourceFilterType(QZXing::SourceFilter_ImageNormal);
            decoder.setTryHarderBehaviour(QZXing::TryHarderBehaviour_ThoroughScanning | QZXing::TryHarderBehaviour_Rotate);

            //trigger decode
            QString result = decoder.decodeImage(imageToDecode);


        if(result==NULL)//si l'image n'a pas pu être decoder
            {
                cout<<"l'image n'a pas pu être decoder"<<endl<<"Veuillez prendre une photo bien droite"<<endl;
            }

          else //sinon afficher le code
            {

                cout << result.toStdString()<<endl;

            }



}
