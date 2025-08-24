#include "livestock_management.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    LibraryApp window;
    window.show();
    
    return app.exec();
}
