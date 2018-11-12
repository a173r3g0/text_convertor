#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

using namespace Qt;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Text Convertor");
}

MainWindow::~MainWindow()
{
    delete ui;
}
class converter{
private:
    void ConvertEN(QString *Line){
        QString line = *Line;
        QString alphabet =   "r,R,t,T,e,E,a,A,o,O,s,S,w,W,l,L,i,I,n,N,b,B,u,p,d,f,g,h,j,k,z,X,x,c,v,y,Y,m, ",
                ALPHA837 = "Я,Я,7,7,3,3,4,4,0,0,$,5,77,77,1,1,!,!,И,И,8,8,U,P,D,F,G,H,J,K,Z,X,X,C,V,¥,¥,M,_"            ;
        QStringList stringList = alphabet.split(",");
        QStringList s7ringList = ALPHA837.split(",");
        int size;
        for(int i = 0; i < (size = stringList.size()); i++){
            line.replace(stringList[i],s7ringList[i]);
        }
        *Line = line;
    }
    void ReverseConvertEN(QString *Line){
        QString line = *Line;
        QString ALPHA837 = "_,M,¥,V,C,X,Z,K,J,H,G,F,D,P,U,8,И,!,1,77,5,$,0,4,3,7,Я";
        QString alphabet = " ,m,y,v,c,x,z,k,j,h,g,f,d,p,u,b,n,i,l,w,s,s,o,a,e,t,r";
        QStringList stringList = alphabet.split(",");
        QStringList s7ringList = ALPHA837.split(",");
        int size;
        for(int i = 0; i < (size = stringList.size()); i++){
            line.replace(s7ringList[i],stringList[i]);
        }
        *Line = line;
    }
    void ConvertRUS(QString *Line){
        QString line = *Line;
        QString alphabet =  "й,ц,у,к,е,н,г,ш,щ,з,х,ъ,ф,ы,в,а,п,р,о,л,д,ж,э,ё,я,ч,с,м,и,т,ь,б,ю,Й,Ц,У,К,Е,Н,Г,Ш,Щ,З,Х,Ъ,Ф,Ы,В,А,П,Р,О,Л,Д,Ж,Э,Ё,Я,Ч,С,М,И,Т,Ь,Б,Ю, ",
                ALPHA837 = "U,Ц,Y,K,3,Н,Г,Ш,Щ,3,Х,Ъ,Ф,bi,8,@,П,Р,0,Л,Д,Ж,Э,Ё,R,4,С,М,N,7,b,Б,Ю,U,Ц,Y,K,3,Н,Г,Ш,Щ,3,Х,Ъ,Ф,bi,8,@,П,Р,0,Л,Д,Ж,Э,Ё,R,4,С,М,N,7,b,Б,Ю,_";
        QStringList stringList = alphabet.split(",");
        QStringList s7ringList = ALPHA837.split(",");
        int size;
        for(int i = 0; i < (size = stringList.size()); i++){
            line.replace(stringList[i],s7ringList[i]);
        }
        *Line = line;
    }
    void ReverseConvertRUS(QString *Line){
        QString line = *Line;
        QString alphabet =  "й,ц,у,к,е,н,г,ш,щ,з,х,ъ,ф,ы,в,а,п,р,о,л,д,ж,э,ё,я,ч,с,м,и,т,ь,б,ю,Й,Ц,У,К,Е,Н,Г,Ш,Щ,З,Х,Ъ,Ф,Ы,В,А,П,Р,О,Л,Д,Ж,Э,Ё,Я,Ч,С,М,И,Т,Ь,Б,Ю, ",
                ALPHA837 = "U,Ц,Y,K,3,Н,Г,Ш,Щ,3,Х,Ъ,Ф,bi,8,@,П,Р,0,Л,Д,Ж,Э,Ё,R,4,С,М,N,7,b,Б,Ю,U,Ц,Y,K,3,Н,Г,Ш,Щ,3,Х,Ъ,Ф,bi,8,@,П,Р,0,Л,Д,Ж,Э,Ё,R,4,С,М,N,7,b,Б,Ю,_";
        QStringList stringList = alphabet.split(",");
        QStringList s7ringList = ALPHA837.split(",");
        int size;
        for(int i = 0; i < (size = stringList.size()); i++){
            line.replace(s7ringList[i],stringList[i]);
        }
        *Line = line;
    }
    void CheckForLanguage(QString line,QString *language){
        QString check_line = line;
        QString rus_alphabet = "й,ц,у,к,е,н,г,ш,щ,з,х,ъ,ф,ы,в,а,п,р,о,л,д,ж,э,ё,ч,с,м,и,т,ь,б,ю,Й,Ц,У,К,Е,Н,Г,Ш,Щ,З,Х,Ъ,Ф,Ы,В,А,П,Р,О,Л,Д,Ж,Э,Ё,Ч,С,М,Т,Ь,Б,Ю";
        QStringList stringList = rus_alphabet.split(",");
        int size;
        for(int i = 0; (size = stringList.size()) > i; i++){
            check_line.remove(stringList[i]);
        }
        if(line == check_line){
            *language = "EN";
        }
        else{
            *language = "RUS";
        }
    }
public:
    void Convert(QString *Line){
        QString language;
        converter string;
        QString line = *Line;
        string.CheckForLanguage(line,&language);
        if(language == "EN"){
            string.ConvertEN(&(*Line));
        }
        else{
            string.ConvertRUS(&(*Line));
        }
    }
    void ReverseConvert(QString *Line){
        QString language;
        converter string;
        QString line = *Line;
        string.CheckForLanguage(line,&language);
        if(language == "EN"){
            string.ReverseConvertEN(&(*Line));
        }
        else{
            string.ReverseConvertRUS(&(*Line));
        }
    }
};
void MainWindow::on_pushButton_clicked()
{
    ui->plainTextEdit_2->clear();
    QString line = ui->plainTextEdit->toPlainText();
    converter Line;
    Line.Convert(&line);
    ui->plainTextEdit_2->appendPlainText(line);
}
void MainWindow::on_pushButton_2_clicked()
{
    ui->plainTextEdit->clear();
    QString line = ui->plainTextEdit_2->toPlainText();
    converter Line;
    Line.ReverseConvert(&line);
    qDebug() << line;
    ui->plainTextEdit->appendPlainText(line);
}
