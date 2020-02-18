#include "HideKakaoTalkAd.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HideKakaoTalkAd w;
	w.show();
	return a.exec();
}
