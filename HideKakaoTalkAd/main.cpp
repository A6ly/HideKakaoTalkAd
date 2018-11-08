#include <Windows.h>
#include <stdio.h>

int main() {

	HWND KakaoMain, KakaoAd, KakaoChildWnd;
	RECT Rect;

	KakaoMain = FindWindow(NULL, TEXT("카카오톡"));
	KakaoAd = FindWindowEx(KakaoMain, NULL, "EVA_Window", NULL);
	KakaoChildWnd = FindWindowEx(KakaoMain, NULL, "EVA_ChildWindow", NULL);

	GetWindowRect(KakaoMain, &Rect);
	SetWindowPos(KakaoAd, NULL, NULL, NULL, NULL, NULL, SWP_NOACTIVATE);
	SetWindowPos(KakaoChildWnd, HWND_BOTTOM, NULL, NULL, (Rect.right - Rect.left - 2), (Rect.bottom - Rect.top - 33), SWP_NOMOVE);

	printf("Hide KakaoTalk Ad!\n");

	return 0;
}
