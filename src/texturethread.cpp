#include "texturethread.h"

#include <QFile>
#include <QProcess>
#include <QDir>

#include "utilities.h"

void TextureThread::run()
{
    QDir().mkdir("Cache");

	QProcess process;
    QStringList localInput = input;
    localInput.append("-version");
    localInput.append("7.4");
    process.start("vtfcmd.exe", localInput);

	process.waitForFinished();

	QFile cacheFile( "Cache/" + vtfFile );
	cacheFile.rename( "Cache/" + output + ".png" );
}

