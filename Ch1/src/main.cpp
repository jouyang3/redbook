#include <QApplication>

#include "firstprogram.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat format;
//    format.setDepthBufferSize( 24 );
    format.setSamples(16);
    format.setVersion(4,1);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setOption(QSurfaceFormat::DebugContext);

    FirstProgram fpw;
    fpw.setFormat(format);
    fpw.resize(640,480);
    fpw.show();

    return a.exec();
}
