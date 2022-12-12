#include "HideKakaoTalkAd.h"
#include "qmessagebox.h"
#include "Windows.h"

HideKakaoTalkAd::HideKakaoTalkAd(QWidget *parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);
	setFixedSize(345, 225);

	connect(ui.HideAdButton, SIGNAL(clicked()), this, SLOT(HideAdButtonClicked()));
}

HWND KakaoMain, KakaoAd, KakaoChildWnd;
RECT Rect;

void HideKakaoTalkAd::HideAdButtonClicked() {
	KakaoMain = FindWindow(NULL, TEXT("카카오톡"));
	KakaoAd = FindWindowEx(KakaoMain, NULL, L"BannerAdWnd", NULL);
	KakaoChildWnd = FindWindowEx(KakaoMain, NULL, L"EVA_ChildWindow", NULL);

	QMessageBox MsgBox;
	MsgBox.setInformativeText("Hide KakaoTalk Ad!!\n");
	MsgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	MsgBox.setDefaultButton(QMessageBox::Ok);

	if (MsgBox.exec() == QMessageBox::Ok) {
		GetWindowRect(KakaoMain, &Rect);
		SetWindowPos(KakaoAd, NULL, NULL, NULL, NULL, NULL, SWP_NOACTIVATE);
		SetWindowPos(KakaoChildWnd, HWND_BOTTOM, NULL, NULL, (Rect.right - Rect.left - 2), (Rect.bottom - Rect.top - 30), SWP_NOMOVE);

		this->close();
	}
}
