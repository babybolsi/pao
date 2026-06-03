#include <QApplication>
#include <QWidget>

#include "View/MainWindow.h"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    View::MainWindow window ;
    window.show();

    return app.exec();
}
