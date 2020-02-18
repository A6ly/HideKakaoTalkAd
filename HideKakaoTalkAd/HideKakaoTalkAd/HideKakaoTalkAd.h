#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HideKakaoTalkAd.h"

class HideKakaoTalkAd : public QMainWindow
{
	Q_OBJECT

public:
	HideKakaoTalkAd(QWidget *parent = Q_NULLPTR);

private:
	Ui::HideKakaoTalkAdClass ui;

public slots:
	void HideAdButtonClicked();
};
